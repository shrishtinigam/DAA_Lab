// hw_Conventional_Matrix_Addition.cpp
/*
Convential Matrix Addition
Write a C++ program to do matrix addition. Use vectors of STL to represent matrices. Understand the precode and postcode given to complete the rest of the code

Reference Code and Code for Dataset generation is present in

https://github.com/janakimeena/DAA_Winter_22/tree/main/Ex4_ch

Generate dataset of different sizes from 2^1 to 2^13 and make a plot of time taken to execute the code

Input Format

First line contains the number of rows and columns in the input square matrices, n

Next line contains the elements of first input matrix

Next line cotains the elements of second input matrix

Output Format

Print the resultant matrix with one row in one line

matrix_add(matrix m1, matrix m2, matrix m3)
    rows = m1.size()
    cols = m1[0].size()
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            m3[i][j] = m1[i][j] + m2[i][j]

With the conventional method of matrix addition we can add two matrices of any dimensions, 
as long they are same. The time complexity is O(n^2) or O(m x n) where m is rows and n is 
columns. 

https://github.com/shrishtinigam/DAA_Lab/tree/main/Ex4_ch/Matrix_Addition

*/
#include<iostream>
using namespace std;
#include<vector>
void read_matrix(vector<vector<int> > &mat,int n)
{
    int i,j,ele;
    for(i=0;i<n;i++)
    {
        vector<int> row;
        for(j=0;j<n;j++)
        {
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
}
void matrix_add(vector<vector<int>> &m1, vector<vector<int>> &m2, vector<vector<int>> & m3)
{
    int rows = m1.size();
    int cols = m1[0].size();
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            m3[i][j] = m1[i][j] + m2[i][j];
}
void print_matrix(vector<vector<int> > mat)
{
    int n=mat.size(),i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    vector<vector<int> > mat1,mat2;
    int i,j,n;
    cin>>n;
    read_matrix(mat1,n);
    read_matrix(mat2,n);
    // Create resultant matrix of size nxn and intialize all elements to 0
   vector< vector<int> > mat3(n, vector<int>(n,0));    
	clock_t tStart = clock();
	matrix_add(mat1,mat2,mat3);
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
//	cout<<"Time taken is "<<time1<<endl;

   print_matrix(mat3);
}