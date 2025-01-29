#!/bin/bash
export CC_P=/clang/bin
export PATH=${CC_P}:$PATH
export ARCH=arm64
export LLVM=1
export LLVM_IAS=1
export kk="-j$(nproc --all) \
	CROSS_COMPILE=aarch64-linux-gnu- \
	CROSS_COMPILE_COMPAT=arm-linux-gnueabi \
	CC=${CC_P}/clang \
	HOSTCC=${CC_P}/clang \
	HOSTCXX=${CC_P}/clang++ \
	CC=${CC_P}/clang \
	LD=${CC_P}/ld.lld \
	AR=${CC_P}/llvm-ar \
	NM=${CC_P}/llvm-nm \
	OBJCOPY=${CC_P}/llvm-objcopy \
	OBJDUMP=${CC_P}/llvm-objdump \
	READELF=${CC_P}/llvm-readelf \
	STRIP=${CC_P}/llvm-strip"
make ${kk} gki_defconfig O=out
make ${kk} vendor/xiaomi_GKI.config O=out 
make ${kk} O=out

