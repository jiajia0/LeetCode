#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stk;// ��������֮ǰ�������ǵڼ����

        // ��β��ͷ����
        for(int i=temperatures.size()-1;i>=0;i--) {
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()])// �����ǰ�����±�ջ�е����¸ߣ����ջ
                stk.pop();
            // ���ջ��Ϊ�գ���˵�����������û�б����ڸߵģ�����0��
            // �����Ϊ����˵��������������ڱ����ڸߵģ���鿴�ϸ���֮ǰ�ߵ������ǵڼ���ġ�
            ans[i] = stk.empty() ? 0 : stk.top() - i ;
            stk.push(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};
    vector<int> result = s.dailyTemperatures(temperatures);
    for(int i : result ) {
        cout << i << " ";
    }
    return 0;
}
