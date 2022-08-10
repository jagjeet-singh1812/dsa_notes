#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[10],b[20];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<20;j++)
    {
b[j]=a[j];
}

    for(int i=0;i<10;i++)
    {
       printf("%d ",b[i]) ;
    }
}