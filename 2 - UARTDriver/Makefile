# toolchain
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# flags
CFLAGS = -mcpu=cortex-m3 -mthumb -O0 -g -Wall -ffreestanding

# files
SRCS = startup.c main.c uart.c
TARGET  = firmware

all:
	$(CC) $(CFLAGS) -T linker.ld $(SRCS) -o $(TARGET).elf -nostdlib
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

flash:
	st-flash write $(TARGET).bin 0x08000000

clean:
	rm -f $(TARGET).elf $(TARGET).bin