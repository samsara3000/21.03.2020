#include"stdio.h"
#define M_MAX (10)
#define N_MAX (10)
int readMatrix(double *a,int m,int n, const char *name);
enum RETURN_CODES{
   ERROR_OPEN,
   ERROR_READ,
   SUCCESS
};
double f(int m,int i,int j);

void initMatrix(double *a,int m,int n);
void printMatrix(double *a,int m,int n);
