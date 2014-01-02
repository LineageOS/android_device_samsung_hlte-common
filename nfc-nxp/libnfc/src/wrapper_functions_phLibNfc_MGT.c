/********************** phLibNfc_MGT ********************/

NFCSTATUS phLibNfc_Mgt_ConfigureDiscovery (
    phLibNfc_eDiscoveryConfigMode_t DiscoveryMode,   
    phLibNfc_sADD_Cfg_t             sADDSetup,
    pphLibNfc_RspCb_t               pConfigDiscovery_RspCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_ConfigureDiscovery_)(DiscoveryMode,sADDSetup,pConfigDiscovery_RspCb,pContext);
}


NFCSTATUS phLibNfc_Mgt_ConfigureDriver (
    pphLibNfc_sConfig_t             psConfig,
    void**                          ppDriverHandle
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_ConfigureDriver_)(psConfig,ppDriverHandle);
}


NFCSTATUS phLibNfc_Mgt_DeInitialize (
    void*                           pDriverHandle,
    pphLibNfc_RspCb_t               pDeInitCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_DeInitialize_)(pDriverHandle,pDeInitCb,pContext);
}


NFCSTATUS phLibNfc_Mgt_GetstackCapabilities(
    phLibNfc_StackCapabilities_t*   phLibNfc_StackCapabilities,
    void *                          pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_GetstackCapabilities_)(phLibNfc_StackCapabilities,pContext);
}


NFCSTATUS phLibNfc_Mgt_Initialize (
    void                            *pDriverHandle,
    pphLibNfc_RspCb_t               pInitCb,
    void                            *pContext)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_Initialize_)(pDriverHandle,pInitCb,pContext);
}


NFCSTATUS phLibNfc_Mgt_IoCtl (
    void*                           pDalHandle,
    uint16_t                        IoctlCode,        
    phNfc_sData_t*                  pInParam,
    phNfc_sData_t*                  pOutParam,
    pphLibNfc_IoctlCallback_t       pIoCtl_Rsp_cb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_IoCtl_)(pDalHandle,IoctlCode,pInParam,pOutParam,pIoCtl_Rsp_cb,pContext);
}


void phLibNfc_Mgt_Recovery ()
{
    if (!openLibrary()) (*phLibNfc_Mgt_Recovery_)();
}


NFCSTATUS phLibNfc_Mgt_SetLlcp_ConfigParams (
    phLibNfc_Llcp_sLinkParameters_t* pConfigInfo,
    pphLibNfc_RspCb_t                pConfigRspCb,
    void*                            pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_SetLlcp_ConfigParams_)(pConfigInfo,pConfigRspCb,pContext);
}


NFCSTATUS phLibNfc_Mgt_UnConfigureDriver (
    void *                          pDriverHandle
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Mgt_UnConfigureDriver_)(pDriverHandle);
}

