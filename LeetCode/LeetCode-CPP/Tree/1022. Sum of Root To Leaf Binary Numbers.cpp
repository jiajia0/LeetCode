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
    vector<vector<int>> nums;
    vector<int> path;
    // �����е�·���ҳ���
    void dfs(TreeNode* root) {
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            nums.push_back(path);
            path.pop_back(); // ����ط�Ҳ��Ҫע�����
            return;
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back(); // ����һ��
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i].size() - 1;
            int sum = 0;
            for(int j = 0; j < nums[i].size(); j++) {
                sum += (nums[i][j] << n);
                n--;
            }
            res += sum;
        }
        return res;
    }
};
*/

class Solution {
public:
    
    int dfs(TreeNode* root, int val) {
        if(root == NULL)
            return 0;
        val = 2*val + root->val;// ����һ��ĳ���2���൱�������ƶ�һλ��Ȼ���ټ��ϵ�ǰ�ڵ�
        if(root->left == NULL && root->right == NULL)
            return val;
        else
            return dfs(root->left, val) + dfs(root->right, val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int res;
        res = dfs(root, 0);
        return res;
    }
};