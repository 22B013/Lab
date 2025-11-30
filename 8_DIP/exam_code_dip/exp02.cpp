#include <stdio.h>
#include <stdlib.h>

int main() {
    int width=640, height=960;
    int  m,n, sub, add;
    int pixel, pixel1;
    char buffer[100];

   FILE *in_file1, *in_file2, *out_file1, *out_file2;
    in_file1 = fopen("ch.pgm", "r");
    in_file2 = fopen("ds.pgm", "r");
    out_file1 = fopen("Addition_Image.pgm", "w");
    out_file2 = fopen("Subtracted_Image.pgm", "w");

    fgets(buffer, sizeof(buffer), in_file1); // P2
    do {
        fgets(buffer, sizeof(buffer), in_file1);
    } while (buffer[0] == '#');

    fgets(buffer, sizeof(buffer), in_file2); // P2
    do {
        fgets(buffer, sizeof(buffer), in_file2);
    } while (buffer[0] == '#');

   fprintf(out_file1, "P2\n%d %d\n255\n", width, height);
    fprintf(out_file2, "P2\n%d %d\n255\n", width, height);

//Exp-2
    for (n = 0; n < width; n++) {
        for (m = 0; m < height; m++) {
            fscanf(in_file1, "%d", &pixel);
            fscanf(in_file2, "%d", &pixel1);

           //Addition
                  add = pixel + pixel1;
                  if (add < 0) add = 0;
                  if (add > 255) add = 255;
     fprintf(out_file1, "%d ", add);
//Subtraction
      sub = pixel - pixel1;
       if (sub < 0) sub = 0;
       if (sub > 255) sub = 255;
       fprintf(out_file2, "%d ", sub);
             }
     fprintf(out_file1, "\n");
     fprintf(out_file2, "\n");
    }

    fclose(in_file1);
    fclose(in_file2);
    fclose(out_file1);
    fclose(out_file2);
    printf("Done! Image processed successfully!\n");
    return 0;
}
