/*
Stream of data storage and removal
A stream of data enters into a storage and end of stream is indicated by 0. Whenever a negative value enters
(i) Do not store it
(ii) Take absolute value of the negative value and let it be 'p'
(iii) Choose 'p' values from storage, remove them from storage and print it so that sum of the elements printed is maximum
Design an algorithm to solve the problem, choose an appropriate data structure so that the time complexity of the algorithm is less. For example, if the stream of data is 5, 10, 8, 12, 9, -2, 6, 54, 31, -4, 15, 22, 34, 17, -3, 41, 0 then print  12, 10, 54, 31, 9, 8, 34, 22, 17.

Input Format

A sequence of integers are given, one number in one line and the sequence ends with 0

Output Format

Print numbers separated by a space. Choose numbers such that sum of numbers printed will be maximum

Input
5 10 8 12 -2 7 39 27 94 28 3 -3 0
Output
12 10 94 39 28
Processing Involved
Max heap form of priority queue
Solution Alternatives
1) Repetitive Sorting 
2) Inserting every new element in its sorted position in an array
Algorithm/ Pseudocode
DATA-STREAM(data)
     let pq be priority-queue of integers
     for i = 0 to data.length
          if(data[i] > 0)
               pq.push(data[i])
          else if(data[i] < 0)
               for j = 0 to abs(data[i])
                    print(pq.pop)
          else 
                break
Font Size
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n(1000), x;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x > 0)
            pq.push(x);
        else if(x < 0)
        {
            int x_abs = x*(-1);
            for(int j = 0; j < x_abs; j++)
            {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
        else
            break;
    }
}