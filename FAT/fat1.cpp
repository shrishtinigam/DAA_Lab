/*Eliminate Common Previous Difference
A function prev_Difference is defined as follows:

prev_Difference(n, i) = ith digit of n - (i-1)th digit of n

all_prev_Difference is a function which takes a number n as input and find all possible, prev_Difference of n that is for values of i = 2 to len(n). 
if n1 is 378219 and n2 is 480107,
all_Prev_Difference(n1) = 4, 1, -6, -1, 8  
all_Prev_Difference(n2) = 4, -8, 1, -1, 7 

common_Prev_Diff_In_Order(n1, n2) - Previous differences of maximum length common in both n1 and n2 and in same order (i.e.) the elements in common_Prev_Diff_In_Order(n1, n2) is obtained by deleting elements  in all_Prev_Difference(n1) that are not present in all_Prev_Difference(n2) and order of no element in all_Prev_Difference is changed

For the above example, common_Prev_Diff_In_Order(n1, n2) = 4, 1, -1

remove_common_differences(n1, n2) - remove all ith digit from n1 if prev_Difference(n, i) is in common_Prev_Diff_In_Order(n1, n2), for the example given remove_common_differences(n1, n2) will be 329

Given two numbers n1 and n2 write a C++ program to find remove_common_differences(n1, n2).
Boundary conditions
0 <= num1 <=1020
0 <= num2 <=1020
Note: No two previous differences will be same in either num1 or num2

Input Format
First line contains the number, num1
Next line contains the number, num2

Output Format
Print the number obtained after remove_common_differences
*/




#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
vector <int> all_prev_difference(int n)
{
    // convert number into vector
    vector<int> ans;
    while(n > 0)
    {
        int x = n%10;
        n = (n - n%10)/10;
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    
    vector <int> ans2;
    for(int i = 1; i < ans.size(); i++)
    {
        ans2.push_back(ans[i] - ans[i-1]);
    }
    return ans2;
}

// Finding Longest Common Subsequence Using Top Down DP
vector<int>lcs_length(vector<int> n1, vector<int> n2, vector<vector<int>> &c, vector<vector<char>> &b)
{
    int m = n1.size(), n = n2.size();
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(n1[i-1] == n2[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'd';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'b';
            }
        }
    }
    
    
    

}

void print_lcs(vector <vector<char>> &b, vector <int> n1, int i, int j, vector <int> & ans)
{
    if(i==0 || j==0)
        return;
    if(b[i][j] == 'd')
    {
        print_lcs(b, n1, i-1, j-1, ans);
        cout << n1[i-1];
        ans.push_back(n1[i-1]);
    }
    else if(b[i][j] == 'u')
        print_lcs(b,n1,i-1,j, ans);
    else
        print_lcs(b, n1, i, j - 1, ans);
}

vector <int> remove_common_difference()
{
    
}


int main()
{
    int num_1, num_2;
    cin >> num_1 >> num_2;
    vector<int> n1 = all_prev_difference(num_1);
    vector<int> n2 = all_prev_difference(num_2);
    vector <vector<int>> c(n1.size() + 1, vector<int>(n2.size() + 1, 0));
    vector <vector<char>> b(n1.size() + 1,vector<char>(n2.size()+1,' '));
    lcs_length(n1,n2,c,b);
    vector <int> ans;
    cout << n1.size();
    print_lcs(b,n1,n1.size(),n2.size() - 1, ans);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}