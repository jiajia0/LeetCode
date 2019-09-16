/*
class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<char> st;
        for(char ch : s) {
            if(ch != ')') {
                st.push(ch);
            } else {
                queue<char> q; // ʹ�ö�����ʵ��ջ��Ԫ�صķ�ת
                while(!st.empty() && st.top() != '(') {
                    q.push(st.top());
                    st.pop();
                }
                if(!st.empty()) // ɾ�� (
                    st.pop();
                while(!q.empty()) { // �ѷ�ת�󣨣��е������ٴ���ӵ�ջ��
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        while(!st.empty()) {
            char top = st.top();
            res = top + res;
            st.pop();
        }
        return res;
    }
};
*/

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') { // ��¼��һ��(��λ��
                st.push(i);
            } else if(s[i] == ')') {
                int top = st.top(); // �ҵ���һ��( ��λ��
                reverse(s.begin() + top + 1, s.begin() + i); // ��()�м���������ݽ��з�ת
                st.pop();
            }
        }

        for(char ch : s) {
            if(ch != '(' && ch !=')')
                res += ch;
        }
        return res;
    }
};