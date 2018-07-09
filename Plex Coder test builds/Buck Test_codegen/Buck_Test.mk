CROSS            ?= "C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/bin/win/arm-none-eabi/bin/arm-none-eabi-"
CFLAGS           := -Wall -O3 -g  -c -fmessage-length=0 -DEXTERNAL_MODE=1 -funsafe-math-optimizations -fopt-info-vec --param max-completely-peeled-insns=1000 --param max-completely-peel-times=100
CC               = $(CROSS)gcc
STRIP            = $(CROSS)strip
INCLUDE          := -I"C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/include"
LIBS             := -L"C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/lib" -L"C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/lib/OpenAmp" -L"C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/lib/Xilinx" -lplexim_hil -lopen_amp -lbaremetal_remote -lm -Wl,--start-group,-lxil,-lgcc,-lc,--end-group
RM               := rm -f
CP               := cp
LFLAGS           := -Wl,-T -Wl,"C:/Users/wede/Documents/GitHub/Plexim_2k18/PLECS_RT_Box/lscript.ld"

APP = Buck_Test.elf

HEADERS += Buck_Test.h
C_SRCFILES += Buck_Test_main.c Buck_Test.c

OBJFILES := $(patsubst %.c, %.o, $(C_SRCFILES))
DEPFILES := $(patsubst %.c, %.d, $(C_SRCFILES))

all: $(APP)

$(APP): $(OBJFILES)
	@echo LINK $@
	$(CC) -o $@ $(LFLAGS) $(OBJFILES) $(LIBS)
	$(STRIP) $@

%.o:%.c $(HEADERS)
	@echo CC $(<:.c=.o)
	$(CC) $(CFLAGS) $(ARCH_CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-$(RM) $(LIB) $(OBJFILES)

FORCE:

PHONY: all clean
