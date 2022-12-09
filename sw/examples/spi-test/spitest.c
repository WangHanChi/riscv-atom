#include <W25Q64.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n = 50;
    char readbuf [n];
    
    unsigned int address = 0x000000;

     W25Q64_init();
    printf("Reading... ");

    read_bytes(readbuf, n, address);

    printf("Done!\n");

    unsigned int addr = address;
    int print_coloumns = 4;

    unsigned int word = 0;

    for(int i=0; i<n; i++)
    {
        if(i%print_coloumns==0)
        {
            putchar('\n'); puts("0x"); puthex(addr+i, 6, 1); puts(" : ");
            word = 0;
        }
            
        
        puthex(readbuf[i], 2, 1); putchar(' ');
        word = (word >> 8) | (((unsigned int)readbuf[i]) << 24);

        if(i%print_coloumns==print_coloumns-1)
        {
            puts("(0x"); puthex(word, 8, 1); putchar(')');
        }

    }

}
