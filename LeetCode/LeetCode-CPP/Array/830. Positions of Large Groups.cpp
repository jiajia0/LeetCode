#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int count=1;
        for(int i=0,j=1;i<S.length();i++,j++) {
            if(S[i] == S[j]) {// �������������ĸ��ȣ���ͳ����Ŀ��һ
                count++;
            } else {
                if(count >= 3) { // ���������������3�����������
                    //cout << "i:" << i << ",count:" << count;
                    vector<int> temp = {i-count+1,i};
                    result.push_back(temp);
                }
                count=1;
            }
        }
        return result;
    }
};*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start=0, end=0, n=S.size();
        vector<vector<int>> res;
        while(end<n)
        {
            while(end<n && S[end]==S[start])// �����ǰ���ַ������ʼ���ַ�����һֱ���Ѱ��
                end++;
            if(end-start>=3) { // ���֮�䳤�ȴ���3���������
                res.push_back({start,end-1});
                //cout << "start:" << start << ",end:" << end << endl;
            }
            start=end;// ������ʼ��λ��
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "abcdddeeeeaabbbcd";
    vector<vector<int>> result = s.largeGroupPositions(str);
    int i,j;
    for(i=0;i<result.size();i++) {
        for(j=0;j<result[0].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
