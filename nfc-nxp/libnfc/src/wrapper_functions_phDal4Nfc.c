/********************** phDal4Nfc ********************/

int phDal4Nfc_msgget (
    key_t   key,
    int     msgflg
)
{
    if (openLibrary()) return -1;
    return (*phDal4Nfc_msgget_)(key,msgflg);
}


int phDal4Nfc_msgrcv (
    int     msqid,
    void*   msgp,
    size_t  msgsz,
    long    msgtyp,
    int     msgflg
)
{
    if (openLibrary()) return -1;
    return (*phDal4Nfc_msgrcv_)(msqid,msgp,msgsz,msgtyp,msgflg);
}


int phDal4Nfc_msgsnd (
    int     msqid,
    void*   msgp,
    size_t  msgsz,
    int     msgflg
)
{
    if (openLibrary()) return -1;
    return (*phDal4Nfc_msgsnd_)(msqid,msgp,msgsz,msgflg);
}

