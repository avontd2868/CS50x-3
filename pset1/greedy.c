#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Round
int main(void)
{
    int quarters = 25;
    int dimes = 10;
    int nickles = 5;
    int pennies = 1;
    float changeOwed;
    int count = 0;
    
    printf("O hai! ");
    
    do
    
    {
        printf("How much change is owed? \n");
        changeOwed = round(GetFloat() * 100);
    }
    while (changeOwed < 0);
    
   
    
    while (changeOwed >= quarters)
    {
        changeOwed -= quarters;
        count++;
    }
    
    while (changeOwed >= dimes)
    {
        changeOwed -= dimes;
        count++;
    }
    
    while (changeOwed >= nickles)
    {
        changeOwed -= nickles;
        count++;
    }
    
    while (changeOwed >= pennies)
    {
        changeOwed -= pennies;
        count++;
    }
    
    printf("%d", count);
    printf("\n");
    return 0;
    
}
