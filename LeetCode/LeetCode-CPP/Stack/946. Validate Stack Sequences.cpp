class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        if(pushed.size() != popped.size())
            return false;
        int i = 0;
        for(int n : pushed) {
            st.push(n); // �Ȱ�pushed�е����ִ���ջ��
            while(!st.empty() && st.top() == popped[i]) { //ջ��Ԫ�ص��ڵ�ǰ��Ҫ��ջ��Ԫ��,����г�ջ���� 
                st.pop();
                i++; // ��ջ��index����ƶ�
            }
        }
        return st.size() == 0;
    }
};