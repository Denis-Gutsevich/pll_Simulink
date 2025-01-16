cmake_minimum_required(VERSION 3.16)

# Project setup
project(pll LANGUAGES C CXX)

# Options and variables
set(MATLAB_ROOT "C:/PROGRA~1/MATLAB/R2022a")
set(MATLAB_BIN "${MATLAB_ROOT}/bin")
set(MATLAB_ARCH_BIN "${MATLAB_BIN}/win64")
set(START_DIR "C:/Denis/FARAMAX/m5_fpga/MATLAB/fpga_dsp_model")
set(MINGW_ROOT "path/to/mingw")

# Add library target
add_library(pll STATIC
    ${MATLAB_ROOT}/rtw/c/src/rt_matrx.c
    ${MATLAB_ROOT}/rtw/c/src/rt_printf.c
    ${START_DIR}/pll_ert_rtw/pll.c
    ${START_DIR}/pll_ert_rtw/pll_data.c
    ${START_DIR}/pll_ert_rtw/rtGetInf.c
    ${START_DIR}/pll_ert_rtw/rtGetNaN.c
    ${START_DIR}/pll_ert_rtw/rt_nonfinite.c
    ${MATLAB_ROOT}/toolbox/physmod/powersys/powersys/sfun_discreteVariableDelay.c
)

# Include directories
target_include_directories(pll PRIVATE
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/toolbox/physmod/powersys/powersys
    ${START_DIR}/pll_ert_rtw
)

# Compiler options
target_compile_options(pll PRIVATE
    -Wall
    -W
    -Wwrite-strings
    -Winline
    -Wstrict-prototypes
    -Wnested-externs
    -Wpointer-arith
    -Wcast-align
    -fwrapv
    -m64
    -O3
    -fno-loop-optimize
    -fno-aggressive-loop-optimizations
)

target_compile_definitions(pll PRIVATE
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTERMFCN=0
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=0
    -DINTEGER_CODE=0
    -DMT=0
    -DRT
    -DUSE_RTMODEL
    -DERT
    -DTID01EQ=0
    -DMODEL=pll
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
)

# Linking options
target_link_libraries(pll PRIVATE
    ws2_32
)

# Add as subdirectory if included from another project
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    # Build executable if this is the main project
    add_executable(pll_exe ${START_DIR}/pll_ert_rtw/ert_main.c)
    target_link_libraries(pll_exe PRIVATE pll)
endif()
