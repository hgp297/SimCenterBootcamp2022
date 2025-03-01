
// program to read values from a file, each file a csv list of int and two double
// written: fmk
//
// code is written using C language, rewrite using C++ language
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName inputFile\n");
    return -1;
  }
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      double *tmp = (double *)malloc(maxVectorSize*2*sizeof(double));
      for (int i=0; i<maxVectorSize; i++)
	tmp[i] = vector1[i];
      free(vector1);
      vector1 = tmp;

      tmp = (double *)malloc(maxVectorSize*2*sizeof(double));
      for (int i=0; i<maxVectorSize; i++)
	tmp[i] = vector2[i];
      free(vector2);
      vector2 =  tmp;      

      maxVectorSize *= 2;
    }
  }

  fclose(filePtr);  
}
