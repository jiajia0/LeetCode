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
    // ���������ʽ�Ϸ�
    TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0) {
            return NULL;
        }
        int num_start_index = 0; // ��ǰ���ֵ���ʼλ��
        int num_end_index = S.find("-") ; // ��ǰ���ֵ����λ�� + 1
        int cur_level = 0; // ��¼��ǰ�Ĳ��
        TreeNode* root = new TreeNode(stoi(S.substr(num_start_index, num_end_index)));
        TreeNode* p = root;
        stack<TreeNode*> stk;
        stk.push(p);
        // �������ʱ stkҲ��Ϊ��
        while(!stk.empty()) {
            TreeNode* node = NULL;
            // �ж��¸��ڵ��ǲ�����һ���
            size_t next_num_start = S.find_first_not_of("-", num_end_index); // �ҵ���һ���ǡ�-����λ��
            if(next_num_start == string::npos) { // ˵���Ѿ������ַ���ĩβ, �����Ľ�������
                return root;
            }
            size_t next_num_end = S.find("-", next_num_start); // �ҵ���һ����-����λ�� �� Ҳ����һ������λ��+1
            if(next_num_end == string::npos) { // ˵���Ѿ������һ������
                next_num_end = S.size(); // ��¼Ϊ�ַ����ĳ���
            }
            int next_level = next_num_start  - num_end_index; // �õ������ǵڼ����
            int next_num = stoi(S.substr(next_num_start, next_num_end)); // ��ȡ����һ������
            //cout << "cur_level:" << cur_level << " , next_level:" << next_level;
            //cout << "cur_num:" << p->val << " , next_num:" << next_num <<  " ,stknum:" << stk.size() <<endl;
            if(next_level > cur_level) { // ����ǵ�ǰ������Ĳ�Ļ�����ӵ���ǰ�ڵ����ڵ�
                node = new TreeNode(next_num);
                p->left = node;
                p = node;
                //cout << "��������ڵ㣬���Ӻ��ֵΪ��" << p->val << endl;
                stk.push(node);
                cur_level = next_level;
                num_start_index = next_num_start;
                num_end_index = next_num_end;
                continue;
            }

            if(next_level == cur_level) { // �����һ����ڵ�ǰ�㣬˵����ͬ�����
                stk.pop(); // ��ǰ��ڵ��ջ
                p = stk.top(); // ��ȡ��һ��Ľڵ�
                node = new TreeNode(next_num); 
                p->right = node;
                p = node;
                //cout << "=�����ҽڵ㣬���Ӻ��ֵΪ��" << p->val << endl;
                stk.push(node);
                cur_level = next_level;
                num_start_index = next_num_start;
                num_end_index = next_num_end;
                continue;
            }
            if(next_level < cur_level) {
                stk.pop();
                p = stk.top();
                //cout << "����ʱ��ֵΪ��" << p->val << endl;
                cur_level--;
            }
        }
        return root;
    }
};