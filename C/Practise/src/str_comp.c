#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_cmp( const char *s1, const char *s2 ){

    int count = 0;
    int len = sizeof(s1);

    for (int i = 0; i < len; i++){
        if (s1[i] == s2[i]){
            count++;
        }
    }
    return count;
}

int main(){

    char x[15] = "ABCDEFGHI";
    char y[15] = "ABCDEMJKL";
    
    int total = str_cmp(x,y);

    printf("%d\n", total);

    return 0;
}