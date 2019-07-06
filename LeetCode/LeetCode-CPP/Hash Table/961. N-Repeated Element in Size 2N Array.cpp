#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int result = A[0];
        map<int,int> nums;
        for(int i : A) { // ��Ԫ�طŵ�map��
            nums[i]++;
            if(nums[i] == A.size()/2)
                return i;
        }

        /*map<int,int>::iterator it = nums.begin();
        int max = 0;
        while(it != nums.end()) { // ����map�ҵ�value������ֵ���Լ���Ӧ��Ԫ��
            if(it->second > max) {
                max = it->second;
                result = it->first;
            }
            it++;
        }*/

        return result;
    }
};


/*class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int result = A[0];
        //
        for(int i : A) {
            if(count(A.begin(),A.end(),i) == A.size()/2) // ͳ�Ƶ�ǰԪ�صĸ������������N����ֱ�ӷ���
                return i;
        }
        return result;
    }
};*/

int main() {
    Solution s;
    vector<int> nums = {5,1,5,2,5,3,5,4};
    int result = s.repeatedNTimes(nums);
    cout << result << endl;
    return 0;
}
