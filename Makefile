obj-m += main.o

# multiple files ( target is as it is, not a reference to an actual target )
# obj-m += target.o 
# target-objs := main.o test.o

num=2
NAME=$(shell uname -r)
all:
	make -C /lib/modules/${NAME}/build M=$(PWD) modules
clean:
	make -C /lib/modules/${NAME}/build M=$(PWD) clean

run:subrun unload  

subrun:load 
	sleep 1
	
load: main.ko 
	@sudo insmod main.ko 
	@sudo dmesg | tail -n ${num}

unload:
	@sudo rmmod main.ko
	@sudo dmesg | tail -n ${num}
