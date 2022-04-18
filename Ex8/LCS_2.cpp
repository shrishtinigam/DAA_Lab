/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
string lcs(string x,string y,int m,int n)
{
    cout<<"In loop";
    int l[m+1][n+1];
    for (int i=0;i<=m;i++)
    {
        for (int j=0;j<=n;j++)
        {
            if (i==0 || j==0)
            l[i][j]=0;
            else if (x[i-1]==y[j-1])
            l[i][j]=l[i-1][j-1] + 1;
            else
            l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
        int len=l[m][n];
        char ca[len+1];
        int i=m;
        int j=n;
        int p=0;
        while (i>0 && j>0)
        {
            if (x[i-1]==y[j-1])
            {
            ca[p]=x[i-1];
            p+=1;
            }
            else if (l[i-1][j]>l[i][j-1])
            i--;
            else
            j--;
        }
        cout<<"LCS: ";
        for (i=0;i<p;i++)
        {
            cout<<ca[i];
        }
}
int main()
{
    string x;
    string y;
    cin>>x>>y;
    cout<<"Input Taken"<<endl;
    cout<<lcs(x,y,x.length(),y.length());
}
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int max(int a,int b)
{
    if (a>=b)
    return a;
    return b;
}
void printLCS( string s1, string s2, int m, int n )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (s1[i-1] == s2[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
     }
   int index = L[m][n];
   cout<<index<<endl;
   char LCS[index+1];
   LCS[index] = '\0'; 
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
     
      if (s1[i-1] == s2[j-1])
      {
          LCS[index-1] = s1[i-1];
          i--; j--; index--;     
      }

      else if (L[i-1][j] >= L[i][j-1])
         i--;
          else
         j--;
   }
   cout<< LCS<<endl;
}
int main()
{
  string s1;
  string s2;
  cin>>s1>>s2;
  printLCS(s1, s2, s1.length(), s2.length());
  return 0;
}