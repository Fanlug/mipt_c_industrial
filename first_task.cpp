#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    float c, b, a;
    printf("Equations of  a^2+bx+c = 0 type solver\n Enter a b and c float values\n");
    scanf("%f %f %f",&a,&b,&c);
    if (a == 0) {
        if ((b == 0) && (c != 0))
        {
            printf("\nNo Roots");
        }
        else if (b == 0)
        {
            printf("\nInfinity");
        }
        else
        {
            printf("\nRoot: %f", (-c) / b);
        }
    }else {
        float discremenant = b * b - 4 * a * c;
        if (discremenant < 0) {
            printf("\nNo roots");
        }
        else if (discremenant == 0) {
            printf("\nRoot: %f",-b/(2*a));
        }
        else {
            printf("\nRoots: x_1=%f, x_2=%f",
                   ((-b) + sqrtf(discremenant)) / (2 * a),
                   ((-b) - sqrtf(discremenant)) / (2 * a));
        }
    }
}