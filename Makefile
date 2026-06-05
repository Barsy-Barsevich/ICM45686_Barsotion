CC = ${PREFIX}-gcc
AR = ${PREFIX}-ar
OBJDUMP = ${PREFIX}-objdump
SIZE = ${PREFIX}-size

.PHONY: build
build: clean
	@echo '=====< Building ICM45686 library >=============='
	@mkdir build || echo "'build' directory has already created."
	${CC} ${FLAGS} -I./inc -c src/icm45686_barsotion.c -o build/icm45686_barsotion.o
	@echo '=====< Creating an archive >===================='
	${AR} rcs libbarsotion-icm45686.a build/*
	@echo '=====< Totals >================================='
	@${SIZE} -t --format=berkeley libbarsotion-icm45686.a

.PHONY: build-debug
build-debug: clean
	@echo '=====< Building ICM45686 library >=============='
	@mkdir build || echo "INFO: 'build' directory has already created."
	${CC} ${FLAGS} -ffunction-sections -I./inc -c src/icm45686_barsotion.c -o build/icm45686_barsotion.o
	${CC} ${FLAGS} -ffunction-sections -I./inc -c src/icm45686_fielddecode.c -o build/icm45686_fielddecode.o
	@echo '=====< Creating an archive >===================='
	${AR} rcs libicm45686-barsotion-debug.a build/*
	@echo '=====< Totals >================================='
	@${SIZE} -t libicm45686-barsotion-debug.a

clean:
	@rm -r build || echo "INFO: no 'build' directory found."
	@rm *.a || echo "INFO: no archives found."