#!/system/bin/sh
# Copyright (C) 2012 The Android Open Source Project
# Copyright (C) 2013-2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Allows customization for various hlte variants.
#


CMDLINE=`cat /proc/cmdline`
if [[ $CMDLINE != "${CMDLINE/SM-N900P}" ]]; #hltespr
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltespr/hltespr:4.3/JSS15J/N900PVPUBMJ4:user/release-keys|g' /system/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|ro.build.description=hltespr-user 4.3 JSS15J N900PVPUBMJ4 release-keys|g' /system/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900P|g' /system/build.prop
       sed -i 's|ro.product.device=hlte|ro.product.device=hltespr|g' /system/build.prop
        echo "ro.telephony.ril.v3=newDriverCallU,newDialCode" >> /system/build.prop
       cp -R /system/lib/cdma/* /system/lib
elif [[ $CMDLINE != "${CMDLINE/SM-N9005}" ]]; #hltexx
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltexx/hlte:4.3/JSS15J/N9005XXUBMH1:user/release-keys|g' /system/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|ro.build.description=hltexx-user 4.3 JSS15J N9005XXUBMH1 release-keys|g' /system/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N9005|g' /system/build.prop
        echo "ro.telephony.ril.v3=newDialCode" >> /system/build.prop
       cp -R /system/lib/gsm/* /system/lib
elif [[ $CMDLINE != "${CMDLINE/SM-N900T}" ]]; #hltetmo
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltetmo/hltetmo:4.3/JSS15J/N900TUVUBMI7:user/release-keys|g' /system/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|hltetmo-user 4.3 JSS15J N900TUVUBMI7 release-keys|g' /system/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900T|g' /system/build.prop
       sed -i 's|ro.product.device=hlte|ro.product.device=hltetmo|g' /system/build.prop
        echo "ro.telephony.ril.v3=newDialCode" >> /system/build.prop
       cp -R /system/lib/gsm/* /system/lib
elif [[ $CMDLINE != "${CMDLINE/SM-N900W8}" ]]; #hltexx
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=samsung/hltevl/hltecan:4.3/JSS15J/N900W8VLUBMJ4:user/release-keys|g' /system/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|ro.build.description="hltevl-user 4.3 JSS15J N900W8VLUBMJ4 release-keys|g' /system/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900W8|g' /system/build.prop
        sed -i 's|ro.product.device=hlte|ro.product.device=hltecan|g' /system/build.prop
        echo "ro.telephony.ril.v3=newDialCode" >> /system/build.prop
        cp -R /system/lib/gsm/* /system/lib
elif [[ $CMDLINE != "${CMDLINE/SM-N900V}" ]]; #hltexx
    then
       sed -i 's|ro.build.fingerprint=xxxxxxxxxx|ro.build.fingerprint=Verizon/hltevzw/hltevzw:4.3/JSS15J/N900VOYUBMJ3:user/release-keys|g' /system/build.prop
       sed -i 's|ro.build.description=xxxxxxxxxx|ro.build.description=hltevzw-user 4.3 JSS15J N900VOYUBMJ3 release-keys|g' /system/build.prop
       sed -i 's|ro.product.model=hlte|ro.product.model=SM-N900W8|g' /system/build.prop
        sed -i 's|ro.product.device=hlte|ro.product.device=hltevzw|g' /system/build.prop
        echo "ro.telephony.ril.v3=newDriverCallU,newDialCode" >> /system/build.prop
        cp -R /system/lib/cdma/* /system/lib
fi
chmod 644 /system/build.prop
