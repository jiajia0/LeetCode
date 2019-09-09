/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
class Solution {
public:
    void dfs(Node* root, vector<int>& res) {
        if(root == NULL)
            return;
        for(int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
*/
/*
// ���Ȱ����������ҵ���ȫ�����뵽stack�У�Ȼ��������ȡ������
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> s1;
        stack<int> s2;
        if(root == NULL)
            return res;
        s1.push(root);
        while(!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node->val);
            for(int i = 0; i < node->children.size(); i++) {
                s1.push(node->children[i]);
            }
        }
        while(!s2.empty()) {
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* node = s.top();
            s.pop();
            res.push_back(node->val);
            for(int i = 0; i < node->children.size(); i++)
                s.push(node->children[i]);
        }
        reverse(res.begin(), res.end()); // �����stackʹ��reverse��� 
        return res;
    }
};