#include<iostream>
#include<vector>
#include<limits.h>
#include<string>
using namespace std;
int dp[10000][1000];
int max(int j,int k)
{
    if (j>=k)
    return j;
    return k;
}
int lcs(string x,string y, int a,int b,int dp[][1000])
{
    if (a==0 || b==0)
    {
        return 0;
    }
    if (dp[a-1][b-1]!=-1)
    return dp[a-1][b-1];
    if (x[a-1]==y[b-1])
    {
        dp[a-1][b-1]= 1 + lcs(x,y,a-1,b-1,dp);
        return dp[a-1][b-1];
    }
    else
    {
        dp[a - 1][b - 1] = max(lcs(x, y, a, b - 1, dp),lcs(x, y, a - 1, b, dp));
        return dp[a-1][b-1];
    }
}
int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    for (int i=0;i<=1000;i++)
    {
        for (int j=0;j<=1000;j++)
        {
            dp[i][j]=-1;
        }
    }
    int len=lcs(x,y,n,m,dp);
    cout<<len<<endl;
    int pos = 0; 
    int px=x.length();
    int py=y.length();
    char res[len];   
    while ((px != -1) && (py != -1)) {
    if (x[px ] == y[py ]) {
        res[pos++] = x[px ];
        //cout<<res[pos-1];
        //cout<<"Pos Calue: "<<pos;
        px--;
        py--;
    } 
    else if (dp[px - 1][py] >= dp[px][py -1]) {
        px--;
    } 
    else {
        py--;
    }
    }
    //cout<<"\nFianl Ans:"<<res<<endl;
    for (int i=len;i>0;i--)
    {
        //cout<<"Value of I:"<<i<<endl;
        cout<<res[i];
    }
}



//Top Down