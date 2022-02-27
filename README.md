# x86_64-decOS-MSC-KIIT
<p align="center">
<img src="https://user-images.githubusercontent.com/89090903/155875235-38e91c24-056b-4642-8c77-6df400fc2508.jpg" width="300" height="300">
</p>


A x86 architecture based 64bit operating system(x86_64-decOS) written entirely from scratch. Written mainly in C/C++ and assembly to test and implement various OS modules interrupt handling, memory management unit, user processes, VFS(file system), system calls, paging memory encryption and lot more. x86_64-decOS design requires to understand the working of operating systems internally, x86 architecture, assembly, calling conventions(SYSTEM5 AMD64), and low-level stuff.


## Features

- Exceptions and interrupt handling
- Memory management unit
- User processes implementation
- System calls implementation
- Keyboard driver and console
- File system to read and write data
- Program Execution
- I/O operations
- File system manipulation
- IPC
- Error handling (Interrupt Handling)
- Resource allocation
- Memory protection and Security



## Why?......

There are many reasons to build an operating system from scratch.

For me, the main two reasons are for fun and to learn new things. When I grew bored of working on my custom compiler, I decided to work on a new project and I chose Operating System Development. It's probably the most complicated hobby project that can be done. I had to learn plenty of things to be advance during this project. There are tons of difficulty that you don't even think about in normal programs. More generally, since I love programing, I was sure I could have a lot of fun developping my own OS. There is also the geek side of having its own OS :)


## .......and How?

Writing an operating system from scratch is not easy and at each step you need a lot of information that is not necessarily easily available. Generally, the more advanced your OS is, the less information you'll find.

The main two resources for develpment have been:

 - [The osdev.org Wiki](wiki.osdev.org) : Tons of information of various subjects.
 - [The osdev.org Forum](http://forum.osdev.org/index.php) : Tons of great posts and a lot of very skilled people to help you if you have a specific issue.

A good series of tutorials to start with is the [Broken Thorn series](http://www.brokenthorn.com/Resources/OSDevIndex.html). I haven't followed the complete tutorial (only some specific parts), but it's full of good information and it's probably a good place to start.

There are also the [Junfeng Yang Series](http://www.cs.columbia.edu/~junfeng/11sp-w4118/lectures/). It's much less complete, but if you like tutorials, it's probably going to be helpful.

And of course (if you develop on Intel), the Intel 64 and IA-32 Architectures Software Developer's Manual, there are several parts to the guide, I've mainly used the System Programming - Part 1 part. Although it can seem heavy, it's pretty good and will be an invaluable asset to understand the architecture: for instance, paging and interrupts handling.


## Interface Requirements

USER INTERFACE:-

- A GUI, with icons and windows, etc.
- A command-line interface for running processes and scripts, browsing files in
directories, etc.
- Console: C/C++, assembly(SYSTEM 5AMD64 calling convention)
- File system (FAT12)

HARDWARE INTERFACES:-

- Keyboard functionality
- Linux(preferred)/Windows OS
- 1GB page support with RAM (1024MB)
- x64 + system hardware
- INTEL 64 and IA-32 architecture

SOFTWARE INTERFACES:-

- nasm assembler
- C/C++ cross-compiler
- git
- GitHub
- VirtualBox

## License

x86_64-decOS is distributed under the MIT License. Read LICENSE for details.
