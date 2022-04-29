#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int is_packing_possible_aux(int n, int m, vector<int>r, vector<int>m_sizes);
bool is_packing_possible(int n, int m, vector<int>m_sizes)
{
    vector <int> r(1000);
    for(int i = 0; i < 1000; i++)
        r[i] = 0;
    r[0] = 0;
    r[m_sizes[0]] = 1;
    if(is_packing_possible_aux(n, m, r, m_sizes) == 1)
        return true;
    return false;
}

int is_packing_possible_aux(int n, int m, vector<int> r ,vector<int>m_sizes)
{
    if(n == 0)
        return true;
    int q;
    if(r[n] == 1)
        return true;
    if(n < m_sizes[0] + 1)
        return false;
    for(int i = 0; i < m; i++)
    {
        if(n > m_sizes[i])
        {
            int q1 = q;
            int q2 = is_packing_possible_aux(n - m_sizes[i], m, r, m_sizes);
            if(q1 == 1 || q2 == 1)
                q = 1;
        }
    }
    r[n] = q;
    return q;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> m_sizes(m);
    for(int i = 0; i < m; i++)
    {
        cin >> m_sizes[i];
    }
    sort(m_sizes.begin(), m_sizes.end());
    
    if(is_packing_possible(n, m, m_sizes))
        cout << "Yes";
    else
        cout << "No";
    //cout << "hello";
    /*for(int i = 0; i < m; i++)
    {
        cout << m_size[i];
    }*/
    
}