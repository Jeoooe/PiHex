TARGET = ./build/pi_hex.out

ifeq ($(OS), Windows_NT)
	TARGET := ./build/pi_hex.exe
endif

$(TARGET): ./pi_hex.c
	$(CC) -o $@ $^ 
