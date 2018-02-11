#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();

        if(n <= 1) {
            return n;
        }

        int maxNum = 1;//��¼�����������ֵ
        int count = 1;//��¼��ǰ�������ֵĴ���

        for(int i=1; i < n; i++) {
            //cout << nums[i-1] << "," << nums[i] << endl;
            if(nums[i-1] < nums[i]) {//����ȵ�ǰ��С���ǵ���
                count++;
            } else {
                count = 1;
            }
            maxNum = max(count,maxNum);
        }
        return maxNum;
    }
};*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;//������������
        int curIndex = 0;//��ǰ���±�

        for(int i=0;i<nums.size();i++) {
            if(i>0 && nums[i] <= nums[i-1]) {//�ӵڶ�����ʼ����¼�µ������п�ʼ��λ��
                curIndex = i;//��¼��ǰ���±�
            }
            maxLen = max(maxLen,i-curIndex+1);//�õ�ǰ������������͵�ǰ����������
        }
        return maxLen;
    }
};


int main() {
    Solution s;
    vector<int> num = {1,3,5,4,2,3,4,5};
    int res = s.findLengthOfLCIS(num);
    cout << res;
}



