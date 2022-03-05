/*
    Max Distance Point from Origin
    Given a set of points, write a divide and conquer algorithm to find the point that has maximum distance from the origin. 
    distance of a point from origin = √x*x + y*y 

    Input Format
    First line contains the number of points, n
    Next 'n' lines contains x and y coordinate of the 'n' points

    Output Format
    First line print the x-coordinate of point at maximum distance from origin
    Next line print the y-coordinate of point at maximum distance from origin

    Input
        3
        1 2
        3 4
        5 6
    Output
        5 6
    Processing Involved
        Recursion
        Divide and Conquer

    Solution Alternatives
        Iterative method

    Algorithm/ Pseudocode
        DISTANCE(point p)
            return sqr((p.x) ^ 2 + (p.y) ^ 2)

        MAX( list of points elements, i, j)
            mid_index = i + (j - i)/2  // to prevent overflow

            mid = DISTANCE(elements[mid_index])
            if( i < j )
                left = MAX(elements, 0, mid_index)
                right = MAX(elements, mid_index + 1, j)
            else
                return elements[mid_index]

            l_dist = DISTANCE(left)
            r_dist = DISTANCE(right)
            max_dist = max(mid, l_dist)
            max_dist = max(max_dist, r_dist)
            
            if(max_dist == l_dist)
                return left
            else if(max_dist == r_dist)
                return right
            return elements[mid_index]
 
*/

#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class point
{
    int x;
    int y;
// complete class point declaration here
    public:

    friend istream& operator >> (istream&, point&);
    friend ostream& operator << (ostream&, point&);

    int distance()
    {
        return sqrt((pow(x,2)) + ((pow(y,2))));
    }
};

istream& operator>>(istream& in,point& i)
{
    in >> i.x >> i.y;
}
ostream& operator<<(ostream& out, point& i)
{
    cout << i.x << " " << i.y << endl;
}

// write defintion of other member functions and max divide and conquer function here

point max(vector <point> elements, int i, int j)
{
    int max_dist;
    int mid_index = i + (j - i)/2; // finding the mid element in the vector

    int mid = elements[mid_index].distance(); // find distance of mid ele from origin
    
    point left, right;
    if(i < j)
    {
        left = max(elements, 0, mid_index); // search in left half
        right = max(elements, mid_index + 1, j); // search in right half
    }
    else
        return elements[mid_index]; // if i >= j, return mid element as no left/right vector half to search
    
    int l_dist = left.distance(); 
    int r_dist = right.distance();
    
    // finding which is max, left max, right max or current mid element
    max_dist = max(mid, l_dist);
    max_dist = max(max_dist, r_dist);
    
    // return whichever is max distance from origin
    if(max_dist == l_dist)
        return left;
    else if(max_dist == r_dist)
        return right;
    return elements[mid_index];
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