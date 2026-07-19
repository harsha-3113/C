#include "BM.h"

void setbit(bitmap *bmp, int16 bitno, bool val)        //sets that particular bit to 0 if false, 1 if true
{
    int16 byteno, bitpos, mask, newbyte;
    int8 byte;
    if(!bmp)
        return;

    byteno = (bitno/8);
    bitpos = (bitno%8);
    byte = (int8)bmp[byteno];
    if(val)
    {
        mask = ( 1<<bitpos);
        newbyte = (byte | mask);                       //OR operator adds 1 into the original byte
    }
    else
    {
        mask = ~( 1<<bitpos);                         //~ inverts the masked byte,so everything would be 1 except bitpos, which will be 0
        newbyte = (byte & mask);                      //AND operator makes that particular bit 0(0*x=0) and everything else would be as it is(1*x=x)
    }

    bmp[byteno] = newbyte;

    return;
}

bitmap *mkbmp(int16 bits)                              //creates a bit map which stores 'bit' number of bits
{
    int16 bytes;
    bitmap *p;
    bytes = (bits + 7) / 8;                            //calculates number of bytes to allocates(1 byte = 8 bits)
    p = malloc($i bytes);                              // p = malloc((int)bytes);
    if (!p)
        return (bitmap *)0;
    zero(p, bytes);

    return p;
}

bool getbit(bitmap *bmp,int16 bitno)                   //tells whether the bit at a position in a byte is True or False
{
    int16 byteno;
    int8 byte, bitpos, mask;
    bool bit;

    if(!bmp)
        return false;

    byteno = (bitno/8);                                //suppose i want to access bitno 10..it would be stored in the first byte(indexing is from 0)
    bitpos = (bitno % 8);                              //10 is in the second position of the first byte
    byte = (int8)bmp[byteno];                          //accessing the byte containing 10
    mask = (1 << bitpos);                              //mask makes all other bits 0 except the bitpos in a duplicate string
    bit = ((byte & mask) >> bitpos) ? true : false;    //now the and operator makes all the other bits 0 except bitpos, when shifted rigt by bitpos the final value is either 00000000 or 00000001

}

void zero(int8 *dst,int16 size)
{
    int8 *p;
    int16 n;
    for(p=dst,n=size;n;n--,p++)
    {
            *p=0;
    }
    return; 
}

void print_byte(bitmap b)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (b >> i) & 1);
    }
    printf("\n");

    return;
}

void random_noise(bitmap *bmp, int16 bits)
{
    for (int16 i = 0; i < bits; i++)
    {
        setbit(bmp, i, rand() % 2);
    }
}

void print_bitmap(bitmap *bmp, int16 width, int16 height)
{
    for (int16 y = 0; y < height; y++)
    {
        for (int16 x = 0; x < width; x++)
        {
            printf("%c", getbit(bmp, y * width + x) ? '#' : '.');
        }
        printf("\n");
    }
}


int main()
{
    bitmap *bmp;
    bmp = mkbmp(16);
    if(!bmp)
        return 0;

    //setbit(bmp, 9, true);
    //setbit(bmp, 10, true);
    //setbit(bmp, 9, false);
    //printf("bit 9 = %d\n",(getbit(bmp,9))?1:0);
    //printf("%s",(char *)mkbmp);
    //printf("Byte 0 = %u\n", bmp[0]);
    //printf("Byte 1 = %u\n", bmp[1]);
    //printf("Byte 0: ");
    //print_byte(bmp[0]);

    //printf("Byte 1: ");
    //print_byte(bmp[1]);
    srand(time(NULL));
    bmp = mkbmp(64);
    random_noise(bmp, 64);
    print_bitmap(bmp, 8, 8);
    free(bmp);
    return 0;
}