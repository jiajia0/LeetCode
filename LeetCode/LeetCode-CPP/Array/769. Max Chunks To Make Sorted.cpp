#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int curMax = 0;

        for(int i=0; i < arr.size(); i++) {
            curMax = max(arr[i],curMax);
            if(curMax == i)// ����������ķ�Χ�ڣ����ֵ�����±꣬˵�����Ի���
                ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,0,1,4,2};
    int result = s.maxChunksToSorted(nums);


    cout << result;

    return 0;
}





