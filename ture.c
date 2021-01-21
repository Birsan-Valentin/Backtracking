#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <conio.h> //  getch();

void init (int n, int st[]);
void introduce(int n, int a[]);
int proba(int p, int n, int st[]);
int valid (int p ,int st[]);
int final(int p);
void tipar(int n, int a[], int st[]);

int main()
{
    int n ;
    printf("n= ");
    scanf("%d",&n);
    int sol,OK;
    int a[n + 1];
    int st[n + 1] ;
    init(n,st);
    introduce(n,a);
    int g;
    g = 1;
    while (g > 0)
    {
    do
        {
            sol = proba(g,n,st);
            if (sol == 1) OK = valid(g,st);
        }
    while (!(!sol || (sol && OK)));
    if (sol == 1 && OK == 1) {
                               if (g == n) tipar(n, a, st);
                               g = g + 1;
                               st[g] = 0;
                              }
    else g = g -1;
    }

    return 0;
}
void init (int n,int st[])
{
    int i;
    for (i = 1; i <= n; i++)
    st[i] = 0;
}
void introduce(int n, int a[])
{
    int i;
    for (i = 1;i <= n;i++)
    {
        printf("a[ %d ]=",i);
        scanf("%d",&a[i]);
    }

    for (i = 1; i <= n ;i++)
        printf("%d ",a[i]);
        printf("\n");
}
int proba(int p, int n, int st[])
{
    int rezult;
    if ((p <= n) && (st[p]<n)) {
                                  st[p] = st[p] + 1;
                                  rezult = 1;
                               }
    else rezult = 0;
    return rezult;
}
int valid (int p , int st[])
{
    int rezult;
    int j;
    rezult = 1;
    for (j = 1;j<=p-1;j++)
    if (st[j] == st[p]) rezult = 0;
    return rezult;
}
void tipar(int n,  int a[], int st[])
{
    int k;
    for (k = 1; k <= n; k++)
    {
        printf("(%d,%d) ",k,st[k]);
    }
    printf("\n");
}
