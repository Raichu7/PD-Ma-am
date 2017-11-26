#include<bits/stdc++.h>
using namespace std;
#define MAX 100
bool isSafe(bool board[MAX][MAX],int r,int c,int n)
{
    int i,j;
    for( i=0;i<c;i++)
    {
        if(board[r][i])
            return false;
    }
    for(i=r,j=c;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }
    for(i=r,j=c;i<n && j>=0;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}
bool NQueen(bool board[MAX][MAX],int n,int c)
{
    if(c>=n)
    {
        static int cnt=0;
        cnt++;
        cout<<"Solution number"<<cnt<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,c,n))
        {
            board[i][c]=1;
            NQueen(board,n,c+1);
            board[i][c]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter the size of the board";
    cin>>n;
    bool board[MAX][MAX];
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            board[MAX][MAX]=0;
        }
    }
    if(!NQueen(board,n,0))
        cout<<"No solution exist";
    return 0;
}
