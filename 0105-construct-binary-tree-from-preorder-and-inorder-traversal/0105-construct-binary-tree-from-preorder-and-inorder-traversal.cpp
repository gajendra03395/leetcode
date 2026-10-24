/**
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
    int search(vector<int>& inorder, int left , int right , int val)
    {
        for(int i = left ; i <= right ; i++)
        {
            if(inorder[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preidx ,int left , int right)
    {
        if(left > right)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preidx]);

        int inidx = search(inorder , left , right , preorder[preidx]);
        preidx++;
        root->left = helper(preorder,inorder,preidx,left,inidx-1);
        root->right = helper(preorder,inorder,preidx,inidx+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder , inorder , preidx , 0 , inorder.size()-1);
    }
};