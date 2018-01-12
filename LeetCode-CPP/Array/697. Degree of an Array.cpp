#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxCount = 0;//���ֳ��ֵ���������Ҳ���Ƕ���
        unordered_map<int,int> numCount;//�������ÿ�����ֳ��ֵĴ���
        unordered_set<int> maxNums;//���������������

        for(int i=0;i<nums.size();i++) {
            numCount[nums[i]]++;//��Ӧ�Ĵ�����һ

            if(numCount[nums[i]] > maxCount) {//����λ�ã������maxNums���飬����µ����ֵ
                maxCount = numCount[nums[i]];
                maxNums.clear();
                maxNums.insert(nums[i]);
            }
            if(numCount[nums[i]] == maxCount) {//�����ȵĻ�,���µ�������ӽ�ȥ
                maxNums.insert(nums[i]);
            }
        }

        int startIndex = -1;
        int endIndex = -1;
        int minLen = -1;

        for(int num : maxNums) {//�������ж����������֣��ҵ�������̵�
            startIndex = -1;
            endIndex = -1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] == num) {
                    if(-1 == startIndex) {
                        startIndex = i;
                    }
                    if(i >= endIndex) {
                        endIndex = i;
                    }
                }
            }
            minLen = (minLen < 0) ? (endIndex-startIndex+1) : min(endIndex-startIndex+1,minLen);
            //cout << startIndex << "," << endIndex << endl;
            //cout << (endIndex-startIndex+1) << endl;
        }

        return minLen;
    }
};*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int minLen = 0;//��С��Ϊ1
        int degree = 0;//��С�Ķ�Ϊ1

        unordered_map<int,pair<int,int>> ans;//�����洢Ԫ�غ͸�Ԫ�ؿ�ʼ�±�ͳ��ֵĴ���

        for(int i=0; i<nums.size(); i++) {
            ans[nums[i]].second++;//���ֵĴ�����һ
            if(ans[nums[i]].second == 1) {//�����Ԫ���״γ���
                //cout << "���֣�" << nums[i] << ",��ʼ������" << i << endl;
                ans[nums[i]].first = i;//��¼��ʼ������
            }

            if(ans[nums[i]].second > degree) {//�����ʱ���ֵĴ������������е���߶���
                degree = ans[nums[i]].second;//������߶���
                minLen = i - ans[nums[i]].first + 1;//��ǰλ�ü�ȥ��ʼλ�õõ��м䳤��
                //cout << "��ǰ����" << i << "����ʼ���꣺" << ans[nums[i]].first << endl;
            } else if(ans[nums[i]].second == degree) {//��������������Ҫ�Ƚ���һ���Ƚ϶�
                minLen = min(minLen,i - ans[nums[i]].first + 1);
            }
        }

        return minLen;
    }
};



int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 1};

    int result = s.findShortestSubArray(nums);
    cout << result;
    return 0;
}



