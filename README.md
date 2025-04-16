[![Full Pipeline Tests](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/Tests.yml/badge.svg?branch=main)](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/Tests.yml) [![Documentation Deployed](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/pages/pages-build-deployment/badge.svg)](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/pages/pages-build-deployment) [![CodeQL Advanced](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/codeql.yml/badge.svg)](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/codeql.yml)

# Noble: A Game Development Suite 
**TLDR:** Noble is a language implementation and VM platform for game-development on low-end hardware.

## Project Overview 
### Software
Noble is a general-purpose programming language (GPL) and stack-based virtual-machine (VM) implementation written in C++ for game development on a wide range of hardware. It aims to provide a Object-Oriented (OO) and Garbage-Collected (GC) VM and accompanying GPL for 2D graphics-based game-development on a wide range of hardware devices, and aims to be lightweight enough to run on very low-end embedded devices such as Atmel [ATMega megaAVR](https://en.wikipedia.org/wiki/AVR_microcontrollers#:~:text=megaAVR%20%E2%80%93%20the%20ATmega%20series) series chips as well as conventional desktop envrionments.

### Hardware
Noble GPL ("Noble") is designed to be largely hardware-agnostic. The Noble GPL compiler is designed to be run on a conventional desktop envrionment, and produces Noble Assembly Language (NAL) sequences which can be run by any conforming VM implementation.

## Noble General-Purpose Language
Noble is a weakly-typed, late-bound language based heavily on the [Lox](https://craftinginterpreters.com/the-lox-language.html) language by Robert Nystrom. It aims to provide a simple Object-Oriented language with an emphasis on game-development.

## Noble Assembly Language
Noble Assembly Language (NAL) is the output language produced by the Noble compiler and interpreted by Noble VM implementations. It has the following properties:

**8-Bit Instruction Set**\
NAL uses an 8-bit instruction set. This is designed to have the lowest memory footprint possible per instruction and be as compatible as possible with a wide range of hardware, including platforms using 8-bit general-purpose registers such as in the ATMega megaAVR microcontroller series.

**16-Bit Address Space**\
By default Noble has a 16-bit address space and is capable of addressing up to 64KB of memory, but can be configured to target 32 or 64-bit address spaces using the ```SET_ADDRESS_32``` or ```SET_ADDRESS_64``` compiler flags. 

# Documentation
Documentation is automatically deployed from the ```main``` branch and is found [here](https://tiny-oak-studio.github.io/NobleCore/).
