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
    
    void dfs(TreeNode* root, vector<int>& res) {
        if(root == NULL)
            return;
        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        dfs(root, res);
        return res;
    }
};
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            if(curr->right != NULL && curr->right != lastVisited) { // �����ұߣ�����ȷ���ұ߸ղ�û�з��ʹ��������ұ��нڵ㣬����������ұߵ�ֱ�ӽӽڵ��Ȼ�ǵ�ǰ�ڵ��ǰһ�������з��ʵ�
                curr = curr->right;
            } else { // ���ұ�����Ϊ�գ������������1��Ҷ�ӽڵ㣬����ɾ�����ɣ�2���������������Ǻ���������������ȷ��ʵģ�������Ȼ���ʵ�ǰ�ڵ㲢ɾ�����ɡ�
                res.push_back(curr->val);
                s.pop();
                lastVisited = curr;
                curr = NULL;
            }
        }
        return res;
    }
};