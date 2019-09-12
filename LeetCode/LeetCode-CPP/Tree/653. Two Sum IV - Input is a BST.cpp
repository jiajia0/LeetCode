/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ʹ��hash˼�룬�������ټ��
/*
class Solution {
public:
    map<int,int> hash;
    
    void dfs(TreeNode* node) {
        if(node == NULL)
            return ;
        hash[node->val]++;
        dfs(node->left);
        dfs(node->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        hash.clear();
        if(root == NULL)
            return false;
        dfs(root);
        
        for(auto it = hash.begin(); it != hash.end(); it++) {
            //cout << it->first << endl;
            // || ֮ǰ��Ϊ�˷�ֹ Tree:1 , target:2 �������|| ֮����Ϊ�˷�ֹԪ���ظ������
            if((hash.count(k - it->first) == 1 && it->first != k-it->first) || (hash[it->first] == 2 && k-it->first))
                return true;
            
        }
        
        return false;
    }
};
*/
// ʹ��hash˼��߱����߼��
/*
class Solution {
public:
    
    bool dfs(TreeNode* root, int k , set<int>& hash) {
        if(root == NULL)
            return false;
        if(hash.count(k - root->val)) {
            return true;
        }
        hash.insert(root->val);
        return dfs(root->left, k, hash) || dfs(root->right, k, hash);
    }
    
    bool findTarget(TreeNode* root, int k) {
     
        if(root == NULL)
            return false;
        set<int> hash;
        
        return dfs(root, k, hash);
        
    }
};
*/
// ����BST�������Ϊ������ص㣬Ȼ��ʹ������ָ����м���sum
class Solution {
public: 
    
    void inorder(TreeNode* root, vector<int>& nums) {
        if(root == NULL)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        vector<int> nums;
        inorder(root, nums);
        int l = 0 , r = nums.size() - 1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum == k)
                return true;
            if(sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
};