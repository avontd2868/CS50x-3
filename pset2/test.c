#include <cs50.h>
#include <ctype.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char* s1 = GetString();
    s1 += 1;
    printf("%c", s1);
    return 0;          
}
