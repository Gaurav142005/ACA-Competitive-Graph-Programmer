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
    vector<vector<int>> zigzagLevelOrder(TreeNode* &root){
        vector<vector<int>> res;
        if(!root)   return res;
        queue <TreeNode*> q;
        q.push(root);
        bool flagRev = false;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            while(size--){
                TreeNode* x = q.front();
                q.pop();
                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
                level.push_back(x->val);
            }
            if(flagRev) reverse(begin(level), end(level));
            flagRev = !flagRev;
            res.push_back(level);
        }
        return res;
    }
};

