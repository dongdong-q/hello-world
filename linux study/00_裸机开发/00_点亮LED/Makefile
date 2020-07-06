all:
	arm-linux-gcc -c -o led_on_stu.o led_on_stu.S
	arm-linux-ld -Ttext 0 -o led_on_stu.elf led_on_stu.o
	arm-linux-objcopy -O binary -S led_on_stu.elf led_on_stu.bin
clean:
	rm *.bin *.o *.elf
