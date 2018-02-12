#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;// ����ͳ�Ƶ�ǰ�������ֽ�
        int hold = -prices[0];// �������㵱ǰ�Ĺ�Ʊ
        for(int i=1; i<prices.size(); i++) {
            cash = max(cash, prices[i] + hold - fee);// �Ƚϵ�ǰ�ֽ�����������ͷ��Ʊ׬��������
            hold = max(hold,cash - prices[i]);// �Ƚϵ�ǰ�Ĺ�Ʊ����������Ʊ֮������ʣ�µ�Ǯ
        }
        return cash;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,3,7,5,10,3};

    int result = s.maxProfit(nums,3);
    cout << result;
    return 0;
}



