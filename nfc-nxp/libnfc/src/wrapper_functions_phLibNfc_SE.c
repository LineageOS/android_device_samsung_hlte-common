/********************** phLibNfc_SE ********************/

NFCSTATUS phLibNfc_SE_GetSecureElementList (
    phLibNfc_SE_List_t*            pSE_List,
    uint8_t*                       uSE_count
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_SE_GetSecureElementList_)(pSE_List,uSE_count);
}


NFCSTATUS phLibNfc_SE_NtfRegister (
    pphLibNfc_SE_NotificationCb_t  pSE_NotificationCb,
    void*                          pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_SE_NtfRegister_)(pSE_NotificationCb,pContext);
}


NFCSTATUS phLibNfc_SE_SetMode (
    phLibNfc_Handle                hSE_Handle, 
    phLibNfc_eSE_ActivationMode    eActivation_mode,
    pphLibNfc_SE_SetModeRspCb_t    pSE_SetMode_Rsp_cb,
    void*                          pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_SE_SetMode_)(hSE_Handle,eActivation_mode,pSE_SetMode_Rsp_cb,pContext);
}

