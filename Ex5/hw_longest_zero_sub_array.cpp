// hw_longest_zero_sub_array.cpp
/*
Zero sum subarray
    Given an array of positive and negative integers, develop a linear algorithm and write a C++ code to check 
    if there exist a subarray whose sum is zero is present in it. If such a subarray exist then print start and 
    end index of first occurrence. Otherwise print -1 for both start and end index. For example, if the array 
    contains seven elements 10, -3, 2,4, -3, 5, 7 then print start index as 2 and end index as 5

    Hint: Use maps for keeping track of sums 

    Note: If more than one zero sum subarray exist then print the one which has got maximum length

Input Format
    First line contains the number of elements in the array, n
    Next line contains the elements separated by a space

Output Format
    Either print start index and end index of subarray whose sum becomes 0 or print -1 if no such subarray exist

Processing Involved
    Loop - Linear - O(n)

Solution Alternatives
    Brute Force - O(n^3)
    Naïve Approach - O(n^2)
    Divide and Conquer - O(n log n)

Algorithm/ Pseudocode

    find_zero_sum(array elements)
        map sum_index;
        i = 0
        sum = 0;
        n = elements.size()
        low = -1
        high = -1
        len = 0
        sum_index[0] = 0
        for(i = 0; i < n; i++)
            sum = sum + elements[i]
            if sum is present in map
                int n = i - sum_index[sum]
                if(n > len) // to ensure the result is longest subarray
                    len = n
                    low = sum_index[sum] + 1
                    high = i + 1
            else
                sum_index[sum] = i + 1
            return (low, high)
*/
#include<iostream>
using namespace std;
#include<vector>
#include<map>
struct details
{
    int low;
    int high;
};
details find_zero_sum(vector<int> elements)
{
    map<int,int> sum_index;
    int i, n, sum = 0;
    details d;
    n = elements.size();
    d.low = -1;
    d.high = -1;
    int len = 0;
    sum_index[0] = 0;
    for(i = 0; i < n; i++)
    {
        sum = sum + elements[i];
        if(sum_index.find(sum) != sum_index.end()) // if sum is present
        {
            int n = i - sum_index[sum];
            if(n > len)
            {
                len = n;
                d.low = sum_index[sum] + 1;
                d.high = i + 1;
            }
        }        
        else
            sum_index[sum] = i + 1;
    }       
        return d;   
}
int main()
{
    vector <int> elements;
    int n, ele, i;
    details d;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> ele;
        elements.push_back(ele);
    }
    d = find_zero_sum(elements);
    if(d.low == -1)
        cout << -1;
    else
        cout << d.low << " " << d.high << endl; // 1 based indexing
}