#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile \n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    static short BLOCKSIZE = 512;
    char *bf = malloc(BLOCKSIZE);
    short file_counter = 0;
    FILE *outptr = NULL;

    while (fread(bf, BLOCKSIZE, 1, inptr) == 1)
    {
    	// check if block is the beginning of a new image
    	if (bf[0] == (char) 0xff && bf[1] == (char) 0xd8 && bf[2] == (char) 0xff && bf[3] >= (char) 0xe0 && bf[3] <= (char) 0xef)
    	{
    		// close file handle if open
    		if (outptr)
    		{
    			fclose(outptr);
    		}

    		// generate filename for image
    		char filename[8];
    		sprintf(filename, "%03d.jpg", file_counter);

    		// open file handle for new image
    		outptr = fopen(filename, "wb");
    		if (outptr == NULL)
    		{
    			fprintf(stderr, "Could not open %s.\n", filename);
    			return 3;
    		}

    		// increment file counter to prepare for next image
    		file_counter++;
    	}

    	// write block to file if file handle is open
    	if (outptr != NULL)
    	{
    		fwrite(bf, BLOCKSIZE, 1, outptr);
    	}

    }

    // close file handle after last loop
    if (outptr != NULL)
    {
    	fclose(outptr);
    }

    fclose(inptr);
}