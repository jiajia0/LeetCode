#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;// �����������Ĵ�
        vector<int> comb;// �������浱ǰ�ķ���
        combination(ans,comb,k,1,n);
        return ans;
    }

    // �ݹ����
    void combination(vector<vector<int>>& ans,vector<int>& comb,int k,int start,int n) {
        // �����ʱcomb�е�Ԫ�ظ����Ѿ�������Ҫ�ģ����ߴ�ʱĿ����Ϊ0�������ݹ�
        if(k == 0 && n == 0) {
            ans.push_back(comb);
            return;
        }
        for(int i = start; i <= 10-k&&i<=n; i++) {
            comb.push_back(i);
            combination(ans,comb,k,i+1,n-i);
            comb.pop_back();
        }
    }

};


int main() {
    Solution s;

    vector<vector<int>> result = s.combinationSum3(3,9);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




