RED-V_SiFive_RISC-V_FE310_SoC
==================
Bare metal programming on the RED-V Thing Plus board (SiFive RISC-V FE310 SoC)


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

Build on `*nix*` is easy using an installed `gcc-riscv64-unknown-elf`

```sh
cd RED-V_SiFive_RISC-V_FE310_SoC
bash Rebuild.sh
```

The build results including ELF-file, HEX-mask, MAP-file
and assembly list file are created in the `Output`directory.

If `gcc-riscv64-unknown-elf` is not installed, it can easily
be obtained [here](https://github.com/sifive/freedom-tools/releases).
Add the path to the RISC-V GCC tools' bin folder in the usual `*nix` way.

## Continuous Integration

TODO
