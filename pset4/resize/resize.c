
/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Enlarge the BMP image by multiplier times.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
int multiplier;
int main(int argc, char* argv[])
{
		// ensure proper usage
	if (argc != 4)
		{
				printf("Usage:resize multiplier infile outfile\n");
				return 1;
		}

	
		multiplier = atoi(argv[1]);
		if(multiplier < 0 || multiplier > 100)
		{
				printf(" 0 < multiplier <= 100.\n");
				return 2;
		}

		// remember filenames and multiplier 
		char* infile = argv[2];
		char* outfile = argv[3];

		// open input file 
		FILE* inptr = fopen(infile, "r");
		if (inptr == NULL)
		{
				printf("Could not open %s.\n", infile);
				return 3;
		}

		// open output file
		FILE* outptr = fopen(outfile, "w");
		if (outptr == NULL)
		{
				fclose(inptr);
				fprintf(stderr, "Could not create %s.\n", outfile);
				return 4;
		}

		// read infile's BITMAPFILEHEADER
		BITMAPFILEHEADER bf;
		fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

		// read infile's BITMAPINFOHEADER
		BITMAPINFOHEADER bi;
		fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

		// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
		if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
						bi.biBitCount != 24 || bi.biCompression != 0)
		{
				fclose(outptr);
				fclose(inptr);
				fprintf(stderr, "Unsupported file format.\n");
				return 4;
		}

		// construct bitmap headers for the outfile
		BITMAPFILEHEADER file_header=bf;
		BITMAPINFOHEADER info_header=bi;	

		info_header.biWidth = bi.biWidth * multiplier;
		info_header.biHeight = bi.biHeight * multiplier;

		// Calculate padding
		int padding_in =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
		int padding_out =  (4 - (info_header.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


		// Calculating bfSize, biSizeImage for output image.
		file_header.bfSize = 54 + info_header.biWidth * abs(info_header.biHeight) * 3 + abs(info_header.biHeight) *  padding_out;
		info_header.biSizeImage = ((((info_header.biWidth * info_header.biBitCount) + 31) & ~31) / 8) * abs(info_header.biHeight);

		// write outfile's BITMAPFILEHEADER
		fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, outptr);

		// write outfile's BITMAPINFOHEADER
		fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, outptr);

		for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
		{

					RGBTRIPLE *arr=(RGBTRIPLE *)malloc(sizeof(RGBTRIPLE)*bi.biWidth);
					
						// iterate over pixels in scanline
						for (int j = 0; j < bi.biWidth; j++)
						{
								// temporary storage
								RGBTRIPLE triple;

								// read RGB triple from infile
								fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
								arr[j]=triple;

								// write RGB triple to outfile
								for(int k = 0; k < multiplier; k++) 
								{
										fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
									
								}
						}
						// skip over padding, if any
        				fseek(inptr, padding_in, SEEK_CUR);
						for (int k = 0; k <padding_out; k++)
								fputc(0x00, outptr);

						for(int l = 0; l < multiplier-1; l++)
						{
						
							for (int j = 0; j < bi.biWidth; j++)
							{

								for(int k = 0; k < multiplier; k++) 
								{
										fwrite(&arr[j], sizeof(RGBTRIPLE), 1, outptr);
									
										
								}
							}
							// then add it to outfile
							for (int k = 0; k <padding_out; k++)
								fputc(0x00, outptr);
						}
						
						free(arr);
					
		}

		// close infile
		fclose(inptr);

		// close outfile
		fclose(outptr);

		// that's all folks
		return 0;
}