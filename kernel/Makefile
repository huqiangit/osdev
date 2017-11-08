OBJ_DIR = ./objs/kernel
CUR_DIR = ./kernel

CC = gcc
LD = ld
CFLAGS = -std=c99 -pedantic -Wall -nostdlib -ffreestanding -m32
LDFLAGS = -s -T $(CUR_DIR)/kernel.ld -nostdlib -n -melf_i386

.PHONY: all

all: $(OBJ_DIR)/kernel

$(OBJ_DIR)/kernel: $(OBJ_DIR)/kernel.o $(CUR_DIR)/kernel.ld
	${LD} ${LDFLAGS} -o $(OBJ_DIR)/kernel $(OBJ_DIR)/kernel.o

$(OBJ_DIR)/%.o: $(CUR_DIR)/%.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	rm -f ${OBJ_DIR}/* 

