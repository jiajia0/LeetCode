class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int res = 0;
        for(string op : ops) {
            if(op == "C") { // ���һ��������Ч
                int top = st.top();
                res -= top;
                st.pop();
                continue;
            }
            if(op == "D") { // ���һ�������������ӵ����ս���У����������ķ�����Ҫ����ջ��
                int top = st.top() * 2;
                res += top;
                st.push(top);
                continue;
            }
            if(op == "+") { // �õ�ջ�����������֣���ӵõ��µķ���
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                st.push(top1 + top2);
                res += (top1 + top2);
                continue;
            }
            // ��ͨ�����֣�ֱ�����
            st.push(stoi(op));
            res += stoi(op);
            
        }
        return res;
    }
};