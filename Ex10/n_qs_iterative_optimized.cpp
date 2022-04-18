// See Theory_Class_Code/back_tracking/NQueens for python version
// Optimized not_attacking function to only check required places

#include<iostream>
using namespace std;
#include<vector>
#include<stack>
void print_board(vector<vector<int> > board)
{
    int n,i,j;
    static int count = 1;
    n = board.size();
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "Completed " << count++ << endl;
}