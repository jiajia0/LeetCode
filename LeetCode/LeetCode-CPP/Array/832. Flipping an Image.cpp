#include <iostream>
#include <vector>

using namespace std;

// Plan A
/*class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        if(A.size()==0 || A[0].size()==0)
            return A;

        int p1,p2;
        int i=0,j=0,temp;

        while(i < A.size()) {

            p1=0,p2=A[0].size()-1;// �ֱ���������м����ɨ��

            while(p1 <= p2) {
                temp = A[i][p1];// ��¼��ǰ��λ���ϵ�����
                A[i][p1] = 1-A[i][p2];//�����Ӧ����λ��Ϊ0����ǰ������Ϊ1����������Ϊ0
                A[i][p2] = 1-temp;//ǰ��Ϊ0����������Ϊ1����֮Ϊ0.
                p1++;
                p2--;
                if(p1 == p2) {//ֻʣ���м��һ������
                    A[i][p1] = 1-A[i][p1];
                    break;
                }
            }
            i++;
        }
        return A;
    }
};*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i){
            int begin = 0;
            int end = A[0].size()-1;
            while (begin < end){
                if(A[i][begin] == A[i][end]){// ���ǰ��ͺ�����ȣ���ʱ��Ҫ���ж�1�������
                    A[i][begin] ^= 0X1;
                    A[i][end] ^= 0X1;
                }
                ++begin;
                --end;
            }
            if(begin == end) A[i][begin] ^=1;
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A = {{1,1,0,0},{1,0,0,1},{1,0,1,0}};
    vector<vector<int>> result = s.flipAndInvertImage(A);

    int i,j;
    for(i=0;i<result.size();i++) {
        for(j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl ;
    }
    return 0;
}
