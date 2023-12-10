.PHONY: all clean

SOURCES = fft_ifft.c
HEADERS = fft_ifft.h
LIBMPREFIX = /usr/lib

all: libfft_ifft.a

clean: 
	rm -f libfft_ifft.a fft_ifft.o fft_ifft_linked.o trig_table.h


libfft_ifft.a: fft_ifft_linked.o
	ar cr libfft_ifft.a fft_ifft_linked.o
 
fft_ifft_linked.o: fft_ifft.o
ifeq ($(TABLE), yes)
		mv fft_ifft.o fft_ifft_linked.o
else
		ld -r -o fft_ifft_linked.o fft_ifft.o $(LIBMPREFIX)/libm.a
endif

fft_ifft.o: $(SOURCES) $(HEADERS)
ifeq ($(TABLE), yes)
ifeq ($(SAMPLES),)
		./tablegenerator.py
		gcc -c -std=c99 -o fft_ifft.o fft_ifft.c 
else
		./tablegenerator.py $(SAMPLES)
		gcc -c -std=c99 -o fft_ifft.o fft_ifft.c
endif
endif
