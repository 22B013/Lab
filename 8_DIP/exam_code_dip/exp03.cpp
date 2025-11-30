#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void displayImage(const char* filename) {
printf("Displaying image: %s\n", filename);   }

int main() {
    int  m,n,pixel;
    int width, height;
    char buffer[50];

    srand(time(NULL));  // Seed random number generator RNG

    FILE *in_file, *out_file;
    in_file = fopen("ch.pgm", "r");
    out_file = fopen("noise_image.pgm", "w");

    fgets(buffer, sizeof(buffer), in_file);
    fprintf(out_file, "%s", buffer);

    do {
           fgets(buffer, sizeof(buffer), in_file);
           fprintf(out_file, "%s", buffer);
} while (buffer[0] == '#');

 sscanf(buffer, "%d %d", &width, &height);

   fgets(buffer, sizeof(buffer), in_file);
    fprintf(out_file, "%s", buffer);

//Exp-3
    // Add noise and write new pixels
    for (int n = 0; n < height; n++) {
        for (int m = 0; m < width; m++) {
            fscanf(in_file, "%d", &pixel);
            int noise = (rand() % 61) - 30;
            pixel += noise;
            if (pixel < 0) pixel = 0;
            if (pixel > 255) pixel = 255;
            fprintf(out_file, "%d ", pixel);
        }
        fprintf(out_file, "\n");
    }

    fclose(in_file);
    fclose(out_file);
    printf("\nDone! Image processed successfully!\n");
    return 0;
}
