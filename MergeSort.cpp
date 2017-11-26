#include<bits/stdc++.h>
using namespace std;
void merge1(int arr[],int L[],int lc,int R[],int rc)
{
    int i,j,k;
    i=j=k=0;
    while(i<lc && j<rc)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }
    while(i<lc)
    {
        arr[k++]=L[i++];
    }
    while(j<rc)
    {
        arr[k++]=R[j++];
    }
}
void mergesort(int arr[],int n)
{
    if(n<2)
        return;
    int mid = n/2;
    int L[mid];
    int R[n-mid];
    for(int i=0;i<mid;i++)
    {
        L[i]=arr[i];
    }
    for(int i=mid;i<n;i++)
    {
        R[i-mid]=arr[i];
    }
    mergesort(L,mid);
    mergesort(R,n-mid);
    merge1(arr,L,mid,R,n-mid);
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
    mergesort(arr,n);
    cout<<"after sorting "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
