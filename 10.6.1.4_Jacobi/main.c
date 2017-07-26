#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
    PROGRAM DISPLAYS THE DIFFUSION EQUATION FOR ENERGY? IN A BEAM THROUGH TIME
    _________GAUSS_METHOD______________GAUSS_METHOD_________
    Users Can Change the:
     - initializer multiple (n)     [defined]
     - density coefficient  (D)     [defined]
     - when time stops      (tEND)  [defined]               Meaning for calculation. Program does not help with midlife crises.
     - length of the board  (xEND)  [defined]
     - time step            (dt)    [defined]
     - position step        (dx)    [defined]
*/

// These are equation/situation specific definitions
#define n 1
#define D 1.0
#define tEND 10.0
#define xEND M_PI
#define K 100000
// These are up for variation to be more accurate
#define lam .4
#define dx (M_PI/10)
#define dt (lam/D*dx*dx)
int xSize = (double)xEND/dx +1;
int tSize = (double)tEND/dt +1;
char fileName[100];
char fileNameTimeSepCSV[100];
char fileNameBlockCSV[100];
char fileNameBlockActualCSV[100];
char errorFile[101];
char continu = 'y';


/*
   x : 0->PI
   t : 0->1
*/

// MINI FUNCTION SET TO 0 BY DEFAULT CONDITIONS defined by problem
double F( double t, double x ){ return 0; }
// STEPWISE COMPUTATIONAL FUNCTIONS
void initializeU( double u[xSize][tSize], int );
void boundaryConditions( double u[tSize][xSize], int tRow );
void gaussSliedelfillRow( double[tSize][xSize], int );
// DISPLAY FUNCTION
void printAll( double u[tSize][xSize] );
// EXACT FUNCTION
double exact( double t, double x ){ return exp(-n*n*t)*sin(n*x); }

int main()
{
    double U[tSize][xSize];

    while (continu == 'y'){

        printf("Please Enter the file name in which these values will be stored: \n");
        scanf(" %s", fileName);
        strcpy(fileNameBlockCSV, fileName);
        strcpy(errorFile, fileName);
        strcpy(fileNameBlockActualCSV, fileName);
        strcat(fileNameBlockCSV, "BLOCK.csv");
        strcat(errorFile, "ERROR.csv");
        strcat(fileNameBlockActualCSV, "BLOCKACTUAL.csv");

        /* STEP 1: Set the initial U at t=0 for the length of the beam x: 0->PI */
        initializeU( U, 0 );

        int i; // goes through all the time steps
        for( i=1; i<tSize; i++ ){
        /* STEP 2: Boundary Conditions for Next time Step */
            boundaryConditions( U, i );
        /* STEP 3: Filling in the rest of the current time Step */
            gaussSliedelfillRow( U, i );
        }


        /* STEP 4: Displaying the Results */
        printAll( U );

        printf("\n\nLambda Marker to compare to Explicit:\n %lf\n\n", lam);

        printf("\nWould you like to continue again? (y/n) ");
        scanf(" %c", &continu);
    }


    return 0;
}


// PRINTING FUNCTION
void printAll( double u[tSize][xSize] ){
    int i, j; double error;

    FILE *ef = fopen(errorFile, "w");
    FILE *bf = fopen(fileNameBlockCSV, "w");
    FILE *abf = fopen(fileNameBlockActualCSV, "w");

    for( i=0; i<tSize; i++ ){
        for( j=0; j<xSize; j++ ){
            if( j==0 )printf("ESTIMATE:\t");
            printf("%lf\t", u[i][j] );
            fprintf(bf,"%lf,", u[i][j]);
        }
        fprintf(bf,"\n");

        for( j=0; j<xSize; j++ ){
            if( j==0 )printf("\nACTUAL:\t\t");
            printf("%lf\t", exact(i*dt, j*dx) );
            fprintf(abf, "%lf,", exact(i*dt, j*dx) );
        }
        fprintf(abf, "\n" );

        for( j=0; j<xSize; j++ ){
            if( j==0 )printf("\nERROR:\t\t");
            error = fabs(exact(i*dt, j*dx)-u[i][j])/exact(i*dt, j*dx) *100;
            if( u[i][j] == 0 || ( j==0 || j==xSize-1) ) error = 0.0;
            printf("%lf\t", error );
            fprintf(ef, "%lf,", error );
        }
        fprintf(ef, "\n");

        printf("\n\n\n\n");
    }

    fclose(ef);
    fclose(abf);
    fclose(bf);

}


void initializeU( double u[tSize][xSize], int j ){
    int i;
    for( i=0; i<xSize; i++ ){
        u[j][i] = sin(i*dx*n);
    }
}
void boundaryConditions( double u[tSize][xSize], int tRow ){
    u[tRow][0] = 0;
    u[tRow][xSize-1] = 0;
}

void gaussSliedelfillRow( double u[tSize][xSize], int t){
    /* STEP A: SETTING UP THE Variables for gaussSliedel */
        // In Reality the a b and c would be a non tridiagonal matrix and they wouldnt be constant
    double a=1+ 2*lam, b=-lam, c=-lam, f; int j; int k;
    double uT[xSize];

    // Fill with the guess
    initializeU( u, t );

    // Fill the temporary array for the k iterations
    for( j=0; j<xSize; j++){
         uT[j] = u[t][j];
    }

    // Actual Gauss Formula for k iterations with the temporary array loaded
    for( k=0; k<K; k++)
        for( j=1; j<xSize-1; j++){
            f = u[t-1][j];
            uT[j] = (f -( b*uT[j-1] + c*uT[j+1] ) )/a;
        }

    // Copying the temporary value back to the actual array
    for( j=1; j<xSize-1; j++){
        u[t][j] = uT[j];
    }

}
