#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
bool isSafe(bool graph[MAX][MAX],int color[MAX],int n,int v,int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && c==color[i])
            return false;
    }
    return true;
}
bool graphColoring(bool graph[MAX][MAX],int color[MAX],int n,int v)
{
    if(v>=n)
    {
        cout<<"Vertex "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<i;
        }
        cout<<endl<<"Color "<<endl;
        int ch=0;
        for(int i=0;i<n;i++)
        {
            cout<<color[i];
            if(ch<color[i])
                ch=color[i];
        }
        cout<<endl<<"Chromatic number of the graph"<<ch<<endl;
        return true;
    }
    for(int i=1;i<n;i++)
    {
        if(isSafe(graph,color,n,v,i))
        {
            color[v]=i;
            if(graphColoring(graph,color,n,v+1))
                return true;
            color[v]=0;
        }
    }
    return false;
}
int main()
{
    bool graph[MAX][MAX];
    int color[MAX];
    int n;
    cout<<"Enter the number of nodes";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        color[i]=0;
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    if(!graphColoring(graph,color,n,0))
        cout<<"No solution exists"<<endl;
    return 0;
}
