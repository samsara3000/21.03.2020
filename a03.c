#include"a03.h"
void transp(double *a,int n){
    int i,j;
    double *pi;
    double *pj;
    double si=0;
    for(i=0;i<n-1;i++){
        j=i+1;
        pi=a+i*n+j;
        pj=a+j*n+i;
        for(j=0;j<n-i-1;j++){
            si=pi[j];
            pi[j]=pj[j*n];
            pj[j*n]=si;
            }
        }
    }
