all:
	arm-linux-gcc -c -o Start.o Start.S
	arm-linux-gcc -c -o main.o main.c
	arm-linux-ld -Ttext 0 Start.o main.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
clean:
	rm *.bin *.o *.elf
