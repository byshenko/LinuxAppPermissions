obj-m += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

info:
	modinfo main.ko

start: run

run:
	sudo insmod main.ko

show:
	cat /proc/modules

stop:
	sudo rmmod main.ko

log:
	journalctl | grep "\[Antivirus\]"