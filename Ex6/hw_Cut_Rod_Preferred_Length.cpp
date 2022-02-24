// hw_Cut_Rod_Preferred_Length.cpp
/*
    Cut Rods of Preferred Lengths
    A rod cutting company streling corporation will cut rods of specific lengths only. 
    Given a list of lengths by which this company will make rods, a rod of length 'n' and 
    list of prices of each piece of rod that shall be cut by the company, write an algorithm 
    and implement it using top down dynamic programming to find maximum revenue that shall be 
    generated. In that case, give a penalty of Rs 1 for each meter of the residue.

    Input Format
    First line contains the length of the rod, n
    Next line contains price of various lengths of rods from 1 to n
    Next line cotains the number of preferred lengths
    Next line contains the preferred lengths separated by a space

    Output Format
    Print the maximum revenue that may be generated 


    Input
    20
    1 5 8 9 10 17 17 20 24 30 31 32 33 34 35 36 37 38 39 40
    2
    3 5

    Output
    50

    Processing Involved
    Recursion 
    Dynamic Programming

    Algorithm/ Pseudocode
    cut_rod_preferred(length, p, n2, pl)  // p -> prices, pl -> array of preferred lengths
    let r[0...100] be an array // human indexing
    for i = 0 to 100
        r[i] = INT_MIN
    r[0] = 0
    r[pl[0]] = p[pl[0]]
    for i = 1 to pl[n2-1]
        if(length < pl[0])
            r[i] = length * (-1)
    return cut_rod_preferred_aux(length, p, n2, pl, r)

    cut_rod_preferred_aux(length, p, n2, pl, r)
        if(length==0)
            return 0
        if(r[length] >= 0)
            return(r[length])
        if(length < pl[0])
            return length * (-1)
        q = INT_MIN
        for i = 0 to n2
            if(length > pl[i])
                q = max(q, p[pl[i]] + cut_rod_preferred_aux(length - pl[i], p, n2, pl, r))
        r[length] = q
        return q
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int cut_rod_preffered_aux(int length, vector<int> &p, int n2, vector<int> &pl, vector<int> &r);
int cut_rod_preffered(int length, vector<int> &p, int n2, vector<int> &pl)
{    
    vector<int> r(100); // human indexing
    for(int i = 0; i < 100; i++)
        r[i] = INT_MIN;
    r[0] = 0;
    r[pl[0]] = p[pl[0]];
    return cut_rod_preffered_aux(length, p, n2, pl, r);    
}
int cut_rod_preffered_aux(int length, vector<int> &p, int n2, vector<int> &pl, vector<int> &r)
{
    if(length==0)
        return 0;
    int q;
    if(r[length] >= 0)
        return(r[length]);
    if(length < pl[0])
        return length * (-1);
    q = INT_MIN;
    for(int i = 0; i < n2; i++)
    {
        if(length > pl[i])
            q = max(q, p[pl[i]] + cut_rod_preffered_aux(length - pl[i], p, n2, pl, r));
    }
    r[length] = q;
    return q;
}
int main()
{
    int i, n1, n2, max_profit;
    
    cin >> n1;
    vector<int> p(n1+1, 0);
    for(i = 1; i <= n1; i++)
        cin >> p[i];
        
    cin >> n2;
    vector<int> pl(n2);
    for(i = 0; i < n2; i++)
        cin >> pl[i];
        
    cout << cut_rod_preffered(n1, p, n2, pl);
}

/* Code that was submitted, above code is improved
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int cut_rod_preffered_aux(int length, vector<int> &p, int n2, vector<int> &pl, vector<int> &r);
int cut_rod_preffered(int length, vector<int> &p, int n2, vector<int> &pl)
{    
    vector<int> r(100); // human indexing
    for(int i = 0; i < 100; i++)
        r[i] = INT_MIN;
    r[0] = 0;
    r[pl[0]] = p[pl[0]];
    for(int i = 1; i < pl[n2-1]; i++)
    {
        if(length < pl[0])
            r[i] = length * (-1);
    }
    return cut_rod_preffered_aux(length, p, n2, pl, r);    
}
int cut_rod_preffered_aux(int length, vector<int> &p, int n2, vector<int> &pl, vector<int> &r)
{
    if(length==0)
        return 0;
    int q;
    if(r[length] >= 0)
        return(r[length]);
    if(length < pl[0])
        return length * (-1);
    q = INT_MIN;
    for(int i = 0; i < n2; i++)
    {
        if(length > pl[i])
            q = max(q, p[pl[i]] + cut_rod_preffered_aux(length - pl[i], p, n2, pl, r));
    }
    r[length] = q;
    return q;
}
int main()
{
    int i, n1, n2, max_profit;
    
    cin >> n1;
    vector<int> p(n1+1, 0);
    for(i = 1; i <= n1; i++)
        cin >> p[i];
        
    cin >> n2;
    vector<int> pl(n2);
    for(i = 0; i < n2; i++)
        cin >> pl[i];
        
    cout << cut_rod_preffered(n1, p, n2, pl);
}
*/