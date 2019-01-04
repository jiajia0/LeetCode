#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_A=0;
        int sum_B=0;
        for(int i=0;i<A.size();i++)
            sum_A += A[i];
        for(int j=0;j<B.size();j++)
            sum_B += B[j];
        int diff = (sum_A-sum_B)/2;
        unordered_set<int> hashset(B.begin(),B.end());
        for (int i =0;i<A.size();i++)
        {
            if ((A[i]-diff)>=1)
            {
                auto elem = hashset.find(A[i]-diff);
                if (elem != hashset.end())
                {
                    vector<int> result {A[i], *elem};
                    return result;
                }
            }
        }
    }
};

/*class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int Asum=accumulate(A.begin(),A.end(),0);//�����AB���ܺ�
        int Bsum=accumulate(B.begin(),B.end(),0);

        int diff = (Asum - Bsum)/2;//�����A��ƽ��ֵ֮��Ĳ���Ƕ��٣���ͬ�����������
        //int diff = Asum - (Asum + Bsum)/2;

        for(int i : A) {
            if(find(B.begin(),B.end(),i-diff)!=B.end()) {// ���A�е�Ԫ�ؼ�ȥ�����ֵ������B�е�ĳ��Ԫ�أ���������Ԫ�ػ�����A��B������ƽ��ֵ
                res.push_back(i);
                res.push_back(i-diff);
                break;
            }
        }

        return res;
    }
};*/

int main() {
    Solution s;
    vector<int> A = {1,2,5};
    vector<int> B = {2,4};
    vector<int> ret = s.fairCandySwap(A,B);
    cout << ret[0] << "," << ret[1];
    return 0;
}
