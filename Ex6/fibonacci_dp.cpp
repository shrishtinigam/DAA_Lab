#include <iostream>
using namespace std;
#include <vector>
/*
    Top-down approach -> fib x = fib x-1 + fib x-2 .. and so on
    static - to prevent the vector fiba_computed from getting reinitiated each time
    same memory is shared between function calls
*/
long int fiba(int n)
{
    static vector<long int> fiba_computed(100,-1); // creates a static vector of size 100 and initializes all the elements to -1 
    long int c;
    fiba_computed[0] = 0;
    fiba_computed[1] = 1;
    if (fiba_computed[n-1] != -1)
        return fiba_computed[n - 1];
    c = fiba(n - 1) + fiba(n - 2);
    fiba_computed[n - 1] = c; // storing the value in the static vector
    return c;
}
int main()
{
    int n = 1;
    //  Menu-driven
    do{
        if(n <= 0)
            cout << "Invalid input, enter a positive non-zero number, -1 to exit";
        cout << "Enter n to find nth fibonacci number, enter -1 to exit";
        cin >> n;
        if(n > 0)
            cout << fiba(n) << "\n";
    }while(n != -1);
}