# Kadane's Algorithm
def maxSubArraySum(a,size):
	
	global_max = a[0]
	positive_sum_till_here = 0
	
	for i in range(0, size):
		positive_sum_till_here = positive_sum_till_here + a[i]
		if (positive_sum_till_here > global_max ):
			global_max = positive_sum_till_here
		if positive_sum_till_here < 0:
			positive_sum_till_here = 0
		
		# Do not compare for all elements. Compare only
		# when max_ending_here > 0
		
	return global_max

a = [-13, -3, -25, -20, -3, -16, -23, -12, -5, 22, -1, -4, -7, 100]

max_val = maxSubArraySum([-2,-3,4,-1,-2,1,5,-3],8)
print(max_val)


"""
sum += arr[i];
        if(sum > max)
        {
            max = sum;
            result.high = i;
            result.low = begin;
        }
        else if(sum < 0)
        {
            begin = i+1;
            sum = 0;
        }

details find_zero_sum(vector<int> elements)
{
    map<int,int> sum_index;
    int i, n, sum = 0;
    details d;
    n = elements.size();
    d.low = -1;
    d.high = -1;
    int len = 0;
    sum_index[0] = 0;
    for(i = 0; i < n; i++)
    {
        sum = sum + elements[i];
        if(sum_index.find(sum) != sum_index.end()) // if sum is present
        {
            int n = i - sum_index[sum];
            if(n > len)
            {
                len = n;
                d.low = sum_index[sum] + 1;
                d.high = i + 1;
            }
        }        
        else
            sum_index[sum] = i + 1;
    }       
        return d;   
}
"""