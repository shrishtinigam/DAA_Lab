/*
Rabin Karp Algorithm - Fix Bug
Given a text T and a pattern P, implement rabin karp algorithm to print all 
occurrences of P in T. Assume that only digits will be given as input. For 
example, if T is "235902314152673992" and P is "31415" then print 6 
(programming index).

Note: The code given has a bug fix it

Input Format
First line contains the text, T
Next line contains the pattern, P

Output Format
Print all indices of occurrence of P in T
Print one index in one line
*/

#include<iostream>
using namespace std;
#include<string>
#include<math.h>

bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}

int valueOf(char ch)
{
    return (ch-'0');
}
bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}
void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i,s;
    n = T.length();
    m = P.length();
    h = (int)pow(d,m-1)%q;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q;
        t0 = (d*t0 + valueOf(T[i]))%q;
    }
    for(s=-1;s<n-m;s++)
    {
        if(p==t0)
        {
           if (check_characters(T,P,s))
                cout<<s+1<<endl;
        }
        if(s<n-m)
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q;
        if(t0<0)
            t0=t0+q;
            
    }
}

int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}