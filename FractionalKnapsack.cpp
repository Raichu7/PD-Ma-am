#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double) a.value/a.weight;
    double r2 = (double) b.value/b.weight;

    return r1>r2;
}
double fractionalKnapSack(struct Item arr[],int n, int W)
{
    sort(arr,arr+n,cmp);
    double finalValue=0.0;
    int currentWeight=0;
    for(int i=0;i<n;i++)
    {
        if(currentWeight + arr[i].weight <= W)
        {
            finalValue = finalValue + arr[i].value;
            currentWeight = currentWeight + arr[i].weight;
        }
        else
        {
            double remain = W - currentWeight;
            finalValue = finalValue + arr[i].value* (remain/arr[i].weight);
        }
    }
    return finalValue;
}
int main()
{
    int n,W;
    double ans;
    cout<<"Enter the total no of items "<<endl;
    cin>>n;
    struct Item arr[n];
    int val,wei;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value"<<endl;
        cin>>arr[i].value;
        cout<<"Enter the weight"<<endl;
        cin>>arr[i].weight;
    }
    cout<<"Enter the capacity of the knapsack "<<endl;
    cin>>W;
    ans = fractionalKnapSack(arr,n,W);
    cout<<"The final value is "<<ans;
    return 0;
}
