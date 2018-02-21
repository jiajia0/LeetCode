#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int result = 0;
        int maxResult = candies.size()/2;// sister�õ�������ǹ�������Ŀ
        unordered_map<int,int> sister;

        for(int i=0;i<candies.size();i++) {
            if(sister[candies[i]]++ == 0) {// ���û�ҵ�˵��sisiterû�������ǹ�
                result++;
                if(result == maxResult)// ���ﵽ������Ŀʱ�Ͳ��ٲ���
                    break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> candies = {1,1,2,3};
    int result = s.distributeCandies(candies);
    cout << result;
    return 0;
}
