#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class components
{
    float ticket;
    float food;
    float luggage;
    public:
    friend istream& operator>>(istream&,components&);
    friend ostream& operator<<(ostream&, components&);
    bool operator>(components);
    float calc_cost();
};
istream& operator>>(istream& in,components& i)
{
    in>>i.ticket>>i.food>>i.luggage;
}
ostream& operator<<(ostream& out, components& i)
{
    cout<<i.ticket<<" "<<i.food<<" "<<i.luggage<<endl;
}
float components::calc_cost()
{
    return ticket+food+sqrt(luggage);
}
bool components::operator>(components i)
{
    return calc_cost()>i.calc_cost();
}
components max(vector<components> elements,int l, int h)
{
    int mid;
    components left,right;
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
    components ele,ret;
    vector<components> elements;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    for(i=0;i<n;i++)
        cout<<elements[i].calc_cost()<<" ";
    ret = max(elements,0,n-1);
    cout<<ret;
}