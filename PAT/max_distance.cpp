
#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class point
{
    int x;
    int y;
    
    public:
    friend istream& operator>>(istream&,point&);
    friend ostream& operator<<(ostream&, point&);
    bool operator>(point);
    float calc_dis_origin();
};
istream& operator>>(istream& in,point& i)
{
    in>>i.x>>i.y;
}
ostream& operator<<(ostream& out, point& i)
{
    cout<<i.x<<" "<<i.y<<endl;
}
float point::calc_dis_origin()
{
    return sqrt(x*x+y*y);
}
bool point::operator>(point i)
{
    return calc_dis_origin()>i.calc_dis_origin();
}
point max(vector<point> elements,int l, int h)
{
    int mid;
    point left,right;
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
    point ele,ret;
    vector<point> elements;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    ret = max(elements,0,n-1);
    cout<<ret;
}
