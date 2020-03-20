#include"matrix.h"
double f(int m,int i,int j){
    (void)m;
    return m-(i>j?i:j);
}
int readMatrix(double *a, int m, int n, const char *name){
    FILE *fp;
    int i,len=m*n;
    if(!(fp=fopen(name,"r")))
        return ERROR_OPEN;
    for(i=0;i<len;i++){
        if(fscanf(fp,"%lf",a+i)!=1){
            fclose(fp);
            return ERROR_READ;
        }
    }
    fclose(fp);
    return SUCCESS;
}
void initMatrix(double *a, int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            a[i*n+j]=f(m,i,j);
        }
    }
}
void printMatrix(double *a, int m, int n){
    int i,j,n_max,m_max;
    if(N_MAX>n){
       n_max=n;
    }else
    {
     n_max=N_MAX;
    }
    if(M_MAX>m){
       m_max=m;
    }else
    {
     m_max=M_MAX;
    }
    for(i=0;i<m_max;i++){
        for(j=0;j<n_max;j++){
            printf("\t%lf",a[i*n+j]);
        }
        printf("\n");
    }
}


