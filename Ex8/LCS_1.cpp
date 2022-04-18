#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
#include<set>
void lcs_length(string x, string y, vector<vector<int> >&c, vector<vector<char> > &b)
{
    int m,n,i,j;
    m = x.length();
    n = y.length();
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'd';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
    }
}
void print_LCS(vector<vector<char> > &b, vector<vector<int> > &c, string x,int i, int j, int max_len,string &op,set<string>& subsequences)
{
 

    char temp[1];
    if((i==0)||(j==0))
    {
        if(op.length()==max_len)
            subsequences.insert(op);


        return ;
    }
    if(b[i][j]=='d')
    {

        temp[0]=x[i-1]; 
        string new_str(temp);
        new_str.append(op);
        print_LCS(b,c,x,i-1,j-1,max_len,new_str,subsequences);
    }
 
   else if(c[i-1][j]==c[i][j-1])
    {
       print_LCS(b,c,x,i-1,j,max_len,op,subsequences);
       print_LCS(b,c,x,i,j-1,max_len,op,subsequences);
    }
    else if(b[i][j]=='u')
    {
        print_LCS(b,c,x,i-1,j,max_len,op,subsequences);
    }
    else
        print_LCS(b,c,x,i,j-1,max_len,op,subsequences);
}
int main()
{
    string x,y,op;
    set<string> subsequences;
    op="";
    int i,j;
    cin>>x>>y;
    vector<vector<int> > c(x.length()+1,vector<int>(y.length()+1,0));
    vector<vector<char> > b(x.length()+1,vector<char>(y.length()+1,'x'));
    lcs_length(x,y,c,b);
print_LCS(b,c,x,x.length(),y.length(),c[x.length()][y.length()],op,subsequences);
    for (auto it = subsequences.begin(); it != subsequences.end(); it++)
        cout << *it << endl;
}