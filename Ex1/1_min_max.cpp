#include<iostream>
#include<array>
using namespace std;

int main() 
{
    int i, n, min, max;
    array <int, 20> a;
    cin >> n;
    cout << "Enter elements";
    for (i = 0; i < n; i++)
        cin >> a[i];
    min = a[0];
    max = a[0];
    for (i = 1; i < n; i++) 
	{
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << "Minimum is " << min << endl;
    cout << "Max is " << max << endl;
}