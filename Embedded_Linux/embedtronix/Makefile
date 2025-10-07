obj-m += creating_devfile.o

all:
	make ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} -C '${KERNEL_PATH}' M=$(PWD) modules
clean:
	make ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} -C "${KERNEL_PATH}" M=$(PWD) clean
