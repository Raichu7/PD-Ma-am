#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF INT_MAX
void FlyodWarshall(int dist[MAX][MAX],int path[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]<1000 && i!=j)
            {
                path[i][j]=i;
            }
            else
            {
                path[i][j]=-1;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    cout<<"The distance matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The path matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printPath(int dist[MAX][MAX],int path[MAX][MAX],int s,int d)
{
    stack<int> st;
    int x=d;
    st.push(d);
    do
    {
        x=path[s][x];
        st.push(x);
    }while(x!=s);
    while(1)
    {
        x=st.top();
        st.pop();
        cout<<x;
        if(st.empty())
            break;
        else
            cout<<"--("<<dist[x][st.top()]<<")-->";
    }
    cout<<endl;
}
int main()
{
    int dist[MAX][MAX];
    int path[MAX][MAX];
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the distance matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dist[i][j];
        }
    }
    FlyodWarshall(dist,path,n);
    int s,d;
    cout<<"Enter the source "<<endl;
    cin>>s;
    cout<<"Enter the destination"<<endl;
    cin>>d;
    printPath(dist,path,s,d);
    return 0;
}
