nasm -f bin -o boot.bin boot.asm
nasm -f bin -o loader.bin loader.asm
nasm -f elf64 -o kernel.o kernel.asm
nasm -f elf64 -o trapa.o trap.asm
nasm -f elf64 -o liba.o lib.asm
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c main.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c trap.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c print.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c debug.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c memory.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c process.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c syscall.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c lib.c 
# i686-elf-gcc -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c keyboard.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c main.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c trap.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c print.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c debug.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c memory.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c process.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c syscall.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c lib.c 
i686-elf-gcc -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -c keyboard.c 

ld -nostdlib -T link.lds -o kernel kernel.o main.o trapa.o trap.o liba.o print.o debug.o memory.o process.o syscall.o lib.o keyboard.o
objcopy -O binary kernel kernel.bin 
dd if=boot.bin of=boot.img bs=512 count=1 conv=notrunc
dd if=loader.bin of=boot.img bs=512 count=5 seek=1 conv=notrunc
dd if=kernel.bin of=boot.img bs=512 count=100 seek=6 conv=notrunc
dd if=user1.bin of=boot.img bs=512 count=10 seek=106 conv=notrunc
dd if=user2.bin of=boot.img bs=512 count=10 seek=116 conv=notrunc
dd if=user3.bin of=boot.img bs=512 count=10 seek=126 conv=notrunc