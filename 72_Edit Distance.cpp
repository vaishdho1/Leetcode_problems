/**************************************************************************************************************
Problem:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
****************************************************************************************************************/
/************************************************************************
I present 2 solutions using dynamic programming technique:
m,n are the lengths of the 2 words respectively.
1) Using O(m*n) space 
2)Using O(m) space where m>n
Both the techniques use O(m*n) time complexity
**************************************************************************/

//Solution 1:Uses O(m*n) space and O(m*n) time compelxity//

int minDistance(string word1, string word2) {
 int n = word1.size();
        int m = word2.size();
        vector<vector<int> >ED(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
            ED[i][m] = n-i;
        for(int j=0;j<m;j++)
            ED[n][j] = m-j;
        
        for(int j=m-1;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(word1[i]==word2[j])
                    ED[i][j] = ED[i+1][j+1];
                else
                    ED[i][j] = 1+min(ED[i+1][j],min(ED[i+1][j+1],ED[i][j+1]));
                
            }
        }
        
        return ED[0][0];
}
            
        
        
 //Solution 2:UsesO(m) space where m>n

int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<int>ED(n+1,0);
        vector<int>dummy(n+1,0);
        for(int i=0;i<n;i++)
            ED[i]= n-i;
        int j =0;
       
       while(j<m)
      {    
           if(j%2==0)
          {
              dummy[n] = j+1; 
              for(int i =n-1;i>=0;i--)
            {
                  if(word1[i]==word2[m-1-j])
                      dummy[i] = ED[i+1];
                  else
                  {
                      dummy[i] = 1+min(min(ED[i],ED[i+1]),dummy[i+1]);
                  }

            }
          }
          else
           {
              ED[n] = j+1; 
              for(int i =n-1;i>=0;i--)
            {
                  if(word1[i]==word2[m-1-j])
                      ED[i] = dummy[i+1];
                  else
                  {
                      ED[i] = 1+min(min(dummy[i],dummy[i+1]),ED[i+1]);
                  }

            }
          }
       j++;
           
      }
    
        if(m%2==0)
            return ED[0];
        return dummy[0];
          
        
      }
