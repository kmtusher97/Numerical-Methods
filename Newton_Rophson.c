/* Newton-Rophson Method */
#include <stdio.h>
#define EPS 1e-7

double f( double x ) {
        return ( x*x - 3*x + 2 );
}

double f1( double x ) {
        return ( 2*x - 3 );
}

void NewtonRophson( double x ) {
        double x1 = x - ( f(x) / f1(x) );
        int i = 0;
        while( 1 ) {
                printf("After iteration %3d root = %.6lf\n", ++i, x1);
                if( fabs( (x1-x)/x1 ) < EPS ) {
                        printf("\nRoot = %.6lf\nf( %.6lf ) = %.6lf\n", x1, x1, f(x1));
                        break;
                }
                x = x1;
                x1 = x - ( f(x) / f1(x) );
        }
}

int main() {
        printf("\nNewton-Raphson Method\n\n");
        printf("Enter the starting value of x\n");
        double x;
        scanf("%lf", &x);
        NewtonRophson(x);

        return 0;
}
