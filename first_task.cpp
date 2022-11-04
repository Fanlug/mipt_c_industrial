#include <stdio.h>
#include <math.h>
#include <string.h>

void inputValues(double *a, double *b, double *c){
    printf("input a b c values\n");
    scanf("%lf %lf %lf",a,b,c);
}

int solver(double a,double b,double c,double *x1,double *x2 ){
    if( a==0.0){
        if ((b == 0.0) && (c != 0.0))
        {
            return 0;
        }
        else if (b == 0.0)
        {
            return -1;
        }
        else
        {
            *x1 = -b/ c;
            return 1;
        }
    }
    else
    {
        double discremenant = b * b - 4.00 * a * c;
        if (discremenant < 0.0) 
        {
            return 0;
        }
        else if (discremenant == 0.0) 
        {
            *x1 = -b/(2 * a);
            return 1;
        }
        else 
        {
            *x1 = ((- b) + sqrt(discremenant)) / (2 * a);
            *x2 = ((- b) - sqrt(discremenant)) / (2 * a);
            return 2;
        }
    }
}

void ui(){
    char input[100];
    int roots = 0;
    double a,b,c,x1,x2;
    printf("Equations of  a^2+bx+c = 0 type solver\n");
    while (true)
    {
        printf("Choose option:\n    1. Enter parameters a, b anc c with space between them \n    2. Get roots\n    3. End program\n");
        scanf("%s",input);
        if(strstr(input,"1")!=NULL || strstr(input,"2")!=NULL)
        {
            if(strstr(input,"1")!=NULL)
            {
                inputValues(&a,&b,&c);
                roots = solver(a,b,c,&x1,&x2);    
            }
            if(roots==-1)
            {
                printf("Any root\n");
            }
            else if(roots == 0)
            {
                printf("No roots\n");
            }
            else if(roots == 1)
            {
                printf("x1 = %lf\n",x1);
            }
            else if(roots == 2)
            {
                printf("x1 = %lf x2 = %lf\n",x1,x2);
            }
        }
        else if(strstr(input,"3")!=NULL)
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


