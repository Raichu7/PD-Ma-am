#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int minDistance(int dist[], bool sptSet[],int n)
{
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<n;i++)
    {
        if(sptSet[i]==false && dist[i]<min)
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void printSolution(int dist[],int n)
{
    cout<<"VERTEX   DISTANCE FROM SOURCE";
    for(int i=0;i<n;i++)
    {
        cout<<i<<"  "<<dist[i]<<endl;
    }
}
void djistra(int graph[MAX][MAX],int n,int src)
{
    int dist[n];
    bool sptSet[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;
    for(int count = 1;count<n-1;count++)
    {
        int u = minDistance(dist,sptSet,n);
        sptSet[u]=true;
        for(int v=0;v<n;v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[v]!= INT_MAX && dist[v] > dist[u]+graph[u][v])
            {
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist,n);
}
int main()
{
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int graph[MAX][MAX];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter for "<<i<<"th node"<<endl;
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    djistra(graph,n,0);
    return 0;
}
