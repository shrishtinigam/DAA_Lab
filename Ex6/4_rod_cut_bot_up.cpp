// 4_rod_cut_bot_up.cpp
#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <algorithm>
int bottom_up_cut_rod(vector<int> &p, int length)
{    
    vector <int> r(100,0);
    int i, q, j;
    r[0] = 0;
    for (j = 1; j <= length; j++)
    {
        q = INT_MIN;
        for(i = 1; i <= j; i++)
        {
            q = max(q, p[i - 1] + r[j - i]);
        }
        r[j] = q;
    }
    return r[length];
}

int main()
{
    int i, n, price, max_profit;
    cin >> n;
    vector <int> p(n);
    for(i = 0; i < n; i++)
        cin >> p[i];
    max_profit = bottom_up_cut_rod(p, n);
    cout << max_profit;
}