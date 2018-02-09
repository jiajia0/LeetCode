#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;//��������
        int minPrice = INT_MAX;//��С�ļ۸�

        for(int i=0;i<prices.size();i++) {
            if(prices[i] < minPrice) {//�滻��С�ļ۸�
                minPrice = prices[i];
            }
            if(prices[i]-minPrice > maxProfit) {// �滻��������
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};*/

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;//��������
        int curProfit = 0;//��ǰ������

        for(int i=1;i<prices.size();i++) {
            curProfit = max(0,curProfit + prices[i] - prices[i-1]);//�������������������֮ǰ�������Ƕ���
            maxProfit = max(maxProfit,curProfit);//������������
        }
        return maxProfit;
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;//��������
        for(int i=0;i<prices.size();i++) {
            for(int j=i+1;j<prices.size();j++) {
                if(prices[j] - prices[i] > maxProfit) {
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};


int main() {
    Solution s;
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    int result = s.maxProfit(nums);
    cout << result;
    return 0;
}




