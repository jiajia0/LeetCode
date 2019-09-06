/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// �Զ�����
/*
class Solution {
public:
    
    void dfs(TreeNode* root, int val) {
        if(root == NULL)
            return;
        // �ҵ�Ҷ�ӽڵ㣬���½ڵ���뵽Ҷ�ӽڵ�����
        if(root->left == NULL && root->val > val) {
            TreeNode* node = new TreeNode(val);
            root->left = node;
        }
        if(root->right == NULL && root->val < val) {
            TreeNode* node = new TreeNode(val);
            root->right = node;
        }
        if(root->val < val)
            dfs(root->right, val);
        if(root->val > val)
            dfs(root->left, val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root, val);
        return root;
    }
};
*/
// �Ե�����
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        if(root->val < val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};