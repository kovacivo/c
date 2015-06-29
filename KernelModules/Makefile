obj−m += hello−1.o

UNAME=`/bin/uname -r`

all: 	
	make -C /lib/modules/`/bin/uname -r`/build M=`pwd` modules
clean:
	make −C /lib/modules/`/bin/uname -r`/build M=`pwd` clean
