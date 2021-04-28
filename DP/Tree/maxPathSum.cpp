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
    
    int recursion(TreeNode* root, int &result){
        if(root==NULL) return 0;
        else{
            int ln = recursion(root->left,result);
            int rn = recursion(root->right,result);
            int not_included = max(max(ln,rn)+root->val,root->val);
            int included = ln+rn+root->val;
            int ans = max(not_included,included);
            result = max(result,ans);
            return not_included;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        recursion(root,result);
        return result;
    }
};
