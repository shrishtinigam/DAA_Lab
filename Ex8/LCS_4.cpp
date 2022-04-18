#include <iostream>
#include <vector>
using namespace std;
int lcs(string& s1, string& s2){
    int m = s1.length()+1;
    int n = s1.length()+1;
    vector<vector<int>> c(m, vector<int>(n, 0));
    for(int i = 1; i< m; i++){
        for(int j = 1; j< n; j++){
            if(s1[i-1] == s2[j-1]){
                c[1][j] = c[0][j-1]+1;
                
            }
            else if(c[0][j] > c[1][j-1]){
                c[1][j] = c[0][j];
                
            }else{
                c[1][j] = c[1][j-1];}
            
        }
        c[0] = c[1];
        
    }
    return c[0][n-1];
    
}int main()
{   
    string s1, s2;
    cin >> s1 >> s2;
    int length = lcs(s1, s2);
    cout << length << endl;
    return 0;
}