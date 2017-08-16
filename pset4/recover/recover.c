#include <cs50.h>       
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* file_name = fopen("card.raw", "r");
    if (file_name == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }
    unsigned char buffer[512];
 
    int count = 0;
    
    FILE* img = NULL; 
    int img_found = 0; //false
    
    while  (fread(buffer, 512, 1, file_name) == 1) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (img_found == 1) {
                fclose(img);
            }
            else {
                img_found = 1;
            }
            
            char filename[8];
            sprintf(filename, "%03d.jpg", count);
            img = fopen(filename, "a");
            count++;
        }
        
        if (img_found == 1) {
            fwrite(&buffer, 512, 1, img);
        }
        
    }
    fclose(file_name);
    fclose(img);

    return 0;
}