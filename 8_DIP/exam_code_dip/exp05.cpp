#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
	int m,n,pixel;
	int width, height;
char buffer[50];

	FILE *in_file,*out_file,*out_file2;
	in_file=fopen("ch.pgm", "r");
	out_file=fopen("log_output.pgm", "w+");
    out_file2=fopen("gamma_output.pgm", "w+");

	fgets(buffer,50,in_file);
    do{
	fgets(buffer,50,in_file);
         } while(buffer[0]=='#');

sscanf(buffer, "%d %d", &width, &height);
fgets(buffer,50,in_file);

fprintf(out_file,"P2\n%d %d\n255\n",width, height);
fprintf(out_file2,"P2\n%d %d\n255\n",width, height);

//Exp-5
    // Prepare normalization
    double gamma=0.5; // Power-law (identity): gamma=1
	double log_min=log(1); //0
	double log_max=log(10); 	double pow_min=pow(0, gamma);
double pow_max=pow(10, gamma);

    // Transformation
for(n=0;n<width;n++) {
    for(m=0;m<height;m++)   {
       fscanf(in_file,"%d",&pixel);

// Log transformation normalization
 int log_s = ((log(1 + pixel) - log_min) / (log_max - log_min)) * 255;
//Power-law normalization
int pow_s = (((1*pow(pixel,gamma))- pow_min)/(pow_max-pow_min))*255;

fprintf(out_file, "%d ", (int)(log_s + 0.5));
fprintf(out_file2, "%d ", (int)(pow_s + 0.5));
    }
}

fclose(in_file); fclose(out_file); fclose(out_file2);
    return 0; }
