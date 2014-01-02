/********************** function call vars: phDal4Nfc **************************/

static int (*phDal4Nfc_msgget_) (
    key_t   key,
    int     msgflg
) = NULL;

static int (*phDal4Nfc_msgrcv_) (
    int     msqid,
    void*   msgp,
    size_t  msgsz,
    long    msgtyp,
    int     msgflg
) = NULL;

static int (*phDal4Nfc_msgsnd_) (
    int     msqid,
    void*   msgp,
    size_t  msgsz,
    int     msgflg
) = NULL;

