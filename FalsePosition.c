/*
        False Position Method
*/
#include <stdio.h>
#define EPS 1e-7

double function( double x ) { /* equation */
        return ( x*x + x - 2 );
}

void FalsePosition( double x1, double x2 ) {
        int itrssn = 0;
        double x;
        for(itrssn=1; itrssn<=50; itrssn++) {
                x = x1 - ( ( function( x1 ) * ( x2-x1 ) ) / ( function( x2 ) - function( x1 ) ) );
                printf("After iteration %3d root = %.6lf\n", itrssn, x);
                if( function( x ) * function( x1 ) < 0 ) x2 = x;
                else x1 = x;
        }
        printf("\nRoot = %.6lf\n", x);
        printf("f( %.6lf ) = %.8lf\n", x, function( x ));
}

int main() {
        printf("\nFalse Position Method\n\n");
        printf("Enter the starting values\n");
        double x1, x2;
        scanf("%lf %lf", &x1, &x2);
        if( function( x1 ) * function( x2 ) >= 0.0 ) {
                printf("\nThere is no root in this interval\n");
        }
        else {
                FalsePosition( x1, x2 );
        }

        return 0;
}
