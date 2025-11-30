#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int main()
{
	int m,n,pixel;
	int width, height;
    char buffer[50];

    FILE *in_file, *out_file1, *out_file2;
    in_file = fopen("ch.pgm", "r");
    out_file1 = fopen("negative.pgm", "w");
    out_file2 = fopen("nth_root.pgm", "w");

    fgets(buffer, sizeof(buffer), in_file); // P2
    fputs(buffer, out_file1);
    fputs(buffer, out_file2);
    do {
        fgets(buffer, sizeof(buffer), in_file);
    } while (buffer[0] == '#');

    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), in_file);

    fprintf(out_file1,"%d %d\n255\n",width, height);
    fprintf(out_file2,"%d %d\n255\n",width, height);

//Exp-4
for (n = 0; n < width; n++) {
        for (m = 0; m < height; m++) {
            fscanf(in_file, "%d", &pixel);
                if (pixel < 0) pixel = 0;
                if (pixel > 255) pixel = 255;

 // Digital negative
           int neg_pixel = 255 - pixel; //negative image | 255=white | 0=black

// Prepare normalization
             double gamma = 0.5; // n-th root (e.g., 0.5 = square root)
             double pow_min=pow(0, gamma); //0
             double pow_max=pow(10, gamma);
// Power-law transformation
             int root_pixel = (((1*pow(pixel,gamma))- pow_min)/(pow_max-pow_min))*255;

           // Write pixels
           fprintf(out_file1,"%d ", neg_pixel);
           fprintf(out_file2,"%d ", (int)(root_pixel+0.5));
        }
    fprintf(out_file1, "\n");  fprintf(out_file2, "\n");
    }

fclose(in_file); fclose(out_file1); fclose(out_file2);
    return 0;
}

