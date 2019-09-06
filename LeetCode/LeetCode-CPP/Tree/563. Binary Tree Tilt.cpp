/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ���������Ҫ�����ÿ���ڵ��tilt ��Ȼ������нڵ��tilt�������
class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = 0, right = 0;
        left += dfs(root->left);
        right += dfs(root->right);
        res += abs(left - right); // ����tilt���ۼ� 
        return left + right + root->val; // �����ӽڵ��sum
    }
    
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return res;
    }
};
