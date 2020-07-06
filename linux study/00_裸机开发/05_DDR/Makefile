COMPILE=arm-linux-

objs=$(patsubst %.S,%.o,$(wildcard *.S))
objs+=$(patsubst %.c,%.o,$(wildcard *.c))

dep_files:=$(patsubst %,.%.d,$(objs))
dep_files:=$(wildcard $(dep_files))

CFLAGS=-Iinclude 

p.bin:p.elf
	$(COMPILE)objcopy -O binary -S $^ $@ 

p.elf:$(objs)
	$(COMPILE)ld -Ttext 0 -o $@ $^
	

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o:%.S
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $<

%.o:%.c 
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm *.o *.elf *.bin $(dep_files)

.PHONY:clean
