#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int temp = left;
        vector<int> result;
        for(int num=left;num<=right;num++) {// ��ָ����Χ��ѭ��
            temp = num;
            if(!(temp%10)) { // �ж��Ƿ�����10��20��300����
                continue;
            }
            while(temp && num%(temp%10) == 0) {// �����ǰλ�����������ͼ�����̽��һλ
                temp /= 10;
                if(temp%10==0){ \\ �ж��Ƿ�����101��203���ֵ�
                    break;
                }
            }
            if(temp == 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int temp = left;
        int mod;
        vector<int> result;
        for(int num=left;num<=right;num++) {// ��ָ����Χ��ѭ��
            temp = num;

            while(temp) {
                mod = temp%10; // �����ʱ������
                if(mod==0 || num%mod!=0)// �����ʱ��������0˵����10�ı������˳��������ʱ����������Ҳ�˳�
                    break;
                temp /= 10;
            }

            if(temp == 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.selfDividingNumbers(1,22);
    for(int i : result) {
        cout << i << ",";
    }
    return 0;
}
