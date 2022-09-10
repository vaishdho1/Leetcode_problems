
/**********************************************************************************************************************
                            Maximum Segment Sum After Removals
                            
You are given two 0-indexed integer arrays nums and removeQueries, both of length n.
For the ith query, the element in nums at the index removeQueries[i] is removed, splitting nums into different segments.
A segment is a contiguous sequence of positive integers in nums. A segment sum is the sum of every element in a segment.
Return an integer array answer, of length n, where answer[i] is the maximum segment sum after applying the ith removal.
Note: The same index will not be removed more than once.
***********************************************************************************************************************/

/***************************************************************************************************
I have used disjoint_union_find method to solve this problem.
The problem can be solved by reversing the deletion operations mentioned,i.e
adding the removed elements in the reverse order into a hash_table
and merging the current element and prev_element to this added element if there is a merge possible
and merging the current_element and the next_one if there is a merge possible.
At each step the maximum sum is inserted at the right location in the answer array.
*****************************************************************************************************/

class Solution {
public:
    pair<int,bool> find(int x,unordered_map<int,int> & parent)
    {
        if(parent.find(x)==parent.end())
            return {0,false};
        while (parent[x]!=x)
            x = parent[x];
        return {x,true};
        
    }
    
    void find_union(int x,int y,unordered_map<int,int> & parent,long long & current_sum,unordered_map<int,long long> &sum_interval)
    {
        bool exists_x,exists_y;
        int px,py;
        px= find(x,parent).first;
        exists_x= find(x,parent).second;
        py= find(y,parent).first;
        exists_y= find(y,parent).second;
        
        
        if(exists_y && exists_x)
        {
          if(px<py)
          {
              parent[py] = px;
              sum_interval[px]+=sum_interval[py];
              current_sum = max(current_sum,sum_interval[px]);
          }
          else
          {
              parent[px] = py;
              sum_interval[py]+=sum_interval[px];
              current_sum = max(current_sum,sum_interval[py]);
          }
        }
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        unordered_map<int,int>parent;
        unordered_map<int,long long>sum_interval;
        vector<long long> ans(removeQueries.size());
        ans[removeQueries.size()-1] = 0;
        long long current_sum = 0;
        for(int i=removeQueries.size()-1;i>0;i-- )
        {
            int idx = removeQueries[i];
            parent[idx] = idx;
            sum_interval[idx] = nums[idx];
            current_sum=max(current_sum,sum_interval[idx]);
            find_union(idx-1,idx,parent,current_sum,sum_interval);
            find_union(idx,idx+1,parent,current_sum,sum_interval);
            ans[i-1]=current_sum;
            
            
        }
        return ans;
        
        
    }
};
