#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, string argv[]){
    
    //Checks to make sure user inputs two command line arguments   
    if (argc != 2)
    {
        printf("WHAT!\n");
        return 1;
    }
    
    //Converts the key argv to int
    int key = atoi(argv[1]);
    
    //Input from user
    string s = GetString();   
    
    //Encrypting user input
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = ((s[i] - 'A') + key) % 26 + 'A';
            printf("%c", s[i]);
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = ((s[i] - 'a') + key) % 26 + 'a';
            printf("%c", s[i]);
        }
        else
        printf("%c", s[i]);
    }
     
    printf("\n");
    return 0;   
}
