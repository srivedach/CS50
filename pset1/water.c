#include<cs50.h>
#include<stdio.h>
int main(void) {
    printf("Minutes: ");
    int w = get_int();
    int b = 12 * w;
    printf("Bottles: %i\n",b);
}