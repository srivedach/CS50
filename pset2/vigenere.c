#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
int main(int argc, string argv[])
{
    int i,j;
    if(argc!=2)
    {
        printf("<Key>");
        return 1;
    }
    string keyWord = argv[1];
    for(i=0;i<strlen(keyWord);i++)
    {
        if(islower(keyWord[i]))
        {
            keyWord[i]=keyWord[i]-'a'+'A';
        }
        if(!isalpha(keyWord[i]))
        {
            printf("Enter alphabets only");
            return 1;
        }
    }
    printf("plaintext: ");
    string name = get_string();
    printf("ciphertext: ");
    for(i=0,j=0;i<strlen(name);i++)
    {
        if(name[i]>='A'&&name[i]<='Z')
        name[i]='A'+(name[i]-'A'+keyWord[(j++)%strlen(keyWord)]-'A')%26;
        
        if(name[i]>='a'&&name[i]<='z')
        name[i]='a'+(name[i]-'a'+keyWord[(j++)%strlen(keyWord)]-'A')%26;
    }
    printf("%s\n",name);
    
}