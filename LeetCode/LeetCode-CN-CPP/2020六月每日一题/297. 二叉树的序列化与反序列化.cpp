/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string serialized = "[";
        queue<TreeNode*> q; // ����һ�����У�����������ȱ���
        q.push(root);
        
        while(!q.empty()) { // ���в�Ϊ��
            TreeNode* node = q.front(); // ȡ�������еĵ�һ��Ԫ��
            q.pop();
            if(node == NULL) {
                serialized += "null";
                if(q.size() != 0) { // �ҽڵ�϶������һ��Ϊ�յģ������ж��Ƿ���Ҫ�������һ��������
                    serialized += ","; 
                }
                continue;
            } 

            serialized += to_string(node->val) + ","; // ���л�
            //cout << node->val << ":" << serialized << " ";
            if(node->left != NULL) {
                q.push(node->left);
            } else {
                q.push(NULL);
            }
            
            if(node->right != NULL) {
                q.push(node->right);
            } else {
                q.push(NULL);
            }
        }
        
        return serialized + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") {
            return NULL;
        }
        // ɾ����������
        data.erase(data.begin());
        data.erase(data.end() - 1);
        
        queue<TreeNode*> q;
        vector<string> tree_data;
        split(data, tree_data, ","); // ���зָ�
        TreeNode* root = new TreeNode(stoi(tree_data[0]));
        q.push(root);
        for(int i = 1 ; i < tree_data.size();) {
            int q_size = q.size(); // ��¼�¶����е�Ԫ�ظ���
            while(q_size != 0) { // �����������Ԫ�س����У�Ȼ����һ�������
                TreeNode* node = q.front(); // ������һ��Ԫ��
                q.pop();
                // �������
                if(tree_data[i] != "null") { // ��һ�����
                    TreeNode* next_left = new TreeNode(stoi(tree_data[i])); // ��ȡ����ǰ�ڵ����ֵ����������ƶ�һλ
                    node->left = next_left;
                    q.push(next_left);
                }
                i++;
                if(tree_data[i] != "null") { // ��һ�����
                    TreeNode* next_right = new TreeNode(stoi(tree_data[i]));
                    node->right = next_right;
                    q.push(next_right);
                }
                i++;
                q_size--;
            }
        }
        return root;
    }

    void split(const std::string& s, std::vector<std::string>& v, const std::string& c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));