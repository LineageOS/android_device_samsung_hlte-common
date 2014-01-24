$(call inherit-product, device/samsung/hlte/full_hlte.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/gsm.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=hlte \
    TARGET_DEVICE=hlte \
    BUILD_FINGERPRINT="xxxxxxxxxx" \
    PRIVATE_BUILD_DESC="xxxxxxxxxx"

PRODUCT_DEVICE := hlte
PRODUCT_NAME := cm_hlte
