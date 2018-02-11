#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=0;//�����
        int maxIndex;//��������±�
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] >= maxNum) {//��¼���ֵ���±�
                maxNum = nums[i];
                maxIndex = i;
            }
        }

        for(int i=0; i < nums.size(); i++) {
            if(i!=maxIndex && nums[maxIndex] < 2*nums[i]) {
                return -1;
            }
        }
        return maxIndex;
    }
};*/

/*class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=0;//�����
        int maxIndex;//��������±�
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] >= maxNum) {//��¼���ֵ���±�
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        sort(nums.begin(),nums.end());//����
        if(maxNum < 2*nums[nums.size()-2]) {
            return -1;
        }
        return maxIndex;
    }
};*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=-1;//�����
        int maxIndex;//��������±�
        int lastMaxNum=-1;//��һ�������
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] >= lastMaxNum) {//�ȿ�һ����ǰ���Ƿ������һ�����ֵ
                lastMaxNum = nums[i];//������һ�����ֵ���ڵ�ǰ��
                if(nums[i] > maxNum) {//�����������ֵ����Ļ���������ǰ���ֵ����һ�����ֵ
                    lastMaxNum = maxNum;
                    maxNum = nums[i];
                    maxIndex = i;
                }
            }
        }
        //cout << maxNum << "," << lastMaxNum << endl;
        if(maxNum < 2*lastMaxNum) {
            return -1;
        }
        return maxIndex;
    }
};


int main() {
    Solution s;
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(3);
    num.push_back(2);
    int res = s.dominantIndex(num);
    cout << res;
}


