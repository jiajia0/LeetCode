#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int startNum = matrix[0][0];//��С����
        int endNum = matrix[n-1][n-1];//������
        int midNum;//�������ֵ����Сֵ����
        int cnt = 0;
        while (startNum < endNum) {
            midNum = (startNum + endNum) / 2;//�õ��м����ֵ
            cnt = 0;
            //cout << midNum << "," <<startNum << "," << endNum << endl;
            for(int i=0;i<n;i++) {
                //cout << "i:" << i << "," << *(upper_bound(matrix[i].begin(), matrix[i].end(), midNum)) << "," << *(matrix[i].begin()) << "," << (upper_bound(matrix[i].begin(), matrix[i].end(), midNum) - matrix[i].begin()) << endl;
                cnt += (upper_bound(matrix[i].begin(), matrix[i].end(), midNum) - matrix[i].begin());
                cout << "cnt :" << cnt << endl;
            }

            if(cnt < k) {
                startNum = midNum + 1;
            } else {
                endNum = midNum;
            }
            cout << endl;
        }
        cout << endNum;
        cout << startNum;
        return endNum;
    }
};

/*class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> number;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                number.push_back(matrix[i][j]);
            }
        }

        sort(number.begin(), number.end());

        return number[k - 1];
    }
};*/

// error �� ���յĴ���start �� end ֮�䣬 ���޷�ȷ����������һ��
/*class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        int cnt = 0;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            cnt = 0; // ��¼��midС�����ָ���
            for(int i = 0; i < n; i++) {
                //cout << (lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin()) << endl;
                cnt += (lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin()); // �������i���ж��ٸ���midС������
            }
            //cout << mid << " " << cnt << endl;
            if(cnt < k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        cout << cnt << endl;
        cout << start << " " << end << endl;
        return cnt >= k ? start : end;
    }
};*/

int main() {
    Solution s;
    vector<vector<int>> martrix;
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;

    a1.push_back(1);
    a1.push_back(2);
    //a1.push_back(9);

    a2.push_back(1);
    a2.push_back(3);
    //a2.push_back(13);

    //a3.push_back(12);
    //a3.push_back(13);
    //a3.push_back(15);

    martrix.push_back(a1);
    martrix.push_back(a2);
    //martrix.push_back(a3);

    int ans = s.kthSmallest(martrix, 3);
    cout << ans;
}
