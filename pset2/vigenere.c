#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, string argv[]){
    
    //Checking to see if the user inputs more than 2 command line arguments    
    if (argc !=2)
    {
        printf("Please type two command line argument!\n");
        return 1;
    
    }
    
    
    string key = argv[1];
    int keyLength = strlen(key);
    
    //iterating over the key to make sure all letters are lower cased and alpha.
    for (int i =0; i < keyLength; i++)
    {
      
        if (!islower(key[i]))
            key[i] = tolower(key[i]);
        
        if (!isalpha(key[i]))
        {
            printf("Keyword must contain letters only! \n");
            return 1;   
        }   
    }
    
    //Storing the plain text 
    string p = GetString();   
    
    //Encrypting the plain text
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        if (p[i] >= 'A' && p[i] <= 'Z')
            {
                p[i] = ((p[i] - 'A') + key[j % keyLength] - 'a') % 26 + 'A';
                printf("%c", p[i]);
                j++;
            }
        
        else if (p[i] >= 'a' && p[i] <= 'z')
            {
                p[i] = ((p[i] - 'a') + key[j % keyLength] -'a') % 26 + 'a';
                printf("%c", p[i]);
                j++;
            }
        else
            printf("%c", p[i]);
     }
    
     
    printf("\n");
    return 0;   
}
