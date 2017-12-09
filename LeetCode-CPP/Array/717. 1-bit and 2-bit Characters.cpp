#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int num = 0;
        while(num < bits.size() - 1) {
            if(bits[num] == 1) {//������������ַ��ľͼ�2
                num = num + 2;
            } else {//�����һ
                num++;
            }
        }
        if(num == bits.size() - 1) {//�����ʱ���õ������һ���±��λ�ã�˵�����һ������0
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);


    bool b = s.isOneBitCharacter(nums);
    cout << b;
    return 0;
}
