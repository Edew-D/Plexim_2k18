CROSS            ?= "C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/bin/win/arm-none-eabi/bin/arm-none-eabi-"
CFLAGS           := -Wall -O3 -g  -c -fmessage-length=0 -DEXTERNAL_MODE=1 -funsafe-math-optimizations -fopt-info-vec --param max-completely-peeled-insns=1000 --param max-completely-peel-times=100
CC               = $(CROSS)gcc
STRIP            = $(CROSS)strip
INCLUDE          := -I"C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/include"
LIBS             := -L"C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/lib" -L"C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/lib/OpenAmp" -L"C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/lib/Xilinx" -lplexim_hil -lopen_amp -lbaremetal_remote -lm -Wl,--start-group,-lxil,-lgcc,-lc,--end-group
RM               := rm -f
CP               := copy
LFLAGS           := -Wl,-T -Wl,"C:/Users/August/Documents/PlecsTSP/PLECS_RT_Box/lscript.ld"

APP = H_Bridge_and_Inductive_Load.elf

HEADERS += H_Bridge_and_Inductive_Load.h
C_SRCFILES += H_Bridge_and_Inductive_Load_main.c H_Bridge_and_Inductive_Load.c

OBJFILES := $(patsubst %.c, %.o, $(C_SRCFILES))
DEPFILES := $(patsubst %.c, %.d, $(C_SRCFILES))

all: $(APP)

$(APP): $(OBJFILES)
	$(CC) -o $@ $(LFLAGS) $(OBJFILES) $(LIBS)
	$(STRIP) $@

	
%.o:%.c $(HEADERS)
	@echo $(CC) $(<:.c=.o)
	$(CC) $(CFLAGS) $(ARCH_CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-$(RM) $(LIB) $(OBJFILES)

FORCE:

PHONY: all clean
