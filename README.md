RED-V_SiFive_RISC-V_FE310_SoC
==================
Bare metal programming on the RED-V Thing Plus board (SiFive RISC-V FE310 SoC).

<p align="center">
    <a href="https://github.com/Embedded-System-Lovers/RED-V_SiFive_RISC-V_FE310_SoC/actions">
        <img src="https://github.com/Embedded-System-Lovers/RED-V_SiFive_RISC-V_FE310_SoC/actions/workflows/RED-V_SiFive_RISC-V_FE310_SoC.yml/badge.svg" alt="Build Status"></a>
    <a href="https://github.com/Embedded-System-Lovers/RED-V_SiFive_RISC-V_FE310_SoC/blob/master/LICENSE_1_0.txt">
        <img src="https://img.shields.io/badge/license-BSL%201.0-blue.svg" alt="Boost Software License 1.0"></a>
</p>

This repository implements an entirely manually-written, pure
_bare_ _metal_ Blinky Project for the SiFive RISC-V FE310 SoC
(on the RED-V Thing Plus board).

Features include:
  - CPU, power, chip, clock and PLL initialization,
  - timebase derived from `mtimer`,
  - blinky LED show with adjustable frequency,
  - implementation in C99 with absolute minimal use of assembly.

A clear and easy-to-understand build system based on GNUmake
completes this fun and educational project.

This repository provides keen insight on starting up
a _bare_ _metal_ SiFive RISC-V controller.

## Details on the Application

The application boots from a tiny startup code in the boot ROM.

Following low-level chip initialization, the program jumps to
the `main()` subroutine. Here the timer interrupt is setup
for LED blinky.

The adjustable LED-phase (its half-period) can be tuned
to provide a rudimentary, visible blinky LED show.
The timebase for blinky is based on the `mtimer`
interrupt handler.

## Building the Application

Build on `*nix*` is easy using `gcc-riscv32-unknown-elf`

Both Make and Cmake can be used to build the Application:

```sh
cd RED-V_SiFive_RISC-V_FE310_SoC
```
### Make
```
bash Rebuild.sh
```
### CMake
```sh
mkdir Output && cd Output
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-unix.cmake .. && make
```

The build results including ELF-file, HEX-mask, MAP-file
and assembly list file are created in the `Output`directory.

If `gcc-riscv32-unknown-elf` is not installed, it can easily
be obtained from [embecosm](https://www.embecosm.com/resources/tool-chain-downloads/#riscv-stable).
Add the path of the RISC-V GCC tools' bin folder to `$PATH`
in the usual `*nix` way.

## Continuous Integration

CI runs on pushes and pull-requests with simple
build(s) including result verification on `ubuntu-latest`
using GitHub Actions.

## Licensing

The project code is licensed under BSL with the exception of
the [register definition file](https://github.com/Embedded-System-Lovers/RED-V_SiFive_RISC-V_FE310_SoC/blob/master/Code/Mcal/riscv-csr.h)
originally from [five-embedded](https://five-embeddev.com) which
is licenced under the Unlicense.
