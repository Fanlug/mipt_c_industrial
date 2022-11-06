#include <stdio.h>
#include <math.h>
#include <string.h>

struct Roots{
    int quantity = 0;
    double x1,x2;
};


void inputValues(double *a, double *b, double *c){
    printf("input a b c values\n");
    scanf("%lf %lf %lf",a,b,c);
}

void printRoots(Roots *roots){
            if(roots->quantity==-1)
            {
                printf("Any root\n");
            }
            else if(roots->quantity == 0)
            {
                printf("No roots\n");
            }
            else if(roots->quantity == 1)
            {
                printf("x1 = %lf\n",roots->x1);
            }
            else if(roots->quantity == 2)
            {
                printf("x1 = %lf x2 = %lf\n",roots->x1,roots->x2);
            }
}

void solver(double a,double b,double c,Roots *roots){
    if( a==0.0){
        if ((b == 0.0) && (c != 0.0))
        {
            roots->quantity = 0;
        }
        else if (b == 0.0)
        {
            roots->quantity = -1;
        }
        else
        {
            roots->x1 = -b/ c;
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
        else if (discremenant == 0.0) 
        {
            roots->x1 = -b/(2 * a);
            roots->quantity = 1;
        }
        else 
        {
            roots->x1 = ((- b) + sqrt(discremenant)) / (2 * a);
            roots->x2 = ((- b) - sqrt(discremenant)) / (2 * a);
            roots->quantity = 2;
        }
    }
}

void ui(){
    char input[100];
    Roots roots;
    double a,b,c;
    printf("Equations of  a^2+bx+c = 0 type solver\n");
    while (true)
    {
        printf("\n1. Enter parameters a, b anc c\n2. Solve equation\n3. Get roots\n4. End program\nChoose option:");
        scanf("%s",input);
        if(strstr(input,"1")!=NULL)
        {
            inputValues(&a,&b,&c);
        }
        if(strstr(input,"2")!=NULL)
        {
            solver(a,b,c,&roots);                
        }
        else if(strstr(input,"3")!=NULL)
        {
            printRoots(&roots);                
        }
        else if(strstr(input,"4")!=NULL)
        {
            break;
        }
        printf("\n"); 
    }
}

int main(int argc, char* argv[])
{
    ui();
}


