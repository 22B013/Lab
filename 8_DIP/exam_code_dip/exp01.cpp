#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int main()
{
	int m,n,pixel;
	int width, height;
char buffer[50];
    FILE *in_file, *out_file;
    in_file = fopen("ch.pgm", "r");
    out_file = fopen("out1.pgm", "w");

    fgets(buffer, sizeof(buffer), in_file); // P2
    fputs(buffer, out_file);
    do {
        fgets(buffer, sizeof(buffer), in_file);
    } while (buffer[0] == '#');

    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), in_file);
    fprintf(out_file,"%d %d\n255\n",width, height);

//Exp-1
for (n = 0; n < width; n++) {
        for (m = 0; m < height; m++) {
            fscanf(in_file, "%d", &pixel);
                if (pixel < 0) pixel = 0;
                if (pixel > 255) pixel = 255;
            fprintf(out_file,"%d ", pixel); //grayscale image | 255=white | 0=black
        }
        fprintf(out_file, "\n");     }

    fclose(in_file);
    fclose(out_file);

    printf("Done! Image processed successfully.\n");
    return 0;
}
