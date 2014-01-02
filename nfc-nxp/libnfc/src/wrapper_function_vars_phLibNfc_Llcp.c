/********************** function call vars: phLibNfc_Llcp **************************/

static NFCSTATUS (*phLibNfc_Llcp_Accept_) (
    phLibNfc_Handle                  hSocket,
    phLibNfc_Llcp_sSocketOptions_t*  psOptions,
    phNfc_sData_t*                   psWorkingBuffer,
    pphLibNfc_LlcpSocketErrCb_t      pErr_Cb,
    pphLibNfc_LlcpSocketAcceptCb_t   pAccept_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Activate_) (
    phLibNfc_Handle                  hRemoteDevice
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Bind_) (
    phLibNfc_Handle                  hSocket,
    uint8_t                          nSap,
    phNfc_sData_t*                   psServiceName
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_CheckLlcp_) (
    phLibNfc_Handle                  hRemoteDevice,
    pphLibNfc_ChkLlcpRspCb_t         pCheckLlcp_RspCb,
    pphLibNfc_LlcpLinkStatusCb_t     pLink_Cb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Close_) (
    phLibNfc_Handle                  hSocket
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Connect_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    uint8_t                          nSap,
    pphLibNfc_LlcpSocketConnectCb_t  pConnect_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_ConnectByUri_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    phNfc_sData_t*                   psUri,
    pphLibNfc_LlcpSocketConnectCb_t  pConnect_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_GetLocalInfo_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Llcp_sLinkParameters_t* pConfigInfo
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_GetRemoteInfo_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Llcp_sLinkParameters_t* pConfigInfo
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Listen_) (
    phLibNfc_Handle                  hSocket,
    pphLibNfc_LlcpSocketListenCb_t   pListen_Cb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Recv_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    phNfc_sData_t*                   psBuffer,
    pphLibNfc_LlcpSocketRecvCb_t     pRecv_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_RecvFrom_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    phNfc_sData_t*                   psBuffer,
    pphLibNfc_LlcpSocketRecvFromCb_t pRecv_Cb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Send_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    phNfc_sData_t*                   psBuffer,
    pphLibNfc_LlcpSocketSendCb_t     pSend_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_SendTo_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    uint8_t                          nSap,
    phNfc_sData_t*                   psBuffer,
    pphLibNfc_LlcpSocketSendCb_t     pSend_RspCb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_Socket_) (
    phLibNfc_Llcp_eSocketType_t      eType,
    phLibNfc_Llcp_sSocketOptions_t*  psOptions,
    phNfc_sData_t*                   psWorkingBuffer,
    phLibNfc_Handle*                 phSocket,
    pphLibNfc_LlcpSocketErrCb_t      pErr_Cb,
    void*                            pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Llcp_SocketGetRemoteOptions_) (
    phLibNfc_Handle                  hRemoteDevice,
    phLibNfc_Handle                  hSocket,
    phLibNfc_Llcp_sSocketOptions_t*  psRemoteOptions
) = NULL;

