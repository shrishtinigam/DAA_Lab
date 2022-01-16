// 2_alternate_insertion_sort.cpp
#include<iostream>
#include<vector>
using namespace std;

void spaceInsertionSort(vector <int>& elements, int n, int start, int space)
{
    int key, i;
    start++;
    for(int j = start; j < n; j = j + 2)
    {
        key = elements[j];
        i = j - space;
        while((i >= 0) && (elements[i] > key))
        {
            elements[i + space] = elements[i];
            i = i-space;
        }
        elements[i + space] = key;
    }
}
int main()
{
    // sort odd positions and even positions separately
    vector <int> elements(20);
    // cout<<"Enter number of elements";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> elements[i];
    spaceInsertionSort(elements, n, 1, 2);
    spaceInsertionSort(elements, n, 2, 2);
    for(int i = 0; i < n; i++)
        cout << elements[i] <<"\n";
}