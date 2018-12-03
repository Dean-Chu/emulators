EXE_PREFIX = arm-linux-gnueabihf-
CC        = ${EXE_PREFIX}gcc
STRIP     = ${EXE_PREFIX}strip
LD = $(CC)
SYSROOT     := /home/dean/sunxi-v3s/buildroot-2017.08/output/host/arm-buildroot-linux-gnueabihf/sysroot
SDL_CFLAGS  := $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
SDL_LIBS    := $(shell $(SYSROOT)/usr/bin/sdl-config --libs)
CFLAGS = --sysroot=$(SYSROOT) -O2 $(SDL_CFLAGS) -g -DPC
LDFLAGS = --sysroot=$(SYSROOT) -s
CFLAGS += -mcpu=cortex-a7 -mtune=cortex-a7 -mfloat-abi=hard -mfpu=neon-vfpv4 -ffast-math $(SDL_LIBS)

LAMENES		= lamenes.c lame6502/lame6502.c lame6502/disas.c lame6502/debugger.c lib/str_chrchk.c lib/str_cut.c sdl_functions.c romloader.c ppu.c input.c lib/str_replace.c

all:		$(LAMENES)
		$(CC) $(CFLAGS) $(LAMENES)
		mv a.out lamenes

install:	$(LAMENES)
		cp lamenes /usr/local/bin

uninstall:	$(LAMENES)
		rm /usr/local/bin/lamenes

clean:		$(LAMENES)
		rm -f lamenes lamenes.core core.*
