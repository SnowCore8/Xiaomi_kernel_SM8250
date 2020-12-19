#!/bin/bash
export ARCH=arm64
target=umi_user_defconfig
make ${target}
cp .config arch/${ARCH}/configs/${target}
make mrproper
