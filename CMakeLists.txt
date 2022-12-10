#
# Root CMakeLists.txt
#
# Use:
#   mkdir Output && cd Output
#   cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-unix.cmake .. && make
#
# Limitations:
#   It only supports unix like platforms
#
cmake_minimum_required (VERSION 3.15)
project(Blinky_RedV_FE310 ASM C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(DEPLOY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(EXECUTABLE_NAME "${CMAKE_PROJECT_NAME}")
set(EXECUTABLE_FORMAT elf)
set(EXECUTABLE "${EXECUTABLE_NAME}.${EXECUTABLE_FORMAT}")
set(SRC_DIR ${CMAKE_SOURCE_DIR}/Code)
set(LD_SCRIPT "${SRC_DIR}/Memory_Map.ld")

# Set default build type if not defined
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Listed flags
# Architecture
set(ARCH_FLAGS_LIST
  -mcpu=sifive-e31
  -mabi=ilp32 
  -msmall-data-limit=0 
  -falign-functions=4
)

# Optimization
set(OPT_RELEASE_FLAGS_LIST
  -O2
  -fno-reorder-blocks-and-partition
  -fno-reorder-functions
)

set(OPT_DEBUG_FLAGS_LIST
  -O0
)

if(CMAKE_BUILD_TYPE MATCHES Release)
  set(OPT_FLAGS_LIST ${OPT_RELEASE_FLAGS_LIST})
else()
  set(OPT_FLAGS_LIST ${OPT_DEBUG_FLAGS_LIST})
endif()

# C flags
set(C_FLAGS_LIST
  ${OPT_FLAG_LIST}
  ${ARCH_FLAGS_LIST}
  -ffast-math
  -ffunction-sections
  -fdata-sections
  -g3
  -Wconversion
  -Wsign-conversion
  -Wunused-parameter
  -Wuninitialized
  -Wmissing-declarations
  -Wshadow
  -Wunreachable-code
  -Wmissing-include-dirs
  -Wall
  -Wextra
  -fomit-frame-pointer
  -gdwarf
  )

# C++ flags
set(CXX_FLAGS_LIST
  ${C_FLAGS_LIST}
  -fno-exceptions
  -fno-rtti
  -fno-use-cxa-atexit
  -fno-nonansi-builtins
  -fno-threadsafe-statics
  -fno-enforce-eh-specs
  -ftemplate-depth=128
  -Wzero-as-null-pointer-constant
)

# Assembler flags
set(ASM_FLAGS_LIST

)

# LD flags
set(LD_FLAGS_LIST
  ${ARCH}
  -nostartfiles
  -Wl,-T ${LD_SCRIPT}
  -Wl,--print-memory-usage
  -Wl,--print-map
  -Wl,-Map=${DEPLOY_DIR}/${PROJECT}.map
)

# Concatenate listed flags so that they can be parsed when assigned to CMAKE_<X>_FLAGS symbols
string(REPLACE ";" " " C_FLAGS "${C_FLAGS_LIST}")
string(REPLACE ";" " " CXX_FLAGS "${CXX_FLAGS_LIST}")
string(REPLACE ";" " " ASM_FLAGS "${ASM_FLAGS_LIST}")
string(REPLACE ";" " " LD_FLAGS "${LD_FLAGS_LIST}")

# Bind toolchain defintions
set(CMAKE_ASM_COMPILER ${CPP})
set(CMAKE_C_COMPILER   ${CC})
set(CMAKE_CXX_COMPILER ${CPP})
set(CMAKE_ASM_FLAGS "${CXX_FLAGS}")
set(CMAKE_C_FLAGS "${C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LD_FLAGS}")
set(CMAKE_VERBOSE_MAKEFILE OFF) # Set it to ON to have verbose build output

# Construct executable
add_executable(${EXECUTABLE}
  ${SRC_DIR}/Mcal/mtimer.c
  ${SRC_DIR}/Mcal/Mcu.c
  ${SRC_DIR}/Startup/boot.s
  ${SRC_DIR}/Startup/intvect.c
  ${SRC_DIR}/Startup/Startup.c
  ${SRC_DIR}/main.c
  )

target_include_directories(${EXECUTABLE}
  PRIVATE
    ${SRC_DIR}
    ${SRC_DIR}/Mcal
  )

target_link_libraries(${EXECUTABLE}
  PRIVATE
  )

target_link_directories(${EXECUTABLE}
  PRIVATE
  )

target_link_options(${EXECUTABLE}
  PRIVATE
  )

# Post build commands
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${OBJCOPY} -Oihex            ${DEPLOY_DIR}/${EXECUTABLE}    ${DEPLOY_DIR}/${EXECUTABLE_NAME}.hex)
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${OBJCOPY} -Obinary          ${DEPLOY_DIR}/${EXECUTABLE}    ${DEPLOY_DIR}/${EXECUTABLE_NAME}.bin)
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${OBJDUMP} -d                ${DEPLOY_DIR}/${EXECUTABLE}  > ${DEPLOY_DIR}/${EXECUTABLE_NAME}.disa)
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${SIZE}    --format=berkeley ${DEPLOY_DIR}/${EXECUTABLE})

# Print build info
message("=====================================")
message("Project:    ${CMAKE_PROJECT_NAME}")
message("Build type: ${CMAKE_BUILD_TYPE}")
message("=====================================")
