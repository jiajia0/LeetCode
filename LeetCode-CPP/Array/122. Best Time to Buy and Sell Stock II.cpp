#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int peak, valley ;
        peak = valley = prices[0];
        int maxProfit = 0;
        int i=0;
        while(i < prices.size()-1) {
            while(i<prices.size()-1 && prices[i] >= prices[i+1]) {//�ҵ��۸���͵���һ��
                i++;
            }
            valley = prices[i];
            while(i<prices.size()-1 && prices[i] <= prices[i+1]) {//�ҵ���������ļ۸�ߵ�һ��
                i++;
            }
            peak = prices[i];
            maxProfit += peak - valley;//�����ʱ������
        }
        return maxProfit;
    }
};

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i=1; i<prices.size();i++) {
            if(prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};*/

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);

    int result = s.maxProfit(nums);
    cout << result;
    return 0;
}



