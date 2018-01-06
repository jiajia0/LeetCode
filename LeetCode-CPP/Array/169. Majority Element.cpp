#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> res;
        int maxCount = 0;//�����洢�������Ĵ���
        int majorNum;//������ų��ִ������
        for (int num : nums) {
            res[num]++;
            if(res[num] >= maxCount) {
                maxCount = res[num];
                majorNum = num;
            }
        }
        return majorNum;
    }
};*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorNum = nums.size() / 2;
        sort(nums.begin(),nums.end());
        return nums[majorNum];//������֮�󣬴�������n/2��Ԫ�ر�Ȼ���м�
    }
};*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorNum;//���ִ�����������
        int count = 0;//����������Ĵ���
        for (int i=0; i < nums.size(); i++) {//����һ������
            if(count == 0) {//�����ʱ������Ϊ0����˵���տ�ʼ������һ�����ֳ��ֵĴ���������0�ˣ����õ�ǰ�����ּ�Ϊ���ִ�����������
                majorNum = nums[i];
            }
            if(majorNum == nums[i]) {//������ִ����������ֵ��ڵ�ǰ�����֣����ü�������һ
                count++;
            } else {//��������ڵ��ü�������һ
                count--;
            }
        }
        return majorNum;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    int result = s.majorityElement(nums);
    cout << result;
    return 0;
}


