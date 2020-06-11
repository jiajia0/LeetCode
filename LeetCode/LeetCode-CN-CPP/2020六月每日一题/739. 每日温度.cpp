class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(),0);
        stack<int> stk;

        for(int i = T.size() - 1; i >= 0; i--) {
            // ջ��ֻ��Ҫ����ȵ�ǰ���¸ߵ�λ��
            while(!stk.empty() && T[i] >= T[stk.top()]) {
                stk.pop(); // ��ջ
            }
            // ���ջ��Ϊ�գ���˵��û�бȵ�ǰ���¸ߣ�������������ȵ�ǰ���λ���뵱ǰ��λ��
            result[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }

        return result;
    }
};