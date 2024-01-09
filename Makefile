.PHONY: all clean

SOURCES = fft_ifft.c
HEADERS = fft_ifft.h

all: libfft_ifft.a

clean: 
	rm -f libfft_ifft.a fft_ifft.o trig_table.h


libfft_ifft.a: fft_ifft.o
	ar cr libfft_ifft.a fft_ifft.o
 

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
