/********************** phLibNfc_llcp ********************/


NFCSTATUS phLibNfc_Llcp_Accept( phLibNfc_Handle                  hSocket,
                                phLibNfc_Llcp_sSocketOptions_t*  psOptions,
                                phNfc_sData_t*                   psWorkingBuffer,
                                pphLibNfc_LlcpSocketErrCb_t      pErr_Cb,
                                pphLibNfc_LlcpSocketAcceptCb_t   pAccept_RspCb,
                                void*                            pContext
                                )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Accept_)(hSocket,psOptions,psWorkingBuffer,pErr_Cb,pAccept_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_Activate( phLibNfc_Handle hRemoteDevice )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Activate_)(hRemoteDevice);
}


NFCSTATUS phLibNfc_Llcp_Bind (
    phLibNfc_Handle               hSocket,
    uint8_t                       nSap,
    phNfc_sData_t*                psServiceName
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Bind_)(hSocket,nSap,psServiceName);
}


NFCSTATUS phLibNfc_Llcp_CheckLlcp (
    phLibNfc_Handle               hRemoteDevice,
    pphLibNfc_ChkLlcpRspCb_t      pCheckLlcp_RspCb,
    pphLibNfc_LlcpLinkStatusCb_t  pLink_Cb,
    void*                         pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_CheckLlcp_)(hRemoteDevice,pCheckLlcp_RspCb,pLink_Cb,pContext);
}


NFCSTATUS phLibNfc_Llcp_Close( phLibNfc_Handle hSocket )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Close_)(hSocket);
}


NFCSTATUS phLibNfc_Llcp_Connect( phLibNfc_Handle                 hRemoteDevice,
                                 phLibNfc_Handle                 hSocket,
                                 uint8_t                         nSap,
                                 pphLibNfc_LlcpSocketConnectCb_t pConnect_RspCb,
                                 void*                           pContext
                                 )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Connect_)(hRemoteDevice,hSocket,nSap,pConnect_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_ConnectByUri( phLibNfc_Handle                 hRemoteDevice,
                                      phLibNfc_Handle                 hSocket,
                                      phNfc_sData_t*                  psUri,
                                      pphLibNfc_LlcpSocketConnectCb_t pConnect_RspCb,
                                      void*                           pContext
                                      )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_ConnectByUri_)(hRemoteDevice,hSocket,psUri,pConnect_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_GetLocalInfo( phLibNfc_Handle                  hRemoteDevice,
                                      phLibNfc_Llcp_sLinkParameters_t* pConfigInfo
                                      )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_GetLocalInfo_)(hRemoteDevice,pConfigInfo);
}


NFCSTATUS phLibNfc_Llcp_GetRemoteInfo( phLibNfc_Handle                    hRemoteDevice,
                                       phLibNfc_Llcp_sLinkParameters_t*   pConfigInfo
                                       )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_GetRemoteInfo_)(hRemoteDevice,pConfigInfo);
}


NFCSTATUS phLibNfc_Llcp_Listen( phLibNfc_Handle                  hSocket,
                                pphLibNfc_LlcpSocketListenCb_t   pListen_Cb,
                                void*                            pContext
                                )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Listen_)(hSocket,pListen_Cb,pContext);
}


NFCSTATUS phLibNfc_Llcp_Recv( phLibNfc_Handle              hRemoteDevice,
                              phLibNfc_Handle              hSocket,
                              phNfc_sData_t*               psBuffer,
                              pphLibNfc_LlcpSocketRecvCb_t pRecv_RspCb,
                              void*                        pContext
                              )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Recv_)(hRemoteDevice,hSocket,psBuffer,pRecv_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_RecvFrom( phLibNfc_Handle                   hRemoteDevice,
                                  phLibNfc_Handle                   hSocket,
                                  phNfc_sData_t*                    psBuffer,
                                  pphLibNfc_LlcpSocketRecvFromCb_t  pRecv_Cb,
                                  void*                             pContext
                                  )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_RecvFrom_)(hRemoteDevice,hSocket,psBuffer,pRecv_Cb,pContext);
}


NFCSTATUS phLibNfc_Llcp_Send( phLibNfc_Handle              hRemoteDevice,
                              phLibNfc_Handle              hSocket,
                              phNfc_sData_t*               psBuffer,
                              pphLibNfc_LlcpSocketSendCb_t pSend_RspCb,
                              void*                        pContext
                              )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Send_)(hRemoteDevice,hSocket,psBuffer,pSend_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_SendTo( phLibNfc_Handle               hRemoteDevice,
                                phLibNfc_Handle               hSocket,
                                uint8_t                       nSap,
                                phNfc_sData_t*                psBuffer,
                                pphLibNfc_LlcpSocketSendCb_t  pSend_RspCb,
                                void*                         pContext
                                )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_SendTo_)(hRemoteDevice,hSocket,nSap,psBuffer,pSend_RspCb,pContext);
}


NFCSTATUS phLibNfc_Llcp_Socket( phLibNfc_Llcp_eSocketType_t      eType,
                                phLibNfc_Llcp_sSocketOptions_t*  psOptions,
                                phNfc_sData_t*                   psWorkingBuffer,
                                phLibNfc_Handle*                 phSocket,
                                pphLibNfc_LlcpSocketErrCb_t      pErr_Cb,
                                void*                            pContext
                                )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_Socket_)(eType,psOptions,psWorkingBuffer,phSocket,pErr_Cb,pContext);
}


NFCSTATUS phLibNfc_Llcp_SocketGetRemoteOptions( phLibNfc_Handle                  hRemoteDevice,
                                                phLibNfc_Handle                  hSocket,
                                                phLibNfc_Llcp_sSocketOptions_t*  psRemoteOptions
                                                )
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Llcp_SocketGetRemoteOptions_)(hRemoteDevice,hSocket,psRemoteOptions);
}
