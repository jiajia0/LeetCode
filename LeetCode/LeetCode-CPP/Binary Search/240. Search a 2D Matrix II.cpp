#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int n = matrix.size() >= matrix[0].size() ? matrix[0].size() : matrix.size(); // �жϳ��к�����һ������
        for(int i = 0; i < n; i++) {
            // �ӶԽ������Ҳ���
            int start = i, end = matrix[0].size() - 1;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                //cout << matrix[i][mid] << " ";
                if(matrix[i][mid] <= target) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            //cout << endl;
            if(matrix[i][start] == target)
                return true;
            if(matrix[i][end] == target)
                return true;
            // �ӶԽ������²���
            start = i, end = matrix.size() - 1;
            while(start + 1 < end) {

                int mid = start + (end - start) / 2;
                if(matrix[mid][i] <= target) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            if(matrix[start][i] == target)
                return true;
            if(matrix[end][i] == target)
                return true;
        }
        return false;
    }
};
*/

// �������Ϻ����½ǿ��ǣ����������������С�Ŀ���������Ҳ����������
// ���ӷ��Խ����ϵĵ㿼�ǣ���ȵ�С��ֻ�����л�������
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        // �����½ǿ�ʼ�����������½�С�ĵ�ֻ������һ�У�������ĵ�ֻ�����ұ�
        int j = 0;
        while(row >= 0 && j <= col) {
            if(matrix[row][j] == target) {
                return true;
            } else if(matrix[row][j] > target) { // ����һ��
                row--;
            } else { // ���ұ�
                j++;
            }
        }
        return false;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    Solution s;
    bool ans = s.searchMatrix(matrix, 23);
    cout << ans << endl;
    return 0;
}
