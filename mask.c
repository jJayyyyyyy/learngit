#include <stdio.h>

int setBit(int *X, int nBit){
    int bitSet = 1;
    bitSet <<= nBit;
    *X |= bitSet;
    
    return 1;
}

int clearBit(int *X, int nBit){
    int bitSet = 1;
    bitSet <<= nBit;
    *X &= ~bitSet;
    
    return 1;
}

int main(){
    
    int X=10;
    printf("%d\n", X);
    
    setBit(&X, 2);
    printf("%d\n", X);
    
    clearBit(&X, 2);
    printf("%d\n", X);
    
    return 0;
    
}