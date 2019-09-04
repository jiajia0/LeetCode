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
    // �ڶ����������У������� L <= x <= R �����еĽڵ�֮��
    int G_L;
    int G_R;
    
    int dfs(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        int res = 0;
        // ��L��R�����ڣ��������
        if(root->val <= G_R && root->val >= G_L) {
            res = root->val + dfs(root->left);
            res = res + dfs(root->right);
        } else if(root->val > G_R) {
            res += dfs(root->left);
        } else {
            res += dfs(root->right);
        }
        return res;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        G_L = L;
        G_R = R;
        int res = dfs(root);
        return res;
    }
};
*/

/*
class Solution {
public:
    // �ڶ����������У������� L <= x <= R �����еĽڵ�֮��
    int G_L;
    int G_R;
    
    int dfs(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        int res = 0;
        // ��L��R�����ڣ��������
        if(root->val <= G_R && root->val >= G_L) {
            res += root->val;
        }
        if(root->val > G_L) // ��ǰ�ڵ��L��˵����߻��в��ҵĿռ�
            res += dfs(root->left);
        if(root->val < G_R) // ˵���ұ߻��в��ҵĿռ�
            res += dfs(root->right);
        return res;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        G_L = L;
        G_R = R;
        int res = dfs(root);
        return res;
    }
};*/

class Solution {
public:
    // �ǵݹ�д�������õ�ջ
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return 0;
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top(); // �õ�ջ����Ԫ��
            s.pop();
            if(node->val >= L && node->val <= R)
                res += node->val;
            if(node->val > L && node->left)
                s.push(node->left);
            if(node->val < R && node->right)
                s.push(node->right);
        }
        return res;
    }
};