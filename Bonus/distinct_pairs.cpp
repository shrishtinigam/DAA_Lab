/*
Find distinct pairs of elements whose differences are same
’Difference’ of a pair of elements (a, b), a, b ∈ N, is defined as the absolute value of the a − b, denoted as |a-b|. Given an array A of size n with integers. Write a pseudo code and an appropriate code to compute all the possible distinct pairs of elements of A whose differences are same. If A =< 2, 8, 4, 5 >, the output should be : (2, 5), (5, 8). These are the pairs whose differences are 3. If A =< 2, 1, 3, 5 >, the output should be : (1, 2), (2, 3), whose difference is 1 and (1, 3), (3, 5) whose difference is 2. If A =< 2, 2, 2, 2 >, the output should be : (2, 2) whose difference is 0. When you print a pair, smaller integer should be printed first and then print the bigger integer (we call this organising the pair). After organising the pairs,  you have to print the pairs in the order of increasing values of the first component of the pair. If the first components are same, you have to print the pair in the increasing order of  the second component.  You can follow any strategy for designing the pseudo code. If A does not have no pairs whose differences are same, your algorithm should return 0.

Input format:

Enter the length of the array: n

Enter the first element of A:

Enter the second element of A:

....

Enter the n-th element of A:

Output format:

Print the smallest difference : d1 (say)

The number of pairs with difference d1: i

First component of the first pair with difference d1:

second component of the second pair with difference d1:

...

...

First component of the i-th pair with difference d1:

second component of the i-th pair with difference d1:

Print the next smallest difference : d2(say)

Number of pairs with difference d2: j

and so on

Example:

Input:

4

2

8

4

5

Output:

3

2

2

5

5

8
*/