objs=$(patsubst %.c,%.o,$(wildcard *.c))

dep_files=$(patsubst %,.%.d,$(objs))
dep_files:=$(wildcard $(dep_files))

CFLAGS= -Werror -Iinclude

test:$(objs)
	gcc -o $@ $^
	echo objs=$(objs)
	

ifneq ($(dep_files),)
include $(dep_files)
endif

%.o:%.c 
	gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

echo:	
	echo dep_files=$(dep_files)

clean:
	rm *.o test $(dep_files)

.PHONY:clean
