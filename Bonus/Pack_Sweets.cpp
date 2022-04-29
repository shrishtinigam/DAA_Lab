/*
Is it possible to Pack the sweets
A sweet shop gets sweet boxes of different sizes (said in the means of number of sweets 
that can be kept) from a sweet box manufacturer. All the sweets prepared by the sweet shop 
are of same size. Boxes manufactured can hold 2 or more sweets. Given the number of sweets 
prepared by the shop and sizes of boxes available, develop an algorithm and write a C++ code 
to check if the sweets can be kept in boxes with following constraints
(i) Multiple boxes of same size shall be chosen

(ii) All chosen boxes are full and no sweet is left over
(ii) All boxes except box bi (bi is any box) is full and bi has its capacity - 1 sweets 
If it is possible to keep sweets with above said constraints then print Yes and Print No otherwise.
For example, if the boxes are of sizes 2, 5, 8 and number of sweets prepared is 18 then print "Yes", 

There are multiple solutions to the problem, one of the solution is 
2x3 + 5 + 8 = 19, 19 is one more than 18. 
If the boxes are of sizes  5, 6 then if number of sweets prepared is 28 then print Yes 5*2 + 6*3 = 28 
and print No if number of sweets prepared is 13

If boxes are of size 5,6 and number of sweets prepared is 25 then print Yes, 5*5 = 25

Input Format
First line contains the number of sweets prepared, n
Next line contains the number of different sizes of boxes, m

Next 'm' lines contain the size of the boxes manufatured


Output Format
Print Yes or No
*/