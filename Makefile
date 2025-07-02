TARGET = ./build/pi_hex

ifeq ($(OS), Windows_NT)
	TARGET := ./build/pi_hex.exe
endif

$(TARGET): ./pi_hex.c
	$(CC) -o $@ $^ 
