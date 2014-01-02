/*
 * Copyright (C) 2010 NXP Semiconductors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "HLTE NFC-NXP"

#define DEBUG_NXP

#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <cutils/log.h>

#include <phNfcStatus.h>
#include <phNfcConfig.h>
#include <phLibNfc.h>

#define LIB_PATH                "/system/lib/libnf1.so"

#define NFCSTATUS_LIB_ERROR NFCSTATUS_INSUFFICIENT_RESOURCES

/********************** Global variables ****************************/

int libnfc_llc_error_count = 0;
static void *libhandle = NULL;

#include "wrapper_function_vars_phLibNfc.c"
#include "wrapper_function_vars_phLibNfc_Llcp.c"
#include "wrapper_function_vars_phLibNfc_MGT.c"
#include "wrapper_function_vars_phLibNfc_Ndef.c"
#include "wrapper_function_vars_phLibNfc_RemoteDev.c"
#include "wrapper_function_vars_phLibNfc_SE.c"
#include "wrapper_function_vars_phDal4Nfc.c"

/********************** utility functions **************************/

void openSymbol(void **functPtr, const char *functName) {
    if (*functPtr == NULL) {
        *functPtr = dlsym(libhandle, functName);
        if (*functPtr == NULL) {
            const char *err_str = dlerror();
            ALOGE("Error (%s) while opening the libnfc library fuction: %s", err_str ? err_str : "unknown", functName);
        }
#ifdef DEBUG_NXP
        else {
            ALOGI("Opened the libnfc library fuction: %s", functName);
        }
#endif
    }
}

int openLibrary() {
    if (libhandle == NULL) {
        const char *err_str;
        libhandle = dlopen(LIB_PATH, RTLD_NOW);
        if (libhandle == NULL) {
            err_str = dlerror();
            ALOGE("Error (%s) while opening the libnfc library", err_str ? err_str : "unknown");
            return -1;
        }
#ifdef DEBUG_NXP
        else {
            ALOGI("Opend the libnfc library: %s", LIB_PATH);
        }
#endif

	openSymbol((void**)&phLibNfc_Download_Mode_,               "phLibNfc_Download_Mode");
	openSymbol((void**)&phLibNfc_HW_Reset_,                    "phLibNfc_HW_Reset");
	openSymbol((void**)&phLibNfc_Load_Firmware_Image_,         "phLibNfc_Load_Firmware_Image");

	openSymbol((void**)&phLibNfc_Llcp_Accept_,                 "phLibNfc_Llcp_Accept");
	openSymbol((void**)&phLibNfc_Llcp_Activate_,               "phLibNfc_Llcp_Activate");
	openSymbol((void**)&phLibNfc_Llcp_Bind_,                   "phLibNfc_Llcp_Bind");
	openSymbol((void**)&phLibNfc_Llcp_CheckLlcp_,              "phLibNfc_Llcp_CheckLlcp");
	openSymbol((void**)&phLibNfc_Llcp_Close_,                  "phLibNfc_Llcp_Close");
	openSymbol((void**)&phLibNfc_Llcp_Connect_,                "phLibNfc_Llcp_Connect");
	openSymbol((void**)&phLibNfc_Llcp_ConnectByUri_,           "phLibNfc_Llcp_ConnectByUri");
	openSymbol((void**)&phLibNfc_Llcp_GetLocalInfo_,           "phLibNfc_Llcp_GetLocalInfo");
	openSymbol((void**)&phLibNfc_Llcp_GetRemoteInfo_,          "phLibNfc_Llcp_GetRemoteInfo");
	openSymbol((void**)&phLibNfc_Llcp_Listen_,                 "phLibNfc_Llcp_Listen");
	openSymbol((void**)&phLibNfc_Llcp_RecvFrom_,               "phLibNfc_Llcp_RecvFrom");
	openSymbol((void**)&phLibNfc_Llcp_Recv_,                   "phLibNfc_Llcp_Recv");
	openSymbol((void**)&phLibNfc_Llcp_Send_,                   "phLibNfc_Llcp_Send");
	openSymbol((void**)&phLibNfc_Llcp_SendTo_,                 "phLibNfc_Llcp_SendTo");
	openSymbol((void**)&phLibNfc_Llcp_Socket_,                 "phLibNfc_Llcp_Socket");
	openSymbol((void**)&phLibNfc_Llcp_SocketGetRemoteOptions_, "phLibNfc_Llcp_SocketGetRemoteOptions");

	openSymbol((void**)&phLibNfc_Mgt_ConfigureDiscovery_,      "phLibNfc_Mgt_ConfigureDiscovery");
	openSymbol((void**)&phLibNfc_Mgt_ConfigureDriver_,         "phLibNfc_Mgt_ConfigureDriver");
	openSymbol((void**)&phLibNfc_Mgt_DeInitialize_,            "phLibNfc_Mgt_DeInitialize");
	openSymbol((void**)&phLibNfc_Mgt_GetstackCapabilities_,    "phLibNfc_Mgt_GetstackCapabilities");
	openSymbol((void**)&phLibNfc_Mgt_Initialize_,              "phLibNfc_Mgt_Initialize");
	openSymbol((void**)&phLibNfc_Mgt_IoCtl_,                   "phLibNfc_Mgt_IoCtl");
	openSymbol((void**)&phLibNfc_Mgt_Recovery_,                "phLibNfc_Mgt_Recovery");
	openSymbol((void**)&phLibNfc_Mgt_SetLlcp_ConfigParams_,    "phLibNfc_Mgt_SetLlcp_ConfigParams");
	openSymbol((void**)&phLibNfc_Mgt_UnConfigureDriver_,       "phLibNfc_Mgt_UnConfigureDriver");

	openSymbol((void**)&phLibNfc_ConvertToReadOnlyNdef_,       "phLibNfc_ConvertToReadOnlyNdef");
	openSymbol((void**)&phLibNfc_Ndef_CheckNdef_,              "phLibNfc_Ndef_CheckNdef");
	openSymbol((void**)&phLibNfc_Ndef_Read_,                   "phLibNfc_Ndef_Read");
	openSymbol((void**)&phLibNfc_Ndef_Write_,                  "phLibNfc_Ndef_Write");

	openSymbol((void**)&phLibNfc_RemoteDev_CheckPresence_,     "phLibNfc_RemoteDev_CheckPresence");
	openSymbol((void**)&phLibNfc_RemoteDev_Connect_,           "phLibNfc_RemoteDev_Connect");
	openSymbol((void**)&phLibNfc_RemoteDev_Disconnect_,        "phLibNfc_RemoteDev_Disconnect");
	openSymbol((void**)&phLibNfc_RemoteDev_FormatNdef_,        "phLibNfc_RemoteDev_FormatNdef");
	openSymbol((void**)&phLibNfc_RemoteDev_NtfRegister_,       "phLibNfc_RemoteDev_NtfRegister");
	openSymbol((void**)&phLibNfc_RemoteDev_ReConnect_,         "phLibNfc_RemoteDev_ReConnect");
	openSymbol((void**)&phLibNfc_RemoteDev_Receive_,           "phLibNfc_RemoteDev_Receive");
	openSymbol((void**)&phLibNfc_RemoteDev_Send_,              "phLibNfc_RemoteDev_Send");
	openSymbol((void**)&phLibNfc_RemoteDev_Transceive_,        "phLibNfc_RemoteDev_Transceive");

	openSymbol((void**)&phLibNfc_SE_GetSecureElementList_,     "phLibNfc_SE_GetSecureElementList");
	openSymbol((void**)&phLibNfc_SE_NtfRegister_,              "phLibNfc_SE_NtfRegister");
	openSymbol((void**)&phLibNfc_SE_SetMode_,                  "phLibNfc_SE_SetMode");

	openSymbol((void**)&phDal4Nfc_msgget_,                     "phDal4Nfc_msgget");
	openSymbol((void**)&phDal4Nfc_msgrcv_,                     "phDal4Nfc_msgrcv");
	openSymbol((void**)&phDal4Nfc_msgsnd_,                     "phDal4Nfc_msgsnd");
    }
    return 0;
}

#include "wrapper_functions_phLibNfc.c"
#include "wrapper_functions_phLibNfc_Llcp.c"
#include "wrapper_functions_phLibNfc_MGT.c"
#include "wrapper_functions_phLibNfc_Ndef.c"
#include "wrapper_functions_phLibNfc_RemoteDev.c"
#include "wrapper_functions_phLibNfc_SE.c"
#include "wrapper_functions_phDal4Nfc.c"

/********************** NEW functions ********************/

NFCSTATUS phLibNfc_SetIsoXchgTimeout(uint8_t timeout) {
    return NFCSTATUS_SUCCESS;
}

int phLibNfc_GetIsoXchgTimeout() {
    return NXP_ISO_XCHG_TIMEOUT;
}

NFCSTATUS phLibNfc_SetHciTimeout(uint32_t timeout_in_ms) {
    return NFCSTATUS_SUCCESS;
}

int phLibNfc_GetHciTimeout() {
    return NXP_NFC_HCI_TIMEOUT;
}

NFCSTATUS phLibNfc_SetFelicaTimeout(uint8_t timeout_in_ms) {
    return NFCSTATUS_SUCCESS;
}

int phLibNfc_GetFelicaTimeout() {
    return NXP_FELICA_XCHG_TIMEOUT;
}

NFCSTATUS phLibNfc_SetMifareRawTimeout(uint8_t timeout) {
    return NFCSTATUS_SUCCESS;
}

int phLibNfc_GetMifareRawTimeout() {
    return NXP_MIFARE_XCHG_TIMEOUT;
}

