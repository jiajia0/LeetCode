/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            res++;
            while(n--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL) //����Ҷ�ӽڵ�ֱ��return
                    return res;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) // �սڵ㲻���м���
            return 0;
        // �������root��leaf�����¾��룬����һ��Ҫ��Ҷ�ӽڵ�
        if(root->left == NULL && root->right == NULL) // Ҷ�ӽڵ����һ��
            return 1;
        // ��������ֻ��һ������������Ҷ�ӽڵ����С���Ӧ������������ģ����յ���һ������ΪMAX����ͨ��min����ɵõ��������������
        // ���⽫�յ�һ������0 �� һ������Ϊ�գ�һ�߲�Ϊ�գ������㵽leaf��������������Ҫ��������Ѱ��
        int left_min = root->left ? minDepth(root->left) : INT_MAX;
        int right_min = root->right ? minDepth(root->right) : INT_MAX;
        return min(left_min, right_min) + 1;
    }
};