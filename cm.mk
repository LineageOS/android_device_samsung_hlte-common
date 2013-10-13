$(call inherit-product, device/samsung/hltexx/full_hltexx.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/gsm.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

## todo PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=hltexx TARGET_DEVICE=hltexx BUILD_FINGERPRINT="samsung/hltexx/jflte:4.2.2/JDQ39/I9505XXUAMDE:user/release-keys" PRIVATE_BUILD_DESC="hltexx-user 4.2.2 JDQ39 I9505XXUAMDE release-keys"

PRODUCT_DEVICE := hltexx
PRODUCT_NAME := cm_hltexx

