#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
int main(int argc, string argv[]) {
  if(argc!=2) {
      printf("Provide Exactly one argument");
      return 1;
  } 
    int key = atoi(argv[1]);
    if(key <0) {
        printf("please enter a valid key");
        return 1;
    }
    else {
        printf("plaintext: ");
        string name = get_string();
        printf("ciphertext: ");
        for(int i = 0;i<strlen(name);i++) {
            if(isalpha(name[i])) {
            if(isupper(name[i])) {
                name[i] = (((name[i]- 65) + key) % 26) + 65;
                printf("%c",name[i]);
            }
            else if(islower(name[i])) {
                name[i] = (((name[i]- 97) + key) % 26) + 97;
                printf("%c",name[i]);
            }
            else {
                printf("%c",name[i]);
            }
        }
        else
        printf("%c",name[i]);
        
        }
        printf("\n");
    }
    return 0;
}