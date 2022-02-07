// hw_longest_max_subarray.cpp
/*
Maximum sub array with maximum length
    Given an array of positive and negative numbers, develop a linear algorithm and 
    write a C++ code to print the start index, end index and sum of subarray which is 
    having maximum sum and maximum length. Consider an array with 13 elements 4, -12, 3, 
    10, 4, 5, -100, 6, 7, 1, 3, 1, 4. There are two subarrays having sum as 22, that is 
    starting at 2 and ending at 5 with elements 3, 10, 4, 5 and another subarray that 
    starts at 8 and end at 13 with elements 6, 7, 1, 3, 1, 4

Input Format
    First line contains the number of elements in array, n
    Next line contains the elements in the array separated by a space

Output Format
    Print the start index, end index and sum of array having maximum sum and having 
    maximum number of elements

Processing Involved
    Loop - Linear - O(n)

Solution Alternatives
    Brute Force - O(n^3)
    Naïve Approach - O(n^2)
    Divide and Conquer - O(n log n)

Algorithm/ Pseudocode
    maxSubarraySum(array arr)
    max = INT8_MIN
    sum = 0
    n = arr.size
    begin = 0
    len = 0
    for(int i = 0; i < n; i++)
        sum = sum + arr[i]
        if(sum < 0)
            sum = 0
            begin = i + 1
        else if(sum >= max)
            n = i - begin
            if(n > len) // to ensure the result is longest max subarray
                len = n
                max = sum
                low = begin + 1
                high = i + 1
    return (max,low,high)    
*/
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct details
{
    int low;
    int high;
    int max;
};

details maxSubarraySum(vector <int> arr)
{ 
    details result;
    int max = INT8_MIN;
    int sum = 0;
    int n = arr.size();
    int begin = 0;
    int len = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum < 0)
        {
            sum = 0;
            begin = i + 1;
        }
        else if(sum >= result.max)
        {
            int n = i - begin;
            if(n > len)
            {
                len = n;
                result.max = sum;
                result.low = begin + 1;
                result.high = i + 1;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    details answer = maxSubarraySum(a);
    cout << answer.low << " " << answer.high << " " << answer.max;
}