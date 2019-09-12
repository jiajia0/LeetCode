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
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return root;
        // ��������Զ�λ�� L <= root->val <= R �С�
        if(root->val > R)
            return trimBST(root->left, L, R); // ����ֱ�ӷ��غ��ʵĽڵ㣬����һ���ڵ����ƴ��
        if(root->val < L)
            return trimBST(root->right, L, R);
        // ��������й�������������
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};