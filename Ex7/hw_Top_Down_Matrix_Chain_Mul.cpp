/*  hw_Top_Down_Matrix_Chain_Mul.cpp
    Matrix Chain Multiplication Top Down
    Develop a top down dynamic programming algorithm to find minimum cost for matrix 
    chain multiplication. Print the tables maintained by the algorithm. For example, 
    when there are six matrices and the input given is 
    7
    30 35 15 5 10 20 25

    M table should be printed as 
    15750 7875 9375 11875 15125 
    2625 4375 7125 10500 
    750 2500 5375 
    1000 3500 
    5000 

    S table should be printed as 
    1 1 3 3 3 
    2 3 3 3 
    3 3 3 
    4 5 
    5 

    Input Format
    First line contains the number of matrices +1, n
    Next line contains the dimensions of the matrices in the chain

    Output Format
    Print the mtable
    Print the s table
    Print the minimum cost

    Input
    5
    23 42 12 4 5

    Output
    11592 5880 6340 
    2016 2760
    240
    1 1 3
    2 2
    3
    6340

    Processing Involved
    Top Down DP
    Recursion

    Solution Alternatives
    Bottom Up DP
    Recursion (without DP)

    Algorithm/ Pseudocode
    matrix_chain_order(p, m, s)
        return matrix_chain_order_aux(1, p.size() - 1, p, m, s)

    matrix_chain_order_aux(i, j, p, m, s)
        min_cost = INT_MAX
        if(i == j)
            return 0
        if(m[i - 1][j - 1] != 0)
            return m[i - 1][j - 1]
        for k = i to j
            left_cost = matrix_chain_order_aux(i, k, p, m, s)
            right_cost = matrix_chain_order_aux(k + 1, j, p, m, s)
            total_cost = left_cost + right_cost + p[i - 1] * p[k] * p[j]
            if(total_cost < min_cost)
                min_cost = total_cost
                min_k = k
        m[i - 1][j - 1] = min_cost
        s[i - 1][j - 1] = min_k
        return min_cost
*/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>
int matrix_chain_order_aux(int i, int j, vector<int> p, vector<vector<int>>& m, vector<vector<int> >& s);
int matrix_chain_order(vector<int> p, vector<vector<int>>& m, vector<vector<int> >& s)
{
     return matrix_chain_order_aux(1, p.size() - 1, p, m, s);
}

int matrix_chain_order_aux(int i, int j, vector<int> p, vector<vector<int>>& m, vector<vector<int> >& s)
{
    int min_cost = INT_MAX, k, left_cost, right_cost, total_cost, min_k;    
    if(i == j)
        return 0;
    if(m[i - 1][j - 1] != 0)
        return m[i - 1][j - 1];
    for(k = i; k < j; k++)
    {       
        left_cost = matrix_chain_order_aux(i, k, p, m, s);
        right_cost = matrix_chain_order_aux(k + 1, j, p, m, s);
        total_cost = left_cost + right_cost + p[i - 1] * p[k] * p[j];

        if(total_cost < min_cost)
        {
            min_cost = total_cost;
            min_k = k;
        }
        
    }
    m[i - 1][j - 1] = min_cost;
    s[i - 1][j - 1] = min_k;
    return min_cost;
}
/*
void print_Optimal_Parens(vector<vector<int> >& s, int i, int j)
{
    if(i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_Optimal_Parens(s, i, s[i - 1][j - 1]);
        print_Optimal_Parens(s, s[i - 1][j - 1] + 1, j);
        cout << ")";
    }
}*/
int main()
{    
    int n, i, j;
    cin >> n;
    vector <int> p(n);
    for(i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<int>> m(n - 1, vector<int>(n - 1, 0));
    vector<vector<int>> s(n - 1, vector<int>(n - 1, 0));
    int answer = matrix_chain_order(p, m, s);
    for(i = 0; i < n - 2; i++)
    {
        for(j =  1; j < n - 1; j++)
        {
            if(m[i][j] != 0)
                cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(i = 0 ; i < n - 2; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(m[i][j] != 0)
                cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << answer;
    // cout << m[0][n - 2] << endl; -> also works
    // print_Optimal_Parens(s, 1, n - 1);
}