#include <stdint.h>
#include <stdio.h>

void print_size(int32_t *array){
    printf("%lu\n", sizeof(array));
}

int main () {
    int32_t myArray[10];
    printf("%lu ", sizeof(myArray));
    print_size(myArray);
}