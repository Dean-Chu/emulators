# Define compilation type
OSTYPE=msys
#OSTYPE=a320od
#OSTYPE=gcw0od

PRGNAME     = vba
EXESUFFIX = .elf
EXE_PREFIX = arm-linux-gnueabihf-
CC        = ${EXE_PREFIX}gcc
CCP       = ${EXE_PREFIX}g++
LD = $(CCP)

SYSROOT     := /home/dean/sunxi-v3s/buildroot-2017.08/output/host/arm-buildroot-linux-gnueabihf/sysroot
SDL_CFLAGS  := $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
SDL_LIBS    := $(shell $(SYSROOT)/usr/bin/sdl-config --libs)

F_OPTS = -fomit-frame-pointer -ffunction-sections -ffast-math -fsingle-precision-constant -fsigned-char
CC_OPTS = -O2 -DC_CORE -DFINAL_VERSION -DSDL -D_OPENDINGUX_ -D_VIDOD32_ -fpermissive $(F_OPTS)

CFLAGS = --sysroot=$(SYSROOT) $(SDL_CFLAGS) $(CC_OPTS)
LDFLAGS = --sysroot=$(SYSROOT) $(SDL_LIBS) -lz -s
CFLAGS += -mcpu=cortex-a7 -mtune=cortex-a7 -mfloat-abi=hard -mfpu=neon-vfpv4 -ffast-math
CXXFLAGS = $(CFLAGS)

# Files to be compiled
SRCDIR    = ./vba/apu ./vba/common ./vba/gb ./vba/gba ./vba ./opendingux .
VPATH     = $(SRCDIR)
SRC_C   = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP   = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
OBJ_C   = $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP   = $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJS     = $(OBJ_C) $(OBJ_CP)

# Rules to make executable
$(PRGNAME)$(EXESUFFIX): $(OBJS)  
ifeq "$(OSTYPE)" "msys"	
	$(LD) $(CFLAGS) -o $(PRGNAME)$(EXESUFFIX) $^ $(LDFLAGS)
else
	$(LD) $(LDFLAGS) -o $(PRGNAME)$(EXESUFFIX) $^
endif

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_CP) : %.o : %.cpp
	$(CCP) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(PRGNAME)$(EXESUFFIX) *.o
