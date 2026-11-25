class Solution {
public:
    vector<vector<int>> level(TreeNode* root)
    {
        vector<vector<int>> ans;              
        if(root == NULL) return ans;          

        queue<TreeNode*> q;                   
        q.push(root);
        q.push(NULL);
        
        vector<int> temp;                     

        while(q.size() > 0)
        {
            TreeNode* curr = q.front();       
            q.pop();

            if(curr == NULL)                  
            {
                ans.push_back(temp);
                temp.clear();
                if(q.size() > 0)
                {
                    q.push(NULL);
                }
            }
            else                              
            {
                temp.push_back(curr->val);    

                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return ans;                           
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        return level(root);
    }
};
