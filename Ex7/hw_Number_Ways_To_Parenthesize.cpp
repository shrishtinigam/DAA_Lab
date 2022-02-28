/*  hw_Number_Ways_To_Parenthesize.cpp
    Number of ways to parenthesize
    In matrix chain multiplication problem, given the number of matrices to be multiplied, 
    write a C++ program to find the number of ways it may be parenthesized. For example, 
    when there are three matrices A1, A2 and A3 there are two ways to parenthesize them. 
    (A1(A2A3)) and ((A1A2)A3). If there are four matrices A1, A2, A3 and A4 then there are 
    five ways to parenthesize as shown (A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), 
    ((A1(A2A3))A4), (((A1A2)A3)A4).

    Input Format
    First line contains the number of matrices in the chain, n

    Output Format
    Print the possible number of parenthesization

    Input
    8

    Output
    429

    Processing Involved
    Recursion

    Solution Alternatives
    DP

    Algorithm/ Pseudocode
    no_of_ways(n)
    sum = 0
    if n = 1
        return 1
    for i = 0 to n
        sum += no_of_ways(i) * no_of_ways(n - i)
    return sum
*/

#include <iostream>
#include <cmath>
using namespace std;

long int no_of_ways(long int n)
{
    long int sum = 0;
    if(n == 1)
        return 1;
    for(long int i = 1; i < n; i++)
        sum += no_of_ways(i) * no_of_ways(n - i);
    return sum;
}

int main()
{
    long n;
    cin >> n;
    cout << no_of_ways(n);
}