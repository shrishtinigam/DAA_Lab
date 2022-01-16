#include<iostream>
#include<vector>
using namespace std;
// elements a and b are passed by reference
void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void bubble_sort_optimized(int elements[],int n)
{
    int flag;
	do{
	    flag = 0;
    	for(int i = 0; i < n - 1; i++)
    	{
    		if(elements[i] > elements[i + 1])
    		{
    			  swap(elements[i], elements[i + 1]);
    			  flag++;
    		}
    	}
    	n--; // to remove unneccessary comparisions towards the end
	}while(flag != 0);
}

/* Along with exiting once the list is sorted, the value of n decreases every 
iteration (by 1). This is because after a pass, the largest element of the pass 
is moved to the last and we don't need to check for swaps there.*/

int main()
{
	vector <int> elements;
	int i, j, n,e;
	cin>>n;
	for(i = 0; i < n; i++)
	{
		cin >> e;
		elements.push_back(e);	
	}
	bubble_sort_optimized(elements.data(),n);
	for(auto it = elements.begin(); it!=elements.end(); it++)
		cout << *it << " ";
}