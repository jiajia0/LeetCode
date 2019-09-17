/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for(int i = 2*nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i%nums.size()]) { // ��ջ��С�ڵ�ǰԪ�ض���ջ
                st.pop();
            }
            res[i%nums.size()] = st.empty() ? -1 : st.top();
            st.push(nums[i%nums.size()]);
            // �Ӻ���ǰ����ջ�У����Դ�ջ����ջ�׵�˳����������д�ǰ�����˳��
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), INT_MAX);
        // �ȰѺ���ȵ�ǰԪ�ش���ҳ���
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        // ���²���һ�飬��INT_MAXλ���ϵ�Ԫ�أ���ͷ��ʼ����һ��
        for(int i = 0 ; i < nums.size(); i++) {
            if(res[i] != INT_MAX)
                continue;
            else {
                int flag = 1;
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[i]) {
                        res[i] = nums[j];
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    res[i] = -1;
            }
        }
        
        return res;
    }
};