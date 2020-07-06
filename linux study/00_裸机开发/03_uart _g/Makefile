COMPILE=arm-linux-

objs=$(patsubst %.S,%.o,$(wildcard *.S))
objs+=$(patsubst %.c,%.o,$(wildcard *.c))

CFLAGS=-Iinclude 

uart.bin:uart.elf
	$(COMPILE)objcopy -O binary -S $^ $@ 

uart.elf:$(objs)
	$(COMPILE)ld -Ttext 0 -o $@ $^
	

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o:%.S
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $<

%.o:%.c 
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $<

clean:
	rm *.o *.elf *.bin

.PHONY:clean
