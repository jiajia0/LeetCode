#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r = M.size();// ���������
        int c = M[0].size();// ���������

        int count = 0;// ����ͳ��ÿ��������Χ�ĸ���
        vector<vector<int>> ans(r,vector<int>(c));//����������

        for(int i=0; i < r; i++) {
            for(int j=0; j < c; j++) {
                count = 0;
                for(int r1=i-1;r1<=i+1;r1++) {//����ǰ������
                    for(int c1=j-1;c1<=j+1;c1++) {//����ǰ������
                        if(0<=r1 && r1 <r && 0<=c1 && c1<c) {//�����ָ����Χ�ڵĻ���
                            ans[i][j] += M[r1][c1];// ����������
                            count++;
                        }
                    }
                }
                //cout << ans[i][j] << "," << count << endl;
                ans[i][j] /= count;//��������
            }
        }
        return ans;
    }
};


int main() {
    Solution s;

    vector<vector<int>> M = {{1,1,1},{1,0,1},{1,1,1}};

    vector<vector<int>> result = s.imageSmoother(M);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
