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

INSTALL_DIR=/Users/beat/workspace_v7/dev_28069/cg
MAKEFILE=Controls.mk
HFILE = Controls.h

##############################################################

ifeq ($(OS),Windows_NT)
# Windows
ClearDir=del /F /Q $(1)\*.*
MoveFile=move /Y $(subst /,\,$(1)) $(subst /,\,$(2))
CopyFile=cp /Y $(subst /,\,$(1)) $(subst /,\,$(2))
FixPath=$(subst /,\,$(1))

else
# Linux style
FixPath = $(1)
ClearDir=rm -Rf $(1)/*
MoveFile=mv $(1) $(2)
CopyFile=cp $(1) $(2)
endif 

INSTALL_FILES=\
  $(INSTALL_DIR)/settings_cg.h \
  $(INSTALL_DIR)/settings.inc \
  $(INSTALL_DIR)/$(HFILE) \
  $(patsubst %.c, $(INSTALL_DIR)/%.c, $(SOURCE_FILES))

# make all variables available to sub-makes
export

##########################################################################						
all:
	"$(MAKE)" -f $(MAKEFILE) $(INSTALL_FILES)

##########################################################################
$(INSTALL_DIR)/%.c:		%.c
						$(call CopyFile, $*.c, $@)
						
$(INSTALL_DIR)/%.h:		%.h
						$(call CopyFile, $*.h, $@)
						
$(INSTALL_DIR)/%.inc:	%.inc
						$(call CopyFile, $*.inc, $@)

