/*
    Binary Search -
    We have to return the location where the required element is to be placed. 
    Normally in binary search, for the end < start condition, we return -1, indicating 
    the required element was not found. 
    But here when we reach this condition, it means the new element is to be added at 
    start or start + 1. If the element is found in the array, then we simply insert it 
    next to that element. 

    We only search in the sorted part of the array.

    binary_search_pos(int *elements, int low, int high, int s)
    1: find mid, mid = (high + low) /2
    2: if high < low
    3.       if s > elements[low]
    4.            return low + 1
    5.       return low
    6. if s == elements[mid]  // element already in array
    7.      return mid + 1 
    8. else if s < elements[mid]
    9.      return binary_search_pos(elements, low, mid - 1, s)
    10. return binary_search_pos(elements, mid + 1, high, s)

    Insertion Sort -
    In regular insertion sort, we have an inner while loop with runs till elements[i] > key. 
    This, in the worst case, an O(n) operation. Instead, we use binary search to directly find 
    the required position, reducing the time complexity of this operation to O(log n).
*/

#include<iostream>
#include<vector>
using namespace std;
int binary_search_pos(int *elements, int low, int high, int s)
{
	int mid;
	mid = (low + high) / 2;
    if(high < low)
	{
	    if(s > elements[low])
	        return low + 1;
	   return low;
	}
	if(s == elements[mid])
		return mid + 1;
	else if(s < elements[mid])
		return binary_search_pos(elements, low, mid - 1, s);
	return binary_search_pos(elements, mid + 1, high, s);
}
int main()
{
    int key, i, j, n, pos;
    cin >> n;
    int elements[n];
    for(i = 0; i < n; i++)
        cin >> elements[i];
    for(j = 1; j < n; j++)
    {
        pos = binary_search_pos(elements, 0, j - 1, elements[j]);
        i = j - 1;
        key = elements[j];
        while(i >= pos)
        {	
            elements[i + 1] = elements[i];
            i = i-1;
        }
        elements[i + 1] = key;
    }

   for(i = 0; i < n; i++)
    {
        cout << elements[i] << " ";
    }
}