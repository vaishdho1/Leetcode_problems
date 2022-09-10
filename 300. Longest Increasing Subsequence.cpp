/*********************************************************************************************
                300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting 
some or no elements without changing the order of the remaining elements. 
 For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 ********************************************************************************************/
/*
Solution:
I present 2 solutions for the same:
1)Using dynamic programming approach - O(n*n):

-- Let LIS[i]:Longest oncreasing subsequence at index 'i' in the array,
   initially set to 1 as length of the longest subsequence initially only consists of the
   element at index 'i'.
-- maximum_length:maximum length of the subsequence

Pseudocode:
For every element of the array,check if the
current element is smaller than the subsequent elements.
    If smaller,check if the LIS[current_element]<LIS[susequent_element] 
            If lesser
                update LIS[current_element]
            If the LIS[current_element]>maximum_length computed so far
                update maximum_length.
                
Note: The actual elements can be recovered using this method 
by creating an edge between ele1 and ele2 if ele2
contributed to the maximum LIS at ele1.
Store indices of elements with max_len and run a dfs from each
of the elements to get the path.
                
2) using binary search technique - O(nlogn)

Store the first element of the array in a temporary array(temp).
For each element in the array
  if arr[i]>temp.back()
      add arr[i] to temp
  if arr[i]<=temp_back
      find the position of the smallest element in temp
      which is greater than arr[i] and replace that element
      with arr[i].(Using binary search)
finally return the size of temp.
Note: The actual elements cannot be recovered using this method directly.
To recover the actual elements, further book keeping is needed 
whenever an element is replaced in temp.
  
*/

//Solution 1:
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n,1);
        int max_lis = 1;
        
        
        for(int i = n-1;i>=0;i--)
        {
            for(int j =i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                        LIS[i] = max(LIS[i],1+LIS[j]);
                if(LIS[i]>max_lis)
                    max_lis = LIS[i];
                
                    
            }
        }
        return max_lis;
        
        }

//Solution 2
int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
                temp.push_back(nums[i]);
            else
            {
                
                int low = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[low] = nums[i];
            }
        }
        
        return temp.size();
        
        }
