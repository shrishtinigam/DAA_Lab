/*
Merge by Inserting
Merge by Inserting is a variation of merge sort in which we make change in the merge part of merge sort. 
The right part of the array is inserted into the left part of the array. That is the elements in the right 
part of the array has to be inserted into the sorted array which is the left part of the array

For example, consider an array of elements with first four elements as left part and second four elements 
as right part. Left part and right part are sorted by themselves. In the merge step, insert the elements 
one by one in the right part into the left part. The left part will keep on increasing in length and will 
become whole array at the end. Consider the elements 1, 4, 7, 12, 2, 5, 8, 14.

Left part consist of 1, 4, 7, 12

Right part consist of 2, 5, 8, 14

Insert 2 into sorted left part, then 5, 8 and 14

1. Analyse the time complexity of this variant of merge sort and make a note in the algorithm part

2. Run the code (in your laptop) for different input sizes like 100, 200, ....,  and plot a graph for the time 
taken by the algorithm

Input Format

First line contains the number of elements to be sorted, n

Next line contain the 'n' elements to be sorted (separated by a space)

Output Format

Print the 'n' elements in ascending order
*/
#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
void merge(vector<int> &elements, int left, int mid, int right)
{	
    //insert the elements in the right part into the left part
    vector<int> Sub_Array;
    int no_Left_Sub, no_Right_Sub, index_Full_Array;
	no_Left_Sub = mid-left+1;
	no_Right_Sub = right-mid;
	// make a copy of left sub array in a temporary array
	for(int i=0;i<no_Left_Sub;i++)
		Sub_Array.push_back(elements[left+i]);
    	// Position the indices for the three arrays rightly
    // Here we perform insertion. We find the appropriate position for each element of the right subarray in the left subarray and insert it.
    // Here at first we have the sorted left subarray.
    int j = 0;
    for(int i = 0; i < no_Right_Sub; i++)
    {
        int key = elements[mid+i+1];
        while(j <= right-left && elements[j] < key)
        {
            j++;
        }
        Sub_Array.push_back(0);
        for(int k = Sub_Array.size(); k> j; k--)
            Sub_Array[k] = Sub_Array[k - 1];
        Sub_Array[j] = key;
    }
    int count = 0;
    
    for(int i = left; i < Sub_Array.size(); i++)
    {
        cout << Sub_Array[count] << " ";
        elements[i] = Sub_Array[count];
        count++;
    }
    cout << "\n";
}
void mergesort(vector<int> &elements, int left, int right)
{
	int mid;
	// When there is only one element in the array
	if(left==right)
		return;
	// Find mid of the array
	mid = (left+right)/2;
	// call mergesort for left subarray
	mergesort(elements,left,mid);
	// call mergesort for right subarray
	mergesort(elements,mid+1,right);
	// merge the sorted left and right subarray
	merge(elements,left,mid,right);
}
int main()
{
	int n,i,ele;
	vector<int> elements;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}
	clock_t tStart = clock();
	mergesort(elements, 0, n-1);
    merge(elements,0, n/2, n-1);
    merge(elements,0, n/2, n-1);
    merge(elements,0, n/2, n-1);
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	//cout<<"Time taken is "<<time1<<endl;
	for(i=0;i<n;i++)
	{
		cout<<elements[i]<<" ";
	}
}