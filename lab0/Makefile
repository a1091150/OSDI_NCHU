TOOLCHAIN_PREFIX = aarch64-elf-
CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
OBJCPY = $(TOOLCHAIN_PREFIX)objcopy



all:
	$(CC) -c a.S
	$(LD) -T linker.ld -o kernel8.elf a.o
	$(OBJCPY) -O binary kernel8.elf kernel8.img

run: all
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

clean:
	rm kernel8.elf *.o kernel8.img