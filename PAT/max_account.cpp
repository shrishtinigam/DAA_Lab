// finding maximum element in an array
// 5 23 12 56 9 71
// 5 71 23 12 56 9
// 5 7 8 3 1 5 
// 5 7 3 8 5 1
// 5 5 1 7 8 3
#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class investment
{
    float principal;
    float rate;
    float num_years;
    public:
    friend istream& operator>>(istream&,investment&);
    friend ostream& operator<<(ostream&, investment&);
    bool operator>(investment);
    float calc_interest();
};
istream& operator>>(istream& in,investment& i)
{
    in>>i.principal>>i.rate>>i.num_years;
}
ostream& operator<<(ostream& out, investment& i)
{
    cout<<i.principal<<" "<<i.rate<<" "<<i.num_years<<endl;
}
float investment::calc_interest()
{
    return sqrt(principal*num_years*rate);
}
bool investment::operator>(investment i)
{
    return calc_interest()>i.calc_interest();
}
investment max(vector<investment> elements,int l, int h)
{
    int mid;
    investment left,right;
    if(l==h)
        return elements[l];
    mid = (l+h)/2;
    left = max(elements,0,mid);
    right = max(elements,mid+1,h);
    return left>right?left:right;
}
int main()
{
    int i,n;
    investment ele,ret;
    vector<investment> elements;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    ret = max(elements,0,n-1);
    cout<<ret;
}