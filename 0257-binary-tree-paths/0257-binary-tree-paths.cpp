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
    void allpaths(TreeNode* root , string path , vector<string>& ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return;
        }
        if(root->left)
        {
            allpaths(root->left , path + "->" + to_string(root->left->val),ans);
        }
        if(root->right)
        {
            allpaths(root->right , path + "->" + to_string(root->right->val),ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = to_string(root->val);

        allpaths(root,path,ans);
        return ans;
    }
};