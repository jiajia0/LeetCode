#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numsSet;

        for(int n : nums) {
            if(numsSet.count(n) == 0) {// �����ǰû�в��ҹ���������ӽ�ȥ
                numsSet.insert(n);
            } else {// ������˽���ɾ����
                numsSet.erase(n);
            }
        }

        return *numsSet.begin();
    }
};*/

/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> numsSet;

        for(int n : nums) {
            sum += n;// ���
            if(numsSet.count(n) == 0) {// ���set��û�����Ԫ�أ�������ӽ�ȥ
                numsSet.insert(n);
            } else {
                sum -= 2*n;// ������������ȥ����n
            }
        }

        return sum;
    }
};*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)// ��ֹΪ�գ�����������û�г��ֿյ����
            return -1;
        int ans = * nums.begin();
        for(int i=1; i < nums.size(); i++) {
            ans ^= nums[i];// �������
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    int result = s.singleNumber(nums);
    cout << result;
    return 0;
}
