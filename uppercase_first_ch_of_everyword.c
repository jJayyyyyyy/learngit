/*  Input a string
 *  Output: uppercase the first character of evrey word
 *          if already uppercased, or other ascii-ch, no change on them
 *
 *  The way of thinking: using ascii
 *  e.g. 'A'+32 = 'a'
 *
**/
#include <stdio.h>
#include <string.h>
#define MAX_NUM 128

int main(){
    char s[MAX_NUM]={0};
    fgets(s, MAX_NUM, stdin);
    int len = (int)strlen(s);
    
    if(s[0]>='a' && s[0]<='z')
        s[0] -= 32;
    for(int i=0; i<len; i++){
        if(s[i] == ' '){
            if(s[i+1]>='a' && s[i+1]<='z')
                s[i+1] -= 32;
        }
    }
    printf("%s\n", s);
    
    return 0;
}
