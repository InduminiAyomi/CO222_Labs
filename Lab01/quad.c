#include <stdio.h>
#include <math.h>

int main()
{

    double a,b,c,x1,x2;
    printf("./quad\n");
    printf("Enter the coefficients: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    double d=(b*b)-4*a*c;
    if(d>0)
    {
        double x1=(-b+sqrt(d))/(2*a);
        double x2=(-b-sqrt(d))/(2*a);
        printf("The solutions are %.2lf and %.2lf\n",x1,x2);
    }
    else if(d==0)
    {
        x1=-b/(2*a);
        printf("The solutions are %.2lf\n",x1);
    }
    else
    {

        double e = (-b*b)+(4*a*c);
        x1 = -b/(2*a);
        x2 = sqrt(e)/(2*a);

        if(x1 == 0)
        {
            printf("The solutions are -%.2lfi and +%.2lfi\n",x2,x2);
        }
        else
        {
            printf("The solutions are %.2lf-%.2lfi and %.2lf+%.2lfi\n",x1,x2,x1,x2);
        }

    }

    return 0;
}
