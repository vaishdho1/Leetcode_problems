/******************************************************************************************************************
                            113. Path Sum II
Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*******************************************************************************************************************/
/****************************************************************
                            Solution
DFS is run from the root till the leaf.
Add the value to a list everytime we enter into a node.
Everytime a leaf node is reached,we check if the sum of the nodes
in the path is same as the targetsum.
If the sum is the same, insert the list into the ans
*******************************************************************/


/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    void final_path(TreeNode* root, int targetSum,vector<int>path, vector<vector<int> >&ans)
    {
       
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0)
        {    ans.push_back(path);
             return;
        }
        else if(root->left==NULL && root->right==NULL)
            return;
        if(root->left!=NULL)
            final_path(root->left, targetSum-root->val,path,ans);
        if(root->right!=NULL)
             final_path(root->right,targetSum-root->val,path,ans);
        return;
            
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> >ans;
        if(root==NULL)
            return ans;
        vector<int>path;
        final_path(root,targetSum,path,ans);
        return ans;
    }
};
