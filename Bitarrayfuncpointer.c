#include <stdio.h>

int setBit(int num,int pos)
{
    return num|(1<<pos);
}
int clearBit(int num,int pos)
{
    return num&~(1<<pos);
}
int toggleBit(int num,int pos)
{
    return num^(1<<pos);
}
int getBit(int num,int pos)
{
    return (num>>pos)&1;
}
int main()
{
    int num,pos,choice,r;
    scanf("%d", &num);
    scanf("%d", &pos);
    printf("\n1. Set Bit , \n2. Clear Bit \n3. Toggle Bit \n4. Get Bit ");
    scanf("%d", &choice);
    int (*fp[])(int, int) = {setBit, clearBit, toggleBit, getBit};

    if(choice>=1&&choice<=4)
    {
        r=fp[choice-1](num,pos);
        if(choice==4)
            printf("Bit=%d\n",r);
        else
            printf("Result=%d\n",r);
    }
    else
    {
        printf("Invalid Choice");
    }

    return 0;
}
