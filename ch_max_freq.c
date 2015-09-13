/*  Input a string
 *  Output the most frequent character
 *
 *  The way of thinking:
 *  using ASCII, count the number of each character
 *  then find out the max number(max_num)
 *  and its according index(max_index)
 *  so the most frequent character is (index + 'a')
 *
 *  time_complexity：O(n)
*/
#include <stdio.h>
#include <string.h>

int main(){
    char s[128]={0};
    int count[26]={0};
    int len=0, i=0;
    int max_num, max_ch;
    
    scanf("%s", s);
    len = strlen(s);
    for(i=0; i<len; i++)
        count[(s[i]-'a')] += 1;
    
    max_num=count[0];
    max_index=0;
    for(i=1; i<26; i++){
        if(count[i] > max_num){
            max_num = count[i];
            max_index = i;
        }
    }
    
    printf("%c\n%d\n", (max_index+'a'), count[max_index]);
    
    return 0;
}