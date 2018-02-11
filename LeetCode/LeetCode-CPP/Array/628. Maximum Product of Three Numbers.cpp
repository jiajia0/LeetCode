#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());//����
        int count = nums.size();
        return max(nums[count-1]*nums[count-2]*nums[count-3],nums[count-1]*nums[0]*nums[1]);//��Ҫע����ܻ��и��������
    }
};*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstPosNum = INT_MIN;//��������
        int secondPosNum = INT_MIN;//�ڶ��������
        int thirdPosNum = INT_MIN;//�����������
        int firstNegNum = INT_MAX;//��С�ĸ���
        int secondNegNum = INT_MAX;//�ڶ�С�ĸ���

        for (int i=0; i < nums.size(); i++) {
            if(num[i] > firstPosNum) {//�滻���
                thirdPosNum = secondPosNum;
                secondPosNum = firstPosNum;
                firstPosNum = num[i];
            } else if(num[i] > secondPosNum) {
                thirdPosNum = secondPosNum;
                secondPosNum = num[i];
            } else if (num[i] > thirdPosNum) {
                thirdPosNum = num[i];
            }

            if(num[i] < firstNegNum) {//�滻С��
                secondNegNum = firstNegNum;
                firstNegNum = num[i];
            } else if(num < secondNegNum) {
                secondNegNum = num[i];
            }
        }

        //cout << firstPosNum << "," << secondPosNum << "," << thirdPosNum << endl;
        //cout << firstNegNum << "," << secondNegNum << endl;

        int Pos = firstPosNum*secondPosNum*thirdPosNum;
        int Neg = firstPosNum*firstNegNum*secondNegNum;

        return max(Pos,Neg);

    }
};


int main() {
    Solution s;
    vector<int> num;
    num.push_back(-1);
    num.push_back(-2);
    num.push_back(1);
    int ret = s.maximumProduct(num);
    cout << ret;
}


