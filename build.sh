#!/bin/bash
export ARCH=arm64
target=umi_user_defconfig
make ${target}
make savedefconfig
mv defconfig arch/${ARCH}/configs/${target}
make mrproper
sh build1.sh
