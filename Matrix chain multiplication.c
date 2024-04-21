#include<stdio.h>
#include<limits.h>
#define MAX 10
int m[MAX][MAX],s[MAX][MAX];
void print_optimal_parens(int i, int j)
{
    if(i==j)
    printf("A%d",i);
    else{
        printf("(");
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        printf(")");
    }
}
void matrix_chain_order(int p[], int n)
{
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    m[i][i] = 0;
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-1+1;i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k = i;k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nCost Matrix \n");
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }

    printf("Parenthesization Matrix\n");
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum Cost = %d \n",m[1][n-1]);
    printf("\nOptimal Parenthesization = ");
    print_optimal_parens(1,n-1);
    printf("\n");
}

int main()
{
    int n,i;

    printf("Enter Number of Matrices : ");
    scanf("%d",&n);

    int p[n+1];

    printf("Enter Dimensions : \n");

    for(i = 0;i<n+1;i++)
    scanf("%d",&p[i]);

    matrix_chain_order(p,n+1);
}