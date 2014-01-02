/********************** phLibNfc_RemoteDev ********************/

NFCSTATUS phLibNfc_RemoteDev_CheckPresence (
    phLibNfc_Handle                 hTargetDev,
    pphLibNfc_RspCb_t               pPresenceChk_RspCb,
    void*                           pRspCbCtx
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_CheckPresence_)(hTargetDev,pPresenceChk_RspCb,pRspCbCtx);
}


NFCSTATUS phLibNfc_RemoteDev_Connect (
    phLibNfc_Handle                 hRemoteDevice,
    pphLibNfc_ConnectCallback_t     pNotifyConnect_RspCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_Connect_)(hRemoteDevice,pNotifyConnect_RspCb,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_Disconnect (
    phLibNfc_Handle                 hRemoteDevice,
    phLibNfc_eReleaseType_t         ReleaseType,
    pphLibNfc_DisconnectCallback_t  pDscntCallback,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_Disconnect_)(hRemoteDevice,ReleaseType,pDscntCallback,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_FormatNdef (
    phLibNfc_Handle                 hRemoteDevice,
    phNfc_sData_t*                  pScrtKey,
    pphLibNfc_RspCb_t               pNdefformat_RspCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_FormatNdef_)(hRemoteDevice,pScrtKey,pNdefformat_RspCb,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_NtfRegister (
    phLibNfc_Registry_Info_t*       pRegistryInfo,
    phLibNfc_NtfRegister_RspCb_t    pNotificationHandler,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_NtfRegister_)(pRegistryInfo,pNotificationHandler,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_ReConnect (
    phLibNfc_Handle                 hRemoteDevice,
    pphLibNfc_ConnectCallback_t     pNotifyReConnect_RspCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_ReConnect_)(hRemoteDevice,pNotifyReConnect_RspCb,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_Receive (
    phLibNfc_Handle                 hRemoteDevice,  
    pphLibNfc_Receive_RspCb_t       pReceiveRspCb,  
    void*                           pContext
) 
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_Receive_)(hRemoteDevice,pReceiveRspCb,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_Send (
    phLibNfc_Handle                 hRemoteDevice,  
    phNfc_sData_t*                  pTransferData,  
    pphLibNfc_RspCb_t               pSendRspCb,  
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_Send_)(hRemoteDevice,pTransferData,pSendRspCb,pContext);
}


NFCSTATUS phLibNfc_RemoteDev_Transceive (
    phLibNfc_Handle                 hRemoteDevice,
    phLibNfc_sTransceiveInfo_t*     psTransceiveInfo,
    pphLibNfc_TransceiveCallback_t  pTransceive_RspCb,
    void*                           pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_RemoteDev_Transceive_)(hRemoteDevice,psTransceiveInfo,pTransceive_RspCb,pContext);
}

