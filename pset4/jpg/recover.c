/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

#define BLOCKSIZE 512

int main (void)
{
    // open memory card
	FILE* fp = fopen("card.raw", "r");

	
    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    // open output file
    FILE *outfile;
    outfile = NULL;
    
    // create a variable to name the new image files
    int jpgnum = 0;
    
    while (1)
    {
        BYTE block[BLOCKSIZE] = {};
        
        for (int i = 0; i < BLOCKSIZE; i++)
        {
            // if you reach the end of file, close the file
            if (feof(fp))
            {
                fclose(fp);
                
                // close previously opened output file pointer if necessary
                if (outfile != NULL)
                    fclose(outfile);
                    
                return 0;
            }

            fread(&block[i], sizeof (BYTE), 1, fp);
        }
    
        if ((block[0] == 0xff) && (block[1] == 0xd8) && (block[2] == 0xff) && (block[3] == 0xe0 || block[3] == 0xe1))
        {
            // close previously opened output file pointer if necessary
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            
            // create a constant char array for filename
            char filename[4];

            sprintf(filename, "%03d.jpg", jpgnum);
            jpgnum++; 

            if ((outfile = fopen(filename, "w")) == NULL)
            {
                printf("Could not write image.\n");
                return 1;
            }
 
            // write the block containing the photo to the outfile
            fwrite(&block[0], BLOCKSIZE * sizeof (BYTE), 1, outfile);
        }

        else if (outfile != NULL) 
        {
            fwrite(&block[0], BLOCKSIZE * sizeof (BYTE), 1, outfile);
        }
    }
 
    // close file
    fclose(fp);
 
    // return 0 to exit program 
    return 0;
}
