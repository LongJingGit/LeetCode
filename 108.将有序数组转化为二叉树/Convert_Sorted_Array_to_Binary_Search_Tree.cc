/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return changeArrayToBst(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* changeArrayToBst(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return NULL;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = changeArrayToBst(nums, left, mid - 1);
        root->right = changeArrayToBst(nums, mid + 1, right);
        
        return root;
    }    
};