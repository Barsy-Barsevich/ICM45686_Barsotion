CC = ${PREFIX}-gcc
AR = ${PREFIX}-ar
OBJDUMP = ${PREFIX}-objdump
SIZE = ${PREFIX}-size

build-debug:
	@echo '=====< Building ICM45686 library >=============='
	@mkdir build || echo "INFO: 'build' directory has already created."
	${CC} ${FLAGS} -I./inc -c src/icm45686_barsotion.c -o build/icm45686_barsotion.o
	${CC} ${FLAGS} -I./inc -c src/icm45686_fielddecode.c -o build/icm45686_fielddecode.o
	@echo '=====< Creating an archive >===================='
	${AR} rcs libicm45686-barsotion-debug.a build/*
	@echo '=====< Totals >================================='
	@${SIZE} -t --format=gnu libicm45686-barsotion-debug.a

build:
	@echo '=====< Building ICM45686 library >=============='
	@mkdir build || echo "'build' directory has already created."
	${CC} ${FLAGS} -I./inc -c src/icm45686_barsotion.c -o build/icm45686_barsotion.o
	@echo '=====< Creating an archive >===================='
	${AR} rcs libicm45686-barsotion.a build/*
	@echo '=====< Totals >================================='
	@${SIZE} -t --format=gnu libicm45686-barsotion.a

clean:
	@rm -r build || echo "INFO: no 'build' directory found."
	@rm *.a || echo "INFO: no archives found."