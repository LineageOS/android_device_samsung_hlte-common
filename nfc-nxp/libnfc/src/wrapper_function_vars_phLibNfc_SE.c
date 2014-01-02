/********************** function call vars: phLibNfc_SE **************************/

static NFCSTATUS (*phLibNfc_SE_GetSecureElementList_) (
    phLibNfc_SE_List_t*            pSE_List,
    uint8_t*                       uSE_count
) = NULL;

static NFCSTATUS (*phLibNfc_SE_NtfRegister_) (
    pphLibNfc_SE_NotificationCb_t  pSE_NotificationCb,
    void                           *pContext
) = NULL;

static NFCSTATUS (*phLibNfc_SE_SetMode_) (
    phLibNfc_Handle                hSE_Handle, 
    phLibNfc_eSE_ActivationMode    eActivation_mode,
    pphLibNfc_SE_SetModeRspCb_t    pSE_SetMode_Rsp_cb,
    void *                         pContext
) = NULL;

