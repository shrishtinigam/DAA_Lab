/*
    hw_Cut_Into_3_5.cpp
    Cut into lengths 3 or 5
    A variation of rod cutting problem is one in which length of the rod will be of length 
    greater than or equal to 8 and you can make cuts of rods of length 3 or 5 only. For each 
    unit of wastage a penalty of Rs.1 should be given. Write an recursive algorithm and implement 
    it to find the maximum revenue that may be generated.

    Input Format
    First line contains the length of the rod,n
    Next line contains the price of rod of length 3 and 5 separated by a space

    Output Format
    Prin the maximum revenue that may be generated

    Input
    24 1 5

    Output
    20

    Processing Involved
    Recursion, Memoization, Dynamic Programming

    Solution Alternatives
    Recursion without DP

    Algorithm/ Pseudocode
    cutrod_3_5(length, p3, p5)
        let r[0...100] be an array with all elements -1 
        let r[0] = 0 (human indexing)
        Assuming price will always be positive - 
        r[3] = p3; 
        r[5] = max(p5, r[3] - 2)
        // r table initialization - first 7 numbers here
        // This can be directly initialized too, (this code can be reused for different lengths)
        for i = 0 to 7
            if(i < 3)
                r[i] = i*(-1)
            if(i > 3 and i < 5)
                r[i] = r[3] + (i - 3) * (-1)
            if(i > 5)
                r[i] = max(2*r[3] + ( (i-6)*(-1)), r[5] + ((i-5)*(-1)))  -> either 3,3 + extra or 5 + extraa
        return cutrod_3_5_aux(r, length);

    cutrod_3_5_aux(r, length)
        if(length < 8 or r[length] > 0)
            return r[length]
        // We can either cut into 3 + (l - 3) or 5 + (l - 5). We choose the max out of them
        q = max(r[3] + cutrod_3_5_aux(r, length - 3), r[5] + cutrod_3_5_aux(r, length - 5))
        r[length] = q
        return q
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int cutrod_3_5_aux(vector<int> &r, int length);
int cutrod_3_5(int length, int p3, int p5)
{
    vector <int> r(100, -1); 
    // lets consider r[0] = 0 (human indexing)
    r[0] = 0; 
    // Assuming price will always be positive
    r[3] = p3; 
    r[5] = max(p5, r[3] + (5-3)*(-1));
    
    // r table initialization - first 7 numbers here
    // This can be directly initialized too
    for(int i = 1; i < 8; i++)
    {
        if(i < 3)
            r[i] = i*(-1);
        if(i > 3 && i < 5)
            r[i] = r[3] + (i - 3) * (-1);
        if(i > 5)
            r[i] = max(2*r[3] + ( (i-(2*3))*(-1) ), r[5] + ( (i-5)*(-1) ));
    }
    return cutrod_3_5_aux(r, length);
}
int cutrod_3_5_aux(vector<int> &r, int length)
{
    if(length < 8 || r[length] > 0)
        return r[length];
    // We can either cut into 3 + (l - 3) or 5 + (l - 5). We choose the max out of them
    int q = max(r[3] + cutrod_3_5_aux(r, length - 3), r[5] + cutrod_3_5_aux(r, length - 5));
    r[length] = q;
    return q;
}
int main()
{
    int i, n, p3, p5, max_profit;
    cin >> n >> p3 >> p5;
    cout << cutrod_3_5(n, p3, p5);
}