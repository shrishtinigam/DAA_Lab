/*  hw_My_Fibonacci_Term.cpp
    My Fibanocci Term
    MyFibonacci series is one which is defined as follows: 

    fiba(1) = 0
    fiba(2) = 1
    fiba(3) = 2
    fiba(n) = fiba(n-1) + fiba(n-2) + fiba(n-3)

    Given value of 'n', use top-down dynamic programming to find fiba(n).

    Input Format
    First line contains the value of 'n'

    Output Format
    Print the nth term in My Fibanocci series

    Input
    Any number n, ex: 25

    Output
    1166220

    Processing Involved
    Recursion, Dynamic Programming, Static Vectors

    Solution Alternatives
    Recursion without DP, 
    Iterative method

    Algorithm/Pseudocode
    fiba(n)
    static array fiba_computed(100,-1)  // static vector of size 100, initialized all the elements to -1
    fiba_computed[0] = 0
    fiba_computed[1] = 1
    fiba_computed[2] = 2
    if (fiba_computed[n-1] != -1)
        return fiba_computed[n - 1]
    c = fiba(n - 1) + fiba(n - 2) + fiba(n - 3)
    fiba_computed[n - 1] = c  // storing the value in the static vector
    return c
*/

#include <iostream>
using namespace std;
#include <vector>
/*
    Top-down approach -> fib x = fib x-1 + fib x-2 + fib x-3 .. and so on
    static - to prevent the vector fiba_computed from getting reinitiated each time
    same memory is shared between function calls
*/
long int fiba(int n)
{
    static vector<long int> fiba_computed(100,-1); // creates a static vector of size 100 and initializes all the elements to -1 
    long int c;
    fiba_computed[0] = 0;
    fiba_computed[1] = 1;
    fiba_computed[2] = 2;
    if (fiba_computed[n-1] != -1)
        return fiba_computed[n - 1];
    c = fiba(n - 1) + fiba(n - 2) + fiba(n - 3);
    fiba_computed[n - 1] = c; // storing the value in the static vector
    return c;
}
int main()
{
    int n;
    cin >> n;
    cout << fiba(n) << "\n";
}