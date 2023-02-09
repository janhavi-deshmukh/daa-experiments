#include <stdio.h>
#include<math.h>
double f1(int i)
{
   return pow(3.0/2,i);
}

double f2(int i)
{
   return pow(i,3);
}

int f3(int i)
{
   return i;
}

float f4(int i)
{
   return pow(2,i);
}

double f5(int i)
{
   return log(i);
}

double f6(int i)
{
   return log(i)/log(10);
}

double f7(int i)
{
   return log(log(i));
}

double f8(int i)
{
   return i*pow(2,i);
}

double f9(int i)
{
   return pow(2.71,i);
}

double f10(int i)
{
   return pow(2,log(i));
}
int main()
{
    printf("N value\tF1\tF2\tF3\tF4\tF5\tF6\tF7\tF8\t  F9\t  F10 \t FACTORIAL\n");
    for(int i=0;i<101;i++)
    {
         printf("n=%d\t %.2f\t %.2f\t %d\t %.2f\t %.2f\t",i,f1(i),f2(i),f3(i),f4(i),f5(i));
         
         printf("%.3f\t %.3f\t %.2f\t  %.2f\t  %.2f\n",f6(i),f7(i),f8(i),f9(i),f10(i));
    
    /*int fact=1;

    if(i==0)
    printf("0 ");
    else if(i<=20)
    {
      fact*=i;
      printf("%d ",fact);
    }
    printf("\n");*/
      
    }


   
   }
