[![Full Pipeline Tests](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/Tests.yml/badge.svg?branch=main)](https://github.com/Tiny-Oak-Studio/NobleCore/actions/workflows/Tests.yml)

# Noble: An ATMega Game Console
**TLDR:** Noble is a language implementation and VM platform for game-development on Atmel ATMega chips.

## Project Overview 
### Software
Noble is a general-purpose programming language (GPL) and stack-based virtual-machine (VM) implementation written in Arduino/C++ for game development on Atmel [ATMega megaAVR](https://en.wikipedia.org/wiki/AVR_microcontrollers#:~:text=megaAVR%20%E2%80%93%20the%20ATmega%20series) chips. It aims to provide a Reduced Instruction Set Computer (RISC)-based VM and accompanying GPL for 2D graphics-based game-development on AVR ATMega chips. 

### Hardware
Noble GPL ("Noble") is designed to be largely hardware-agnostic and instead provides a framework for easy VM implementation on any hardware able to support execution of Noble Assembly Language (NAL) sequences. There is _one_ exception: Noble assumes access to the [SD library](https://www.arduino.cc/reference/en/libraries/sd/) from Arduino and requires an active SD-card module to be present in any hardware configuration that wants to support Noble software. 

## Noble General-Purpose Language
Noble is a weakly-typed, late-bound language based heavily on the [Lox](https://craftinginterpreters.com/the-lox-language.html) language by Robert Nystrom. It aims to provide a simple [context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar) for Object-Oriented Programming (OOP), with an emphasis on game-development targeting [ATMega megaAVR](https://en.wikipedia.org/wiki/AVR_microcontrollers#:~:text=megaAVR%20%E2%80%93%20the%20ATmega%20series) series chips from Atmel. The compiler performs three passes: The initial AST contruction phase, an optimisation phase, and then the final NAL generation phase. The compiler's final output language is NAL.

## Noble Assembly Language
Noble Assembly Language (NAL) is the intermediary language produced by the Noble compiler and interpreted by Noble VM implementations. It has the following properties:

**8-Bit Instruction Set**
Noble Assembly Language operates using an 8-bit instruction set. This is designed to be as compatible as possible with a wide range of hardware, including platforms  using 8-bit general-purpose registers such as in the ATMega megaAVR microcontroller series. This limits the maximum size of the instruction set to 256, but enables us to make the most use of registers on low-end chips.

**16-Bit Address Space**
Noble _assumes_ a 16-bit address space, but can be configured to target a 32 or 64-bit address space using the ```SET_ADDRESS_32``` or ```SET_ADDRESS_64``` compiler flags. It is important to note that compiling with these flags set will result in different NAL sequences for each target address space, so care should be taken to set the appropriate flags for the target environment.

# Documentation
Documentation is automatically deployed from the ```main``` branch and is found [here](https://github.com/Tiny-Oak-Studio/NobleCore).
