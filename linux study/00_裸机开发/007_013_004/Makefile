all:
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc -c -o led.o led.c
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc -c -o uart.o uart.c
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc -c -o init.o init.c
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc -c -o main.o main.c
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-gcc -c -o start.o start.S
	#arm-linux-ld -Ttext 0 -Tdata 0x30000000  start.o led.o uart.o init.o main.o -o sdram.elf
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-ld -T sdram.lds start.o led.o uart.o init.o main.o -o sdram.elf
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-objcopy -O binary -S sdram.elf sdram.bin
	/opt/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-objdump -D sdram.elf > sdram.dis
clean:
	rm *.bin *.o *.elf *.dis
	
