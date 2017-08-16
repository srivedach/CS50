
#include <stdio.h>
#include <cs50.h>
int main(void) {
    
    int n;
    int i,j;
    do {
        printf("Height:");
        n = get_int();
    } while(n<0 || n>23);
    for(i = 0;i<n;i++) {
        for(j=i;j<n-1;j++) {
            printf(" ");
        }
            for(j = 0;j<i+2;j++) {
                printf("#");
            }
                printf("\n");
    }
}