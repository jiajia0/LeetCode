#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int> ans;//��������Ԫ�غ���һ�������λ��
        int r = matrix.size();//������
        int c = matrix[0].size();//������
        if(r == 1 || c == 1) {
            return true;
        }
        int i=0;
        while(i < c-1) {
            ans[i+1] = matrix[0][i];
            //cout << "��ǰԪ�أ�" << matrix[0][i] << "����һ��Ԥ�ڵ�����" << i+1 << endl;
            i++;
        }
        for(i=1;i<r;i++) {
            int j=c-1;
            while(j > 0) {//�Ƚ��������Ƿ���Ԥ�ڵ�һ��
                //cout << j << "," << ans[j] << "," << matrix[i][j] << endl;
                if(ans[j] == matrix[i][j]) {//���һ���������Ϣ
                    ans[j+1] = matrix[i][j];
                } else {
                    //cout << "quit" << i << "," << j;
                    return false;
                }
                j--;
            }
            ans[1] = matrix[i][0];//���µļ�������
        }
        return true;
    }
};*/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()-1;i++) {
            for(int j=0;j<matrix[0].size()-1;j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {5,1,2,3};
    vector<int> nums3 = {9,5,1,2};

    vector<vector<int>> matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);

    bool result = s.isToeplitzMatrix(matrix);
    cout << result;
    return 0;
}


