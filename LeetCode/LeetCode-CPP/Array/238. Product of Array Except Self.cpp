#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();//�õ�������ܳ���
        vector<int> result(n);//����Ľ��

        int left = 1;//����߿�ʼ����
        for(int i=0; i < n; i++) {
            if(i > 0) {//�ӵڶ�����ʼ
                left = left * nums[i-1];//������ߵ����ֵõ���ߵ������ܺ�
            }
            result[i] = left;//��ǰ��λ�õ�����ߵ������ܺ�
        }

        int right = 1;//���ұ߿�ʼ����
        for(int i=n-1; i >= 0; i--) {
            if(i < n-1) {//�ӵ����ڶ�����ʼ
                right = right * nums[i+1];//�õ��ұߵ��ܺ�
            }
            result[i] = result[i] * right;//��ǰλ���ٳ����ұߵ��ܺ�
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<int> result = s.productExceptSelf(nums);
    for(auto n : result) {
        cout << n << ",";
    }
    return 0;
}

