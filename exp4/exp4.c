#include <stdio.h>
#include<string.h>

int c[20][20],b[20][20];
char S1[20];
char S2[20];

int max(int a, int b)
{ 
    if(a>b){
        return a;
    }
    else
        return b;
}

void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",S1[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}


void lcs(char *S1,char *S2,int m,int n)
{
    
    for(int i=0;i<=m;i++){
        c[i][0]=0;
        for(int j=0;i<=n;i++){
            c[0][i]=0;
                                
            //c, u and l denotes cross, upward and downward directions respectively
            for(i=1;i<=m;i++){
                for(j=1;j<=n;j++)
                {
                    if(S1[i-1]==S2[j-1])
                    {
                        c[i][j]=c[i-1][j-1]+1;
                        b[i][j]='c';
                    }
                    else if(c[i-1][j]>=c[i][j-1])
                    {
                        c[i][j]=c[i-1][j];
                        b[i][j]='u';
                    }
                    else
                    {
                        c[i][j]=c[i][j-1];
                        b[i][j]='l';
                    }
                }
            }
        }
    }

    print(m,n);
    
}
 

int lcs_length(char* x, char* y,int m,int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + lcs_length(x, y, m - 1, n - 1);
    else
        return max(lcs_length(x, y, m, n - 1), lcs_length(x, y, m - 1, n));
}


int main()
{
    
    printf("\nEnter 1st sequence: ");
    scanf("%s",S1);
    printf("Enter 2nd sequence: ");
    scanf("%s",S2);

    int m=strlen(S1);
    int n=strlen(S2);

    printf("\nLength of LCS is %d", lcs_length(S1, S2, m, n));
    printf("\nThe Longest Common Subsequence is: ");
    lcs(S1,S2,m,n);
    
    return 0;
}
