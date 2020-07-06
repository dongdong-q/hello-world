COMPILE=arm-linux-

objs=$(patsubst %.S,%.o,$(wildcard *.S))
objs+=$(patsubst %.c,%.o,$(wildcard *.c))

dep_files:=$(patsubst %,.%.d,$(objs))
dep_files:=$(wildcard $(dep_files))

CFLAGS=-Iinclude 

p.bin:p.elf
	$(COMPILE)objcopy -O binary -S $^ $@ 

p.elf:$(objs)
	$(COMPILE)ld -T p.lds -o $@ $^
	

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o:%.S
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $<

%.o:%.c 
	$(COMPILE)gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

dump:
	$(COMPILE)objdump -D p.elf >p.dis

clean:
	rm *.o *.elf *.bin $(dep_files) *.dis

.PHONY:clean
.PHONY:dump
