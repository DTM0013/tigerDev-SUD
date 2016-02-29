CC=g++
CFLAGS= -c -g -I../

LIBS=libs/Entity libs/Database libs/Combat


All: libraries

libraries:
	mkdir libraries/
	for dir in $(LIBS); do \
		cd $$dir; \
		$(CC) $(CFLAGS) *.cpp; \
		mv *.o ../../libraries; \
		cd -; \
	done		 

clean:
	rm -rf libraries/
