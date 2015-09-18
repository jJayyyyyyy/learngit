#include <stdint.h>
#include <stdio.h>

//sizeof(arrayname) returns the space that the whole array takes
// e.g. int32_t myArray[10] -->  32/8=4 bytes
// so it returns 4*10 = 40

void print_size(int32_t array[]){
    //here array[] has turned into a pointer, not an array
    //and sizeof(pointer) return the length of a pointer
    //64-bit-system --> 64-bit-pointer 64/8=8 bytes
    printf("%lu\n", sizeof(array));
}

int main () {
    int32_t myArray[10];
    printf("%lu ", sizeof(myArray));//returns (32/8)*10 = 40
    print_size(myArray);//returns (64/8) = 8
}