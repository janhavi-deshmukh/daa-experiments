#include <stdlib.h>
#include <math.h>
#include <limits.h>


int s[20][20],m[20][20],p[20];
int n;
void print(int i,int j){
if (i == j)
printf(" M%d ",i);
else
   {
      printf("(");
      print(i, s[i][j]);
      print(s[i][j] + 1, j);
      printf(")");
   }
}
void multiply(){
int q,k;
for(int i=n;i>0;i--)
 {
   for(int j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(int k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}
int chain(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k,min=INT_MAX,count=0;
    for (k = i; k < j; k++) {
        count = chain(p, i, k) + chain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}
int main(){
printf("\n\t--MATRIX CHAIN MULTIPLICATION--\n");
printf("\nEnter the no of matrices: ");
scanf("%d",&n);
printf("\nThe dimensions of matrices are: \n");
    for (int i = 0; i<=n; i++) {
        p[i]= (rand()%(46 - 15 + 1)) + 15;
        printf("%d ", p[i]);
    }
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
{
 m[i][i]=0;
 m[i][j]=INT_MAX;
 s[i][j]=0;
}
multiply();
printf("\n\nMultiplication Sequence : ");
print(1,n);
printf("\n\nMinimum/Optimal number of multiplications is %d\n",chain(p, 1, n));
return 0;
}
