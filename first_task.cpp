#include <stdio.h>
#include <math.h>
#include <string.h>

struct Roots{
    int quantity = 0;
    double roots[2];
};


void inputValues(double *a, double *b, double *c){
    printf("input a b c values\n");
    scanf("%lf %lf %lf",a,b,c);
}

void printRoots(Roots *roots){
    if(roots->quantity==-1)
    {
        printf("Any root");
    }
    else if(roots->quantity == 0)
    {
        printf("No roots");
    }
    else if(roots->quantity > 0){
        for (size_t i = 1; i <= roots->quantity; i++)
        {
            printf("x%d=%lf \n",i,roots->roots[i-1]);
        }
    }
}

void solver(double a,double b,double c,Roots *roots){
    if( 0.001>abs(a)){
        if ( 0.001>abs(b) &&  0.001<abs(c))
        {
            roots->quantity = 0;
        }
        else if (0.001>abs(b))
        {
            roots->quantity = -1;
        }
        else
        {
            roots->roots[0] = -b/ c;
            roots->quantity = 2;
        }
    }
    else
    {
        double discremenant = b * b - 4.00 * a * c;
        if (discremenant < 0.0) 
        {
            roots->quantity = 0;
        }
        else if (0.001>discremenant) 
        {
            roots->roots[0] = -b/(2 * a);
            roots->quantity = 1;
        }
        else 
        {
            roots->roots[0] = ((- b) + sqrt(discremenant)) / (2 * a);
            roots->roots[1] = ((- b) - sqrt(discremenant)) / (2 * a);
            roots->quantity = 2;
        }
    }
}

void ui(){
    char input = '1';
    Roots roots;
    double a,b,c;
    printf("Equations of  a^2+bx+c = 0 type solver\n");
    while (input!='4')
    {
        if(input<'5' && input>'0')
            printf("1. Enter parameters a, b anc c\n2. Solve equation\n3. Get roots\n4. End program\nChoose option:");
        input = getchar();
        if(input<'5' && input>'0'){
            switch(input){
                case '1':inputValues(&a,&b,&c);break;
                case '2':solver(a,b,c,&roots);break;
                case '3':printRoots(&roots);break;
            }
            putchar('\n');
        }
        
    }
}

int main(int argc, char* argv[])
{
    ui();
}


