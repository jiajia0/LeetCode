#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size() + 1;//�õ�������Ӧ�õ�����

        for(int i=0; i < nums.size(); i++) {//���������ʱ���ܺ�
            sum += nums[i];
        }
        return ((n*(n-1))/2 - sum);//ʹ�ø�˹��ʽ�������������ȥ���������ʵ������
    }
};*/

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());//��������

        if(nums[0] != 0) {//�����һ�����ֲ�����0
            return 0;
        }

        if(nums[nums.size()-1] != nums.size()) {//������һ�����ֲ���������ĳ���
            return nums.size();
        }

        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]+1 != nums[i]) {//���ǰ��ĵļ���һ֮���뵱ǰ��һλ����ȣ���˵��ȱʧ��
                return nums[i-1] + 1;
            }
        }
    }
};*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> numSet;

        for(int i=0; i<nums.size(); i++) {//�������飬�������ݷŵ���ϣ����
            numSet[nums[i]]++;//��Ӧ��value��һ
        }

        for(int i=0; i <= nums.size(); i++) {//��0��n��������ȱ����һ������
            if(numSet[i] == 0) {
                return i;
            }
        }
    }
};

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();
        for(int i=0; i<nums.size(); i++) {//���������Ϊ0��n���������Լ����鳤�Ƚ������Ļ�����Ȳ��ֻ�������������ȱʧֵ
            miss ^= i ^ nums[i];
        }
        return miss;
    }
};*/

int main() {
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(0);
    num.push_back(1);
    int ret = s.missingNumber(num);
    cout << ret;
}


