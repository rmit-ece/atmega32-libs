CC		:= avr-gcc
CFLAGS		:= -Wall -Wextra -pedantic -Os -mmcu=atmega32 -nostartfiles -nostdlib
SOURCES		:= $(wildcard *.c)
OBJS 		:= $(patsubst %.c, %.o, $(wildcard *.c))
TARGET		:= prog.bin
IHEX_TARG	:= prog.hex

all: $(OBJS)
	#avr-gcc -mmcu=atmega32 -nostartfiles -nostdlib -Wl,--relax -o $(TARGET) $(OBJS)
	#avr-objcopy -j .text -j .data -O ihex prog.bin prog.hex

	# Uncomment this if you want to flash this (including main) into a project
	# You'll need to remove -nostartfiles and -nostdlib though!
	#avrdude -c usbasp -p m32 -U flash:w:prog.hex

	avr-ar rcs spi.a *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.hex
	rm -f *.a
