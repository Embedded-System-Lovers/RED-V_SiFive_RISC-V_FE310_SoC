##############################################################################80
#
#  Copyright Christopher Kormanyos 2023 - 2024.
#  Distributed under The Unlicense.
#
##############################################################################80

##############################################################################80
#
# Makefile
#
# Build system for RED-V_SiFive_RISC-V_FE310_SoC based on standard GNU tools
#
# Using GNU Make 4.2.1 (see version information in build log)
#
# 23-June-2024
#
# See also a definitive list of GCC command line options
# (for numerous target systems) here:
#   https://man7.org/linux/man-pages/man1/gcc.1.html
#
##############################################################################80

############################################################################################
# Defines
############################################################################################

HW_TARGET  = RedV_FE310
PRJ_NAME   = Blinky_$(HW_TARGET)
OUTPUT_DIR = $(CURDIR)/../bin
OBJ_DIR    = $(CURDIR)/../tmp/obj
SRC_DIR    = $(CURDIR)/../Code
LD_SCRIPT  = $(SRC_DIR)/Memory_Map.ld

##############################################################################80
# tools
##############################################################################80

ifeq ($(TYP_CC),LLVM)
PATH_TOOLS_CC   := $(CURDIR)/tools/Util/msys64/usr/local/llvm-17.0.2-riscv32/bin
endif

ifeq ($(TYP_CC),GCC)
PATH_TOOLS_CC   := $(CURDIR)/tools/Util/msys64/usr/local/gcc-13.2.0-riscv32-unknown-elf/bin
endif

TOOL_PREFIX     := $(CURDIR)/tools/UnxUtils/usr/local/wbin
TOOL_PREFIX     := $(TOOL_PREFIX)/

GNUMAKE         := $(CURDIR)/make$(EXEEXT)

EXEEXT          := .exe

ifeq ($(TYP_CC),LLVM)
AS              := $(PATH_TOOLS_CC)/clang++$(EXEEXT)
CC              := $(PATH_TOOLS_CC)/clang++$(EXEEXT)
CP              := $(PATH_TOOLS_CC)/clang++$(EXEEXT)
LD              := $(PATH_TOOLS_CC)/clang++$(EXEEXT)
OBJDUMP         := $(PATH_TOOLS_CC)/llvm-objdump$(EXEEXT)
OBJCOPY         := $(PATH_TOOLS_CC)/llvm-objcopy$(EXEEXT)
READELF         := $(PATH_TOOLS_CC)/llvm-readelf$(EXEEXT)
endif
ifeq ($(TYP_CC),GCC)
AS              := $(PATH_TOOLS_CC)/riscv32-unknown-elf-g++$(EXEEXT)
CC              := $(PATH_TOOLS_CC)/riscv32-unknown-elf-g++$(EXEEXT)
CP              := $(PATH_TOOLS_CC)/riscv32-unknown-elf-g++$(EXEEXT)
LD              := $(PATH_TOOLS_CC)/riscv32-unknown-elf-g++$(EXEEXT)
OBJDUMP         := $(PATH_TOOLS_CC)/riscv32-unknown-elf-objdump$(EXEEXT)
OBJCOPY         := $(PATH_TOOLS_CC)/riscv32-unknown-elf-objcopy$(EXEEXT)
READELF         := $(PATH_TOOLS_CC)/riscv32-unknown-elf-readelf$(EXEEXT)
endif
ECHO            := $(TOOL_PREFIX)echo$(EXEEXT)
MKDIR           := $(TOOL_PREFIX)mkdir$(EXEEXT)
MV              := $(TOOL_PREFIX)mv$(EXEEXT)
RM              := $(TOOL_PREFIX)rm$(EXEEXT)


AS              := $(subst /,\,$(AS))
CC              := $(subst /,\,$(CC))
CP              := $(subst /,\,$(CP))
LD              := $(subst /,\,$(LD))
OBJDUMP         := $(subst /,\,$(OBJDUMP))
OBJCOPY         := $(subst /,\,$(OBJCOPY))
READELF         := $(subst /,\,$(READELF))
ECHO            := $(subst /,\,$(ECHO))
MKDIR           := $(subst /,\,$(MKDIR))
MV              := $(subst /,\,$(MV))
RM              := $(subst /,\,$(RM))

##############################################################################80
# OS-independent abstratcion of the null-device
##############################################################################80

NULL_DEVICE     := NUL
$(NULL_DEVICE)  := NUL

##############################################################################80
# flags
##############################################################################80

OPT            := -O2                                           \
                  -fno-reorder-blocks-and-partition             \
                  -fno-reorder-functions

OPT            := -O0

ARCH           := -mcpu=sifive-e31                              \
                  -mabi=ilp32                                   \
                  -march=rv32imac                               \

ifeq ($(TYP_CC),GCC)
ARCH           += -msmall-data-limit=0
ARCH           += -falign-functions=4
endif

ASOPS          := $(OPT)                                        \
                  $(ARCH)                                       \


ifeq ($(TYP_CC),GCC)
ASOPS          += -Wa,-adhln=$(OBJ_DIR)/$(basename $(@F)).lst
endif


COPS           := $(OPT)                                        \
                  $(ARCH)                                       \
                  -ffast-math                                   \
                  -falign-functions=4                           \
                  -g3                                           \
                  -Wconversion                                  \
                  -Wsign-conversion                             \
                  -Wunused-parameter                            \
                  -Wuninitialized                               \
                  -Wmissing-declarations                        \
                  -Wshadow                                      \
                  -Wunreachable-code                            \
                  -Wmissing-include-dirs                        \
                  -std=c11                                      \
                  -Wall                                         \
                  -Wextra                                       \
                  -fomit-frame-pointer                          \
                  -gdwarf-2                                     \
                  -fno-exceptions


LOPS           := -e Startup_Init                               \
                  $(ARCH)                                       \
                  -ffast-math                                   \
                  -falign-functions=4                           \
                  -Wl,--print-memory-usage                      \
                  -Wl,--print-map                               \
                  -Wl,-T$(LD_SCRIPT)                            \
                  -Wl,-Map=$(OUTPUT_DIR)/$(PRJ_NAME).map

ifeq ($(TYP_CC),GCC)
LOPS           += -nostdlib
LOPS           += -nostartfiles
endif

############################################################################################
# Source Files
############################################################################################

SRC_FILES      := $(SRC_DIR)/Mcal/mtimer.c                      \
                  $(SRC_DIR)/Mcal/Clock.c                       \
                  $(SRC_DIR)/Mcal/Mcu.c                         \
                  $(SRC_DIR)/Startup/boot.s                     \
                  $(SRC_DIR)/Startup/intvect.c                  \
                  $(SRC_DIR)/Startup/Startup.c                  \
                  $(SRC_DIR)/main.c

############################################################################################
# Include Paths
############################################################################################

INC_FILES      := $(SRC_DIR)                                 \
                  $(SRC_DIR)/Mcal

############################################################################################
# Rules
############################################################################################

VPATH := $(subst \,/,$(sort $(dir $(SRC_FILES)) $(OBJ_DIR)))

FILES_O := $(addprefix $(OBJ_DIR)/, $(notdir $(addsuffix .o, $(basename $(SRC_FILES)))))


ifeq ($(MAKECMDGOALS),build)
-include $(subst .o,.d,$(FILES_O))
endif


all : clean version $(OUTPUT_DIR)/$(PRJ_NAME).elf


.PHONY : version
version :
	@-$(ECHO) print compiler version
	@-$(ECHO)
	@-$(CC) -v


.PHONY : clean
clean :
	@-$(ECHO) clean and create directories
	@-$(ECHO)
	@-$(RM) -rf $(OBJ_DIR) *.o       2>$(NULL_DEVICE)
	@-$(RM) -rf $(OBJ_DIR) *.d       2>$(NULL_DEVICE)
	@-$(RM) -rf $(OUTPUT_DIR) *.hex  2>$(NULL_DEVICE)
	@-$(RM) -rf $(OUTPUT_DIR) *.elf  2>$(NULL_DEVICE)
	@-$(RM) -rf $(OUTPUT_DIR) *.list 2>$(NULL_DEVICE)
	@-$(RM) -rf $(OUTPUT_DIR) *.map  2>$(NULL_DEVICE)
	@-$(RM) -rf $(OUTPUT_DIR) *.txt  2>$(NULL_DEVICE)
	@-$(MKDIR) -p $(subst \,/,$(OBJ_DIR))
	@-$(MKDIR) -p $(subst \,/,$(OUTPUT_DIR))


$(OBJ_DIR)/%.o : %.c
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@-$(CC) -x c $(COPS) $(addprefix -I, $(INC_FILES)) -c $< -o $(OBJ_DIR)/$(basename $(@F)).o


$(OBJ_DIR)/%.o : %.s
	@-echo +++ compile: $(subst \,/,$<) to $(subst \,/,$@)
	@-$(CC) -x assembler $(ASOPS) $(addprefix -I, $(INC_FILES)) -c $< -o $(OBJ_DIR)/$(basename $(@F)).o


$(OUTPUT_DIR)/$(PRJ_NAME).elf : $(FILES_O) $(LD_SCRIPT)
	@$(LD) -x none $(LOPS) $(FILES_O) -o $(OUTPUT_DIR)/$(PRJ_NAME).elf
	@$(OBJDUMP) -D --wide $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).list.all
	@$(OBJCOPY) $(OUTPUT_DIR)/$(PRJ_NAME).elf -O ihex $(OUTPUT_DIR)/$(PRJ_NAME).hex
	@$(READELF) --wide -S -s $(OUTPUT_DIR)/$(PRJ_NAME).elf > $(OUTPUT_DIR)/$(PRJ_NAME).readelf
