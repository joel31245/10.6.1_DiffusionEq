#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double u0(double n,double x)
{
    return(sin(n*x));
}
double uexact(double n,double t,double x)
{
    return(exp(-pow(n,2)*t)*sin(n*x));
}

void main()
{
double n=1;
double D=1.0;
double F=0.0;
double dx=M_PI/10;
double xi=0.0;
double xf=M_PI;
double tMAX=10;
double lambda=0.01;
double dt=lambda*dx*dx/D;
int i,j,k;
int M=(int)ceil(tMAX/dt);
int N=(int)ceil((xf-xi)/dx);
double u[M+1][N+1];
double a[M+1];
double b[M+1];
double c[M+1];
double arrayres[M+1];
double alpha[M+1];
double g[M+1];
double testu[N+1];

FILE *fptr;
FILE *fp;
fp=fopen("exact.csv","w");
fptr=fopen("implicitdata.csv","w");
for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
    //printf("%lf ",uexact(n,(i*dt),(j*dx)));
    fprintf(fp,"%lf,",uexact(n,(i*dt),(j*dx)));
    }
    fprintf(fp,"\n");
    //printf("\n");
}
//printf("\n\n");

for(j=0;j<=N;j++)
{
    u[0][j]=u0(n,j*dx);
}

for(j=0;j<=N;j++)
{
    a[j]=(1+2*lambda);
    c[j]=-lambda;
    b[j+1]=-lambda;
}

for(i=1;i<=M;i++)
{

for(j=0;j<=N;j++)
{
    arrayres[j]=u[i-1][j];
}
alpha[0]=a[0];
for(j=1;j<=N;j++)
{
    alpha[j]=a[j]-(b[j]*c[j-1])/alpha[j-1];
}

g[0]=arrayres[0];
for(j=1;j<=N;j++)
{
    g[j]=arrayres[j]-(b[j]*g[j-1])/alpha[j-1];
}

u[i][N]=g[N]/alpha[N];
for(j=N-1;j>=0;j--)
{
    u[i][j]=(g[j]-(c[j]*u[i][j+1]))/alpha[j];
}
}

for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
        //printf("%lf ",u[i][j]);
    }
    //printf("\n");
}
for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
        fprintf(fptr,"%lf,",u[i][j]);
    }
    fprintf(fptr,"\n");
}
fclose(fptr);

// Printing out the error values
fp=fopen("error.csv","w");
double error;
for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
        error = (uexact(n, i*dt, j*dx) - u[i][j])/uexact(n, i*dt, j*dx);
        if ( u[i][j] == 0 || uexact(n,i*dt,j*dx)==0 ) error = 0;
        fprintf(fp,"%lf,",error);
    }
    fprintf(fp,"\n");
}
fclose(fp);
}
