/*
        Bisection Method
*/
#include <stdio.h>
#define EPS 1e-7

double function( double x ) { /* equation */
        return ( x*x + x - 2 );
}

void Bisection( double x1, double x2 ) {
        double x;
        int i;
        for(i=1; i<100; i++) {
                x = (x1+x2)/2.0;
                printf("After iteration %3d Root = %.6lf\n", i, x);
                if( function( x ) * function( x2 ) < 0 ) {
                        x1 = x;
                }
                else {
                        x2 = x;
                }
                if( fabs( function(x) ) < EPS ) {
                        printf("\nRoot = %.6lf\n", x);
                        printf("For x = %.6lf f(x) = %.6lf\n", x, function( x ));
                        break;
                }
        }
}

int main() {
        printf("\nBisection Method\n\n");
        printf("Enter the starting values\n");
        double x1, x2;
        scanf("%lf %lf", &x1, &x2);
        if( function( x1 ) * function( x2 ) >= 0.0 ) {
                printf("\nThere is no root in this interval\n");
        }
        else {
                Bisection( x1, x2 );
        }

        return 0;
}
