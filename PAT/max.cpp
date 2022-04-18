// finding maximum element in an array
// 5 23 12 56 9 71
// 5 71 23 12 56 9
// 5 7 8 3 1 5 
// 5 7 3 8 5 1
// 5 5 1 7 8 3
#include<iostream>
using namespace std;
#include<vector>
int max(vector<int> elements,int l, int h)
{
    int mid,left,right;
    if(l==h)
        return elements[l];
    mid = (l+h)/2;
    left = max(elements,0,mid);
    right = max(elements,mid+1,h);
    return left>right?left:right;
}
int main()
{
    int i,n,ele;
    vector<int> elements;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    cout<<max(elements,0,n-1);
}