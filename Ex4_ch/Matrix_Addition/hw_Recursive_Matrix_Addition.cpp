// hw_Recursive_Matrix_Addition.cpp
/*
Recursive Matrix Addition
Write a C++ program to do matrix addition by recursion. Use vectors of STL to represent matrices. Understand the precode and postcode given to complete the rest of the code

Algorithm for recursive_matrix_addition

Step 1: If size of matrix is 1 then add the elements in the input matrices to get output

c[i][j]  = a[i][j]+b[i][j] and return

Otherwise go to step 2

Step 2: Split the input and output matrices into four matrices of size n/2 and call 

C11 = recursive_matrix_addition(A11,B11)

C12 = recursive_matrix_addition(A12,B12)

C21 = recursive_matrix_addition(A21,B21)

C22 = recursive_matrix_addition(A22,B22)

Reference Code and Code for Dataset generation is present in

https://github.com/janakimeena/DAA_Winter_22/tree/main/Ex4_ch

Generate dataset of different sizes from 2^1 to 2^13 and make a plot of time taken to execute the code and compare with conventional matrix addition

Input Format

First line contains the number of rows and columns in the input square matrices, n

Next line contains the elements of first input matrix

Next line cotains the elements of second input matrix

Output Format

Print the resultant matrix with one row in one line

square_matrix_add_recursive(matrix m1, matrix m2, matrix m3, i, j, n)
    if(n == 1)
        m3[i][j] = m1[i][j] + m2[i][j]
        return
    square_matrix_add_recursive(m1,m2,m3,i,j,n/2)     // 11 matrix addition
    square_matrix_add_recursive(m1,m2,m3,i+n/2,j,n/2)   // 12 matrix addition
    square_matrix_add_recursive(m1,m2,m3,i,j+n/2,n/2)   // 21 matrix addition
    square_matrix_add_recursive(m1,m2,m3,i+n/2,j+n/2,n/2)  // 22 matrix addition

Matrix addition consists of simply adding respective elements in both the matrices. 
Matrices have to be of the same dimensions. We can do this recursively for a square
matrix of dimensions n x n where n = 2^k. We divide the matrix into four parts and 
add those parts recursively. The base case is when n = 1, where we just add the one 
element in the 1x1 matrix.

Excel sheet with comparison between recursive and conventional method runtimes is here along with code - 
https://github.com/shrishtinigam/DAA_Lab/tree/main/Ex4_ch/Matrix_Addition
*/

#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
void read_matrix(vector<vector<int> >&mat,int n)
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
void square_matrix_add_recursive(vector<vector<int>> &m1, vector<vector<int>> &m2, vector<vector<int>> & m3, int i, int j, int n)
{
    if(n == 1)
    {
        m3[i][j] = m1[i][j] + m2[i][j];
        return;
    }
    square_matrix_add_recursive(m1,m2,m3,i,j,n/2);
    square_matrix_add_recursive(m1,m2,m3,i+n/2,j,n/2);
    square_matrix_add_recursive(m1,m2,m3,i,j+n/2,n/2);
    square_matrix_add_recursive(m1,m2,m3,i+n/2,j+n/2,n/2);
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
   square_matrix_add_recursive(mat1,mat2,mat3,0,0,n);
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Time taken is "<<time1<<endl;

   print_matrix(mat3);
}