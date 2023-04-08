obj-m += hello.o
num=2
NAME=$(shell uname -r)
all:
	make -C /lib/modules/${NAME}/build M=$(PWD) modules
clean:
	make -C /lib/modules/${NAME}/build M=$(PWD) clean
	
load: hello.ko 
	@sudo insmod hello.ko 
	@sudo dmesg | tail -n ${num}
unload:
	@sudo rmmod hello
	@sudo dmesg | tail -n ${num}
