/*
Activity Selection using Priority Queue based on Start time
Given a set 'S' of 'n' activities, implement the iterative greedy algorithm to select a subset of activities from S 
by selecting the task that starts last. Build a priority queue (max heap) based on start time and then select the 
activities

Input Format
First line contains the number of activities, n
Next 'n' line contains the details of the activities such as name of activity, start time and finish time

Output Format
Print the name of the activities that are selected separated by a space
*/
#include<iostream>
using namespace std;
#include<queue>
#include<set>
/*11
a3 0 6
a1 1 4
a4 5 7
a2 3 5
a5 3 9
a11 12 16
a6 5 9
a9 8 12
a7 6 10
a8 8 11
a10 2 14
*/
class activity
{
    public:
    string name;
    int start;
    int finish;
    friend istream& operator>>(istream&,activity&);
    friend ostream& operator<<(ostream&,const activity&);
    bool operator<(const activity&) const;
};
istream& operator>>(istream& in, activity& a)
{
    in>>a.name>>a.start>>a.finish;
}
ostream& operator<<(ostream& out, const activity& a)
{
    out<<a.name<<" ";
}
// overload less than operator so that priority queue can be 
// constructed as desired. We intend to create a min priority
// queue based on finish time of activity
bool activity::operator<(const activity& a) const
{
    return a.start>start;
}
void iterative_activity_selector(priority_queue<activity> &pq,vector<activity> &v)
{
    activity a;
    // take activity with maximum start time
    a = pq.top();
    pq.pop();
    // select it and put it in vector
    v.push_back(a);
    
    while(!pq.empty())
    {
        // if finish time of top activity is lesser than start time
        // of current activity then add it to vector and
        // remove top activity from priority queue
        if(pq.top().finish<=a.start)
        {
            a = pq.top();
            v.push_back(a);
        }
        pq.pop();      
        
    }
    
}
int main()
{
    priority_queue<activity> pq;
    int n,i;
    activity a;
    vector<activity> v;
    cin>>n;
    // read input activities and create a priority queue based on
    // finish time 
    for(i=0;i<n;i++)
    {
        cin>>a;
        pq.push(a);
    }
    /////////////// BLOCK 1 //////////////////
    /*while(!pq.empty())
    {
        a = pq.top();
        pq.pop();
        cout<<a<<" ";
    }*/
    ///////////////// BLOCK 1 //////////////////////

    //////////////// BLOCK 2 //////////////////////
    // call recursive function to select activities from
    // the constructed priority queue and pass the vector
    // to store selected vector
    iterative_activity_selector(pq,v);
    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    //////////////// BLOCK 2 //////////////////////
}