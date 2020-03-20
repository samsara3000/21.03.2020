#include"a02.h"
#include<stdio.h>
double Tracer(double *a, int m, int n){
    double trace=0;
    int i;
    (void)m;
    (void)n;
    for(i=0;i<n;i++){
        trace+=a[i*(n+1)];
    }
    printf("Trace: %lf\n",trace);
    return trace;
}
