#!/system/bin/sh

if [ ! -f /system/etc/boot_fixup ];then
mount -o rw,remount,barrier=1 /system
rm -rf  /vendor/firmware/keymaster
mkdir /vendor/firmware/keymaster
cp /firmware/image/keymaste.b00 /vendor/firmware/keymaster/keymaster.b00
cp /firmware/image/keymaste.b01 /vendor/firmware/keymaster/keymaster.b01
cp /firmware/image/keymaste.b02 /vendor/firmware/keymaster/keymaster.b02
cp /firmware/image/keymaste.b03 /vendor/firmware/keymaster/keymaster.b03
cp /firmware/image/keymaste.mdt /vendor/firmware/keymaster/keymaster.mdt
chmod 0644  /vendor/firmware/keymaster/*

touch /system/etc/boot_fixup

mount -o ro,remount,barrier=1 /system

fi