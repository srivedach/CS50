#include<stdio.h>
#include<cs50.h>
int main(void) {
    float n;
    do {
        printf("O hai! How much change is owed?");
        n = get_float();
    }while(n<0);
    int d = n*100;
    int c = 0;
    while(d-25>=0) {
        c++;
        d = d-25;
    }
    while(d-10>=0) {
        c++;
        d = d-10;
    }
    while(d-5>=0) {
        c++;
        d = d-5;
    }
    while(d-1>=0) {
        c++;
        d = d-1;
    }
    printf("%i\n",c);
}