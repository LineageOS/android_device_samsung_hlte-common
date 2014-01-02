/********************** phLibNfc ********************/

NFCSTATUS phLibNfc_Download_Mode ()
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_Download_Mode_)();
}


NFCSTATUS phLibNfc_HW_Reset ()
{
    if (openLibrary()) return NFCSTATUS_LIB_ERROR;
    return (*phLibNfc_HW_Reset_)();
}


int phLibNfc_Load_Firmware_Image ()
{
    if (openLibrary()) return -1;
    return (*phLibNfc_Load_Firmware_Image_)();
}
