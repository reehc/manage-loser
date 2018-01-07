#!/bin/sh
echo "Hello, I am backheer."

SRC="/media/blackcheer/DATA/Download_Chrome/Shadowsocks-4.0.4"
DST=/media/blackcheer/Samsung\ USB

SDA=sda3
SDB=sdb
DIR=Download_Chrome/Shadowsocks-4.0.4
# read -p "I am going to mount /dev/$SDA and find $DIR in it, is that right?(y/n) " ANS
read -p "I am going to copy blalala!!!(y/n)  " ANS
[ "$ANS" = "y" -o "$ANS" = "Y"  ] && {
echo "Fine...I am starting!"

cp -r "$SRC" "$DST"

# Well, I don't have to do this...
# sudo mkdir /mnt/temp_$SDA &&
# sudo mkdir /mnt/temp_$SDB &&
# sudo mount -t ntfs /dev/$SDA /mnt/temp_$SDA &&
# sudo mount -t exfat /dev/$SDB /mnt/temp_$SDB &&
# sudo cp -r /mnt/temp$SDA/DIR /mnt/temp_$SDB &&
# sudo umount /dev/$SDA &&
# sudo umount /dev/$SDB &&

echo "Done perfectly!"
}

