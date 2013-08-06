/******************
*
*   pset1
*   Itsa Mario!
*   by: Colin+Plus
*
*******************/

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //Variable declared outside of loops for proper scope   
    int rows;
    
    //Asking user for input and checking to see if the number is between 1 and 23
    do
    {
        printf("Please enter a non-negative interger between 1 and 23: ");
        rows = GetInt();
        
    }
    while (rows < 0 || rows > 23);
    
    //Begin drawing the half parymid in rows
    for (int i = 0; i < rows; i++)
    {
        //This loop prints the spacing
        for (int j = rows - 1; j > i; j--) 
            printf(" ");
            
        //This loop draws the #
        for (int k = 0; k <= i; k++)
            if (k == 0)
                printf("##");
            else
                printf("#");
        printf("\n");
    }
    return 0; 
}
