#include <stdio.h>

short reverseBit(short num){
    short a,b,c;
    b=0x01;
    c=0x00;
    for(int i=0; i<16; i++){
        a = num & b;
        a = a >> i;
        b = b << 1;
        c = c << 1;
        c = c | a;

    }
    return c;
}


int main(){
    short num = 0x01;
    
    printf("%x\n", num);
    printf("%x\n", reverseBit(num));
}