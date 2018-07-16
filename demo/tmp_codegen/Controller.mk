#   Copyright (c) 2014-2016 by Plexim GmbH
#   All rights reserved.
#
#   A free license is granted to anyone to use this software for any legal
#   non safety-critical purpose, including commercial applications, provided
#   that:
#   1) IT IS NOT USED TO DIRECTLY OR INDIRECTLY COMPETE WITH PLEXIM, and
#   2) THIS COPYRIGHT NOTICE IS PRESERVED in its entirety.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
#   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.


include gensrcs.mk

TARGET_ROOT=C:/Users/August/Documents/PlecsTSP/TI_F2806x
PIL_PREP_PATH=C:/Users/August/Documents/PlecsTSP/TI_F2806x/bin/win/pil
TOOLS_PATH=C:/Users/August/Documents/PlecsTSP/TI_F2806x/bin/win/c2000
OUT_NAME=Controller
MAKEFILE=Controller.mk
LINKFILE=Controller.lkf

##############################################################

ifeq ($(OS),Windows_NT)
# Windows
ClearDir=del /F /Q $(1)\*.*
MoveFile=move /Y $(subst /,\,$(1)) $(subst /,\,$(2))
FixPath=$(subst /,\,$(1))

C2PROG_TARGET="28069,67,66_JTAG"
C2PROG_REG=$(shell reg query "HKLM\SOFTWARE\WOW6432Node\Codeskin\C2Prog" /v InstallPath)
ifeq ($(word 2, $(C2PROG_REG)), InstallPath)
C2PROGROOT=$(wordlist 4, $(words $(C2PROG_REG)), $(C2PROG_REG))
endif

else
# Linux style
FixPath = $(1)
ClearDir=rm -Rf $(1)/*
MoveFile=mv $(1) $(2)
endif 

EXE_PATH=$(TOOLS_PATH)/BIN
LIB_PATH=$(TOOLS_PATH)/LIB
INC_PATH=$(TOOLS_PATH)/INCLUDE

BIN_DIR=./output
BIN_DIR_OS=$(call FixPath,$(BIN_DIR))

# compiler / assembler
C_OPTIONS=\
-DPLECS_CODER\
-fr$(BIN_DIR)\
-fs$(BIN_DIR)\
-v28 \
-ml \
-mt \
--float_support=fpu32 \
-O0 \
--include_path="./" \
--include_path="$(TARGET_ROOT)/app" \
--include_path="$(TARGET_ROOT)/pil" \
--include_path="$(TARGET_ROOT)/tiinc" \
--include_path="$(TARGET_ROOT)/inc" \
--include_path="$(TARGET_ROOT)/inc_impl" \
--include_path="$(TOOLS_PATH)/include" \
-g \
--gcc \
--diag_warning=225

L_OPTIONS=$(LINKFILE)

HFILES=\
	settings_cg.h

NON_PIL_OBJFILES=\
	$(BIN_DIR)/F2806x_usDelay.obj \
	$(BIN_DIR)/F2806x_GlobalVariableDefs.obj \
	$(BIN_DIR)/F2806x_DevInit.obj \
	$(BIN_DIR)/F2806x_CodeStartBranch.obj

PIL_OBJFILES=\
	$(BIN_DIR)/pwm_2806x.obj \
	$(BIN_DIR)/ain_2806x.obj \
	$(BIN_DIR)/dio_2806x.obj \
	$(BIN_DIR)/qep_2806x.obj \
	$(BIN_DIR)/dispatcher_2806x.obj \
	$(BIN_DIR)/gatedriver_rtbox.obj \
	$(BIN_DIR)/power.obj \
	$(BIN_DIR)/hal_2806x.obj \
	$(BIN_DIR)/pu.obj \
	$(BIN_DIR)/calib.obj \
	$(BIN_DIR)/pil_symbols_p.obj \
	$(BIN_DIR)/pil_symbols_c.obj \
	$(BIN_DIR)/pil_ctrl.obj \
	$(BIN_DIR)/main.obj \
	$(BIN_DIR)/sci.obj \
	$(patsubst %.c, $(BIN_DIR)/%.obj, $(SOURCE_FILES))

OBJFILES=$(NON_PIL_OBJFILES) $(PIL_OBJFILES)
	
PPFILES=$(patsubst %.obj, %.pilpp, $(PIL_OBJFILES))

ifneq ($(and $(C2PROGROOT),$(C2PROG_TARGET)),)
HEX_EXTENSION=ehx
else
HEX_EXTENSION=hex
endif

# make all variables available to sub-makes
export

# Pre-compile 
##########################################################################						
all:
ifneq ($(wildcard $(BIN_DIR_OS)),  $(BIN_DIR_OS))
	"$(MAKE)" -f $(MAKEFILE) clean
endif
	"$(MAKE)" -f $(MAKEFILE) $(BIN_DIR)/$(OUT_NAME).$(HEX_EXTENSION)

# C2Prog extended hex
##########################################################################					
$(BIN_DIR)/$(OUT_NAME).ehx:  $(BIN_DIR)/$(OUT_NAME).hex	
					$(C2PROGROOT)/C2ProgShell -create=$(BIN_DIR)/$(OUT_NAME).ehx -hex=$(BIN_DIR)/$(OUT_NAME).hex -target=$(C2PROG_TARGET)							
	
# Linker (also generates hex-file for programmin the Flash)
##########################################################################					
$(BIN_DIR)/$(OUT_NAME).hex:  $(OBJFILES)
					$(EXE_PATH)/cl2000 -z -i$(LIB_PATH) $(OBJFILES) $(L_OPTIONS)
					$(EXE_PATH)/hex2000 -romwidth 16 -memwidth 16 -i -o $(BIN_DIR)/$(OUT_NAME).hex $(BIN_DIR)/$(OUT_NAME).out

# Explicit rules for PIL
##########################################################################
pil_symbols_c.inc:	$(PPFILES)
					$(PIL_PREP_PATH)/pilpreptool $(PPFILES) -k "cregister __cregister interrupt __interrupt __inline far" -postfix -o pil_symbols

$(BIN_DIR)/pil_symbols_c.obj: $(TARGET_ROOT)/app/pil_symbols_c.c pil_symbols_c.inc
					$(EXE_PATH)/cl2000 $(C_OPTIONS) $(TARGET_ROOT)/app/pil_symbols_c.c 
					
$(BIN_DIR)/pil_symbols_p.obj: $(TARGET_ROOT)/app/pil_symbols_p.c pil_symbols_c.inc
					$(EXE_PATH)/cl2000 $(C_OPTIONS) $(TARGET_ROOT)/app/pil_symbols_p.c 

# PIL Preprocessor
##########################################################################
$(BIN_DIR)/%.pilpp:		%.c	$(HFILES)			
						$(EXE_PATH)/cl2000 $(C_OPTIONS) -DPIL_PREP_TOOL --preproc_only --pp_directory=$(BIN_DIR) $<
						$(call MoveFile, $(BIN_DIR)/$*.pp, $@)

$(BIN_DIR)/%.pilpp:		$(TARGET_ROOT)/src/%.c $(HFILES)			
						$(EXE_PATH)/cl2000 $(C_OPTIONS) -DPIL_PREP_TOOL --preproc_only --pp_directory=$(BIN_DIR) $<
						$(call MoveFile, $(BIN_DIR)/$*.pp, $@)

$(BIN_DIR)/%.pilpp:		$(TARGET_ROOT)/app/%.c $(HFILES)			
						$(EXE_PATH)/cl2000 $(C_OPTIONS) -DPIL_PREP_TOOL --preproc_only --pp_directory=$(BIN_DIR) $<
						$(call MoveFile, $(BIN_DIR)/$*.pp, $@)


$(BIN_DIR)/%.pilpp:		$(TARGET_ROOT)/tisrc/%.c $(HFILES)			
						$(EXE_PATH)/cl2000 $(C_OPTIONS) -DPIL_PREP_TOOL --preproc_only --pp_directory=$(BIN_DIR) $<
						$(call MoveFile, $(BIN_DIR)/$*.pp, $@)rm
			
# Implicit Rules for C-Compile & Assembly
##########################################################################
$(BIN_DIR)/%.obj:		%.c	$(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 
						
$(BIN_DIR)/%.obj:		$(TARGET_ROOT)/src/%.c $(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 	
						
$(BIN_DIR)/%.obj:		$(TARGET_ROOT)/app/%.c $(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 							
											
$(BIN_DIR)/%.obj:		$(TARGET_ROOT)/tisrc/%.c $(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 						
							
$(BIN_DIR)/%.obj:		$(TARGET_ROOT)/%.asm $(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 
						
$(BIN_DIR)/%.obj:		$(TARGET_ROOT)/tisrc/%.asm $(HFILES)
						$(EXE_PATH)/cl2000 $(C_OPTIONS) $< 												
		
##########################################################################
clean:
ifeq ($(wildcard $(BIN_DIR_OS)),  $(BIN_DIR_OS))
		$(call ClearDir, $(BIN_DIR_OS))
else
		mkdir $(BIN_DIR_OS)
endif
