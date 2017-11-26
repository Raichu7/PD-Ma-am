#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}
int partition1(int arr[],int start,int end)
{
    int pivot = arr[end];
    int temp;
    int pIndex = start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex],arr[end]);
    return pIndex;
}
void quicksort(int arr[],int start,int end)
{
    if(start<end)
    {
        int p = partition1(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements of the array ";
        cin>>arr[i];
    }
    cout<<endl;
    /*cout<<"The elements are"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }*/
    quicksort(arr,0,n-1);
    cout<<"after sorting "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
