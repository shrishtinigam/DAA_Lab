// hw_linear_max_subarray.cpp
/*
Linear Solution for Maximum Sub array Problem
    Develop an algorithm and implement it to solve maximum sum subarray problem in linear 
    time to print the starting index, end index and sum of the subarray whose sum is maximum. 
    Compare the performance of this algorithm with naive algorithm and divide and conquer 
    algorithm for size of inputs 100, 1000, 10000, 50000, 100000, 500000, 1000000. For 
    example, consider an array with 16 elements, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 
    12, -5, -22, 15, -4, 7. Maximum subarray starts at index 8 and ends at index 11 (human 
    indices) and sum is 43

Input Format
    First line contains the number of elements, n
    Next line contains 'n' elements separated by a space

Output Format
    Print the start index, end index and sum of subarray that has got maximum sum

Processing Involved
    Loop - Linear - O(n)

Solution Alternatives
    Brute Force - O(n^3)
    Naïve Approach - O(n^2)
    Divide and Conquer - O(n log n)

Algorithm/Pseudocode
    maxSubarraySum(array arr) 
    max = INT8_MIN
    sum = 0
    n = arr.size()
    begin = 0
    for(i = 0; i < n; i++)
        sum = sum + arr[i]
        if(sum > max)
            max = sum
            low = begin + 1
            high = i + 1
        if(sum < 0)
            sum = 0
            begin = i + 1
    return (low,high,max)
*/

#include <iostream>
#include <limits>
#include <vector>
#include <ctime>
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
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > result.max)
        {
            result.max = sum;
            result.low = begin + 1;
            result.high = i + 1;
        }
        if(sum < 0)
        {
            sum = 0;
            begin = i + 1;
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
    clock_t tStart = clock();
    details answer = maxSubarraySum(a);
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<time1<<endl;
    cout << answer.low << " " << answer.high << " " << answer.max;
}