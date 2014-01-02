/********************** function call vars: phLibNfc_MGT **************************/

static NFCSTATUS (*phLibNfc_Mgt_ConfigureDiscovery_) (
    phLibNfc_eDiscoveryConfigMode_t DiscoveryMode,   
    phLibNfc_sADD_Cfg_t             sADDSetup,
    pphLibNfc_RspCb_t               pConfigDiscovery_RspCb,
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_ConfigureDriver_) (
    pphLibNfc_sConfig_t             psConfig,
    void **                         ppDriverHandle
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_DeInitialize_) (
    void *                          pDriverHandle,
    pphLibNfc_RspCb_t               pDeInitCb,
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_GetstackCapabilities_) (
    phLibNfc_StackCapabilities_t*   phLibNfc_StackCapabilities,
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_Initialize_) (
    void                            *pDriverHandle,
    pphLibNfc_RspCb_t               pInitCb,
    void                            *pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_IoCtl_) (
    void*                           pDalHandle,
    uint16_t                        IoctlCode,        
    phNfc_sData_t*                  pInParam,
    phNfc_sData_t*                  pOutParam,
    pphLibNfc_IoctlCallback_t       pIoCtl_Rsp_cb,
    void*                           pContext
) = NULL;

static void (*phLibNfc_Mgt_Recovery_) () = NULL;

static NFCSTATUS (*phLibNfc_Mgt_SetLlcp_ConfigParams_) (
    phLibNfc_Llcp_sLinkParameters_t* pConfigInfo,
    pphLibNfc_RspCb_t               pConfigRspCb,
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Mgt_UnConfigureDriver_) (
    void *                          pDriverHandle
) = NULL;

