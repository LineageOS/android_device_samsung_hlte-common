/********************** phLibNfc_Ndef ********************/

NFCSTATUS phLibNfc_ConvertToReadOnlyNdef (
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t*           pScrtKey,
    pphLibNfc_RspCb_t        pNdefReadOnly_RspCb,
    void*                    pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_ConvertToReadOnlyNdef_)(hRemoteDevice,pScrtKey,pNdefReadOnly_RspCb,pContext);
}


NFCSTATUS phLibNfc_Ndef_CheckNdef (
    phLibNfc_Handle          hRemoteDevice,
    pphLibNfc_ChkNdefRspCb_t pCheckNdef_RspCb,
    void*                    pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Ndef_CheckNdef_)(hRemoteDevice,pCheckNdef_RspCb,pContext);
}


NFCSTATUS phLibNfc_Ndef_Read(
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t            *psRd,
    phLibNfc_Ndef_EOffset_t  Offset,
    pphLibNfc_RspCb_t        pNdefRead_RspCb,
    void*                    pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Ndef_Read_)(hRemoteDevice,psRd,Offset,pNdefRead_RspCb,pContext);
}


NFCSTATUS phLibNfc_Ndef_Write(
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t            *psWr,                              
    pphLibNfc_RspCb_t        pNdefWrite_RspCb,
    void*                    pContext
)
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Ndef_Write_)(hRemoteDevice,psWr,pNdefWrite_RspCb,pContext);
}
