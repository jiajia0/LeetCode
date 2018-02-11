#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> Num;//����ͳ�����ֳ��ֵĴ���
        for(int n : nums) {
            if(++Num[n] > 1) {
                return true;
            }
        }
        return false;
    }
};*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) {
            return false;
        }
        sort(nums.begin(),nums.end());//��������
        for(int i=0; i < nums.size()-1; i ++) {
            if(nums[i] == nums[i+1]) {//�����������Ԫ����ȵĻ����ͷ���true
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(2);
    num.push_back(15);
    bool res = s.containsDuplicate(num);
    cout << res;
}


