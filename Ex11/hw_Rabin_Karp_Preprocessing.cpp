// Didn't pass
/*
Rabin Karp - Simple preprocessing function
Given a Text 'T' and a Pattern 'P', implement rabin-karp algorithm with 
a simple pre-processing function p such that it returns numerical equivalent 
of digits, 10 to 35 for capital letters and 36 to 61 for small letters. Count 
the number of spurious hits also
Note: Edit the code in the editor to simplify the preprocessing funtion

Input Format
First line contains the text T
Next line contains the pattern, P
Next line contains the total number of characters in the input alphabet
Next line contains a prime number

Output Format
Print the number of spurious hits
Print the position of occurrence of P in T
*/

#include<iostream>
using namespace std;
#include<string>
#include<cmath>
#include<vector>
int valueOf(char ch)
{
    return (ch-'0');
}
bool check_characters(string T, string P, long long s)
{
    long long n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}
void rabin_karp_matcher(string T, string P, long long d, long long q)
{
    d = 62;
    q = 19;
    int spurious_hits = 0;
    vector <int> position; // array of positions of true hits
    // cout << "hello\n";
    long long n, m, h, p, t0, i,s;
    n = T.length();
    m = P.length();
    h = (long long)pow(d,m-1)%q; //%q
    //cout<<"h value is "<<h<<endl;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q; // 
        t0 = (d*t0 + valueOf(T[i]))%q; //%q
    }
    for(s=-1;s<n-m;s++)
    {
        //cout<<p<<" "<<t0<<endl;
        if(p==t0)
        {
            if (check_characters(T,P,s))
                position.push_back(s+1);
            else
                spurious_hits++;
        }
        if(s<n-m)
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q; // %q
        if (t0 < 0)
            t0 = (t0 + q);
    }
    cout << spurious_hits << "\n";
    for (auto i : position)
        cout << i << "\n";
    
}

int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}