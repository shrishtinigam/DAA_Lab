// Print the distance to the vertices away by two from a given source
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int V;
    cin >> V;
    int adj[V][V];
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> adj[i][j];
        }
    }
    int S;
    cin >> S;
    vector <int> level_1;
    for(int i = 0; i < V; i++)
    {
        if(adj[S][i] > 0)
        {
            level_1.push_back(i);
        }
    }
    
    for(int i = 0; i < level_1.size(); i++)
    {
        for(int j = 0; j < V; j++)
        {
            vector <int> x;
            if(adj[level_1[i]][j] > 0 && j != S)
            {
                cout << j << " ";
                cout << adj[S][level_1[i]] + adj[level_1[i]][j] << "\n";
            }
        }
    }
}