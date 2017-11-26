#include<bits/stdc++.h>
using namespace std;
int knapSack(int value[],int weight[],int n,int W)
{
    int K[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                K[i][j]=0;
            }
            else if (weight[i-1] <= j)
            {
                K[i][j] = max(value[i-1]+K[i-1][j-weight[i-1]], K[i-1][j]);
            }
            else
                K[i][j]= K[i-1][j];
        }
    }
    return K[n][W];
}
int main()
{
    int n;
    cout<<"Enter the total no of items "<<endl;
    cin>>n;
    int value[n];
    int weight[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value"<<endl;
        cin>>value[i];
        cout<<"Enter the weight"<<endl;
        cin>>weight[i];
    }
    int W;
    cout<<"Enter the capacity of the knapsack "<<endl;
    cin>>W;
    cout<<"Answer is "<<knapSack(value,weight,n,W)<<endl;
}
