/********************** function call vars: phLibNfc **************************/

static NFCSTATUS (*phLibNfc_RemoteDev_CheckPresence_) (
    phLibNfc_Handle                hTargetDev,
    pphLibNfc_RspCb_t              pPresenceChk_RspCb,
    void*                          pRspCbCtx
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_Connect_) (
    phLibNfc_Handle                hRemoteDevice,
    pphLibNfc_ConnectCallback_t    pNotifyConnect_RspCb,
    void*                          pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_Disconnect_) (
    phLibNfc_Handle                hRemoteDevice,
    phLibNfc_eReleaseType_t        ReleaseType,
    pphLibNfc_DisconnectCallback_t pDscntCallback,
    void*                          pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_FormatNdef_) (
    phLibNfc_Handle                hRemoteDevice,
    phNfc_sData_t*                 pScrtKey,
    pphLibNfc_RspCb_t              pNdefformat_RspCb,
    void*                          pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_NtfRegister_) (
    phLibNfc_Registry_Info_t*      pRegistryInfo,
    phLibNfc_NtfRegister_RspCb_t   pNotificationHandler,
    void*                          pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_ReConnect_) (
    phLibNfc_Handle                 hRemoteDevice,
    pphLibNfc_ConnectCallback_t     pNotifyReConnect_RspCb,
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_Receive_) (
    phLibNfc_Handle                 hRemoteDevice,  
    pphLibNfc_Receive_RspCb_t       pReceiveRspCb,  
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_Send_) (
    phLibNfc_Handle                 hRemoteDevice,  
    phNfc_sData_t*                  pTransferData,  
    pphLibNfc_RspCb_t               pSendRspCb,  
    void*                           pContext
) = NULL;

static NFCSTATUS (*phLibNfc_RemoteDev_Transceive_) (
    phLibNfc_Handle                 hRemoteDevice,
    phLibNfc_sTransceiveInfo_t*     psTransceiveInfo,
    pphLibNfc_TransceiveCallback_t  pTransceive_RspCb,
    void*                           pContext
) = NULL;

