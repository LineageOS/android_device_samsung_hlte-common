/********************** function call vars: phLibNfc_Ndef **************************/

static NFCSTATUS (*phLibNfc_ConvertToReadOnlyNdef_) (
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t*           pScrtKey,
    pphLibNfc_RspCb_t        pNdefReadOnly_RspCb,
    void*                    pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Ndef_CheckNdef_) (
    phLibNfc_Handle          hRemoteDevice,
    pphLibNfc_ChkNdefRspCb_t pCheckNdef_RspCb,
    void*                    pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Ndef_Read_) (
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t*           psRd,
    phLibNfc_Ndef_EOffset_t  Offset,
    pphLibNfc_RspCb_t        pNdefRead_RspCb,
    void*                    pContext
) = NULL;

static NFCSTATUS (*phLibNfc_Ndef_Write_) (
    phLibNfc_Handle          hRemoteDevice,
    phNfc_sData_t*           psWr,                              
    pphLibNfc_RspCb_t        pNdefWrite_RspCb,
    void*                    pContext
) = NULL;

