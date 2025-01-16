###########################################################################
## Makefile generated for component 'pll'. 
## 
## Makefile     : pll.mk
## Generated on : Mon Jan 13 16:59:22 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/pll.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

PRODUCT_NAME              = pll
MAKEFILE                  = pll.make
MATLAB_ROOT               = R2022a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = fpga_dsp_model
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = pll_comp.rsp
CMD_FILE                  = pll.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
ARM_TOOLCHAIN_DIR         = $(RELATIVE_PATH_TO_ANCHOR)/arm-none-eabi
ARM_BIN                   = $(ARM_TOOLCHAIN_DIR)/bin

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          ARM GCC Toolchain
# Supported Version(s):    10.x
# ToolchainInfo Version:   2025
# Specification Revision:  1.0

# C Compiler: ARM GCC C Compiler
CC_PATH = $(ARM_BIN)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# CPP Compiler: ARM GCC CPP Compiler
CXX_PATH = $(ARM_BIN)
CXX = "$(CC_PATH)/arm-none-eabi-g++"

# Linker: ARM GCC Linker
LD_PATH = $(ARM_BIN)
LD = "$(LD_PATH)/arm-none-eabi-gcc"

# Archiver: ARM GCC Archiver
AR_PATH = $(ARM_BIN)
AR = "$(AR_PATH)/arm-none-eabi-ar"

#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
RM                  = @del
ECHO                = @echo

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -mcpu=cortex-m4 -mthumb -O3 -ffunction-sections -fdata-sections
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -mcpu=cortex-m4 -mthumb -O3 -ffunction-sections -fdata-sections
LDFLAGS              = -mcpu=cortex-m4 -mthumb -T$(START_DIR)/../stm32mp15xx_m4.ld -Wl,--gc-sections -Wl,-Map=output.map

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/ert_main.elf
PRODUCT_TYPE = "firmware"
BUILD_TYPE = "test firmware"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/pll_ert_rtw \
                     -I$(START_DIR)/include -I$(MATLAB_ROOT)/rtw/c/src \
                     -I$(MATLAB_ROOT)/toolbox/physmod/powersys/powersys \
                     -I$(MATLAB_ROOT)/extern/include \
                     -I$(MATLAB_ROOT)/simulink/include
                     
INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DRT -DUSE_RTMODEL -DERT -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=pll -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/rtw/c/src/rt_matrx.c \
       $(MATLAB_ROOT)/rtw/c/src/rt_printf.c \
       $(START_DIR)/pll_ert_rtw/pll.cpp \
       $(START_DIR)/pll_ert_rtw/pll_data.cpp \
       $(START_DIR)/pll_ert_rtw/rtGetInf.cpp \
       $(START_DIR)/pll_ert_rtw/rtGetNaN.cpp \
       $(START_DIR)/pll_ert_rtw/rt_nonfinite.cpp \
       $(MATLAB_ROOT)/toolbox/physmod/powersys/powersys/sfun_discreteVariableDelay.c

MAIN_SRC = $(START_DIR)/pll_ert_rtw/ert_main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_matrx.o rt_printf.o pll.o pll_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o sfun_discreteVariableDelay.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## FINAL TARGET
###########################################################################

$(PRODUCT) : $(OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(ALL_OBJS)
	@echo "### Created: $(PRODUCT)"
	
# Convert ELF to BIN
$(PRODUCT).bin : $(PRODUCT)
	@echo "### Converting ELF to BIN... "
	$(ARM_BIN)/arm-none-eabi-objcopy -O binary $(PRODUCT) $(PRODUCT).bin
	@echo "### Created: $(PRODUCT).bin"

###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"
   
rt_matrx.o : $(MATLAB_ROOT)/rtw/c/src/rt_matrx.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


rt_printf.o : $(MATLAB_ROOT)/rtw/c/src/rt_printf.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


ert_main.o : $(START_DIR)/pll_ert_rtw/ert_main.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


pll.o : $(START_DIR)/pll_ert_rtw/pll.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


pll_data.o : $(START_DIR)/pll_ert_rtw/pll_data.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/pll_ert_rtw/rtGetInf.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/pll_ert_rtw/rtGetNaN.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/pll_ert_rtw/rt_nonfinite.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"


sfun_discreteVariableDelay.o : $(MATLAB_ROOT)/toolbox/physmod/powersys/powersys/sfun_discreteVariableDelay.c
	$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -o "$@" "$<"

# Resource usage
resources : $(PRODUCT)
	@echo "### Resource usage for $(PRODUCT):"
	$(ARM_BIN)/arm-none-eabi-size $(PRODUCT)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean print-%

all : build $(PRODUCT).bin $(PRODUCT).hex
	@echo "### Successfully generated all binary outputs."

build : $(PRODUCT)

clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\\,$(PRODUCT))
	$(RM) $(subst /,\\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."

print-%:
	@echo $* = $($*)
