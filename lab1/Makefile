TOOLCHAIN_PREFIX = aarch64-elf-
CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
OBJCPY = $(TOOLCHAIN_PREFIX)objcopy

SRCS = $(wildcard *.c)
SRCS += $(wildcard include/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all: kernel8.img
	$(info $(SRCS))

start.o: start.S
	$(CC) $(CFLAGS) -c start.S -o start.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel8.img: start.o $(OBJS)
	$(LD) start.o $(OBJS) -T link.ld -o kernel8.elf
	$(OBJCPY) -O binary kernel8.elf kernel8.img

run: all	
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -serial null -serial mon:stdio

asm: all
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

clean:
	rm kernel8.elf *.o kernel8.img