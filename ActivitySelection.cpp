#include<bits/stdc++.h>
using namespace std;
struct Activity
{
    int startTime;
    int finishTime;
};
bool cmp(struct Activity a, struct Activity b)
{
    return (a.finishTime < b.finishTime);
}
void ActivitySelection(struct Activity a[],int n)
{
    sort(a,a+n,cmp);
    cout<<"The activities selected are"<<endl;
    int i=0;
    cout<<"Activity number"<<i+1<<" "<<a[i].startTime<<" "<<a[i].finishTime<<endl;
    for(int j=1;j<n;j++)
    {
        if(a[j].startTime >= a[i].finishTime)
        {
            cout<<"Activity number"<<j+1<<" "<<a[j].startTime<<" "<<a[j].finishTime<<endl;
            i=j;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of activities "<<endl;
    cin>>n;
    struct Activity a[n];
    int s,f;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the start time";
        cin>>a[i].startTime;
        cout<<"Enter the finish time";
        cin>>a[i].finishTime;
    }
    ActivitySelection(a,n);
    return 0;
}
