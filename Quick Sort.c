#include<stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[], int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int partition(int arr[], int l, int u)
{
    int piv = arr[u];
    int p2 = l - 1;
    int p1;
    for(p1 = l;p1<=u;p1++)
    {
        if(arr[p1] < piv)
        {
            p2++;
            swap(&arr[p2],&arr[p1]);
        }
    }
    swap(&arr[p2+1],&arr[u]);
    return(p2+1);
}
void quicksort(int arr[],int l, int u)
{
    if(l < u)
    {
        int pi = partition(arr,l,u);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,u);
    }
}
void main()
{
    int n,x;
    printf("Enter the Size of the Array : ");
    scanf("%d",&n);

    int arr[10];
    printf("Enter Elements of the Array : ");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Elements of the Array before Sorting : \n");
    printArray(arr,n);
    quicksort(arr,0,n-1);
    printf("\nElements of the Array after Sorting : \n");
    printArray(arr,n);
}