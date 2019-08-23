#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// Time Limit
/*
class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> status(n + 1, 1);
        status[0] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j<= n; j++) {
                if(j % i == 0)
                    status[j] = !status[j];
            }
        }
        return accumulate(status.begin(), status.end(), 0);
    }
};*/

/*
��i�����ݰ��µĴ��������ڵ�i�����ݵ����Ӹ���������6 = 1 * 6 = 2 * 3 �����Էֱ���ڵ�1�֡���2�֡���3�֡���6�ֻᰴ�¡�
�տ�ʼ�ĵ���״̬Ϊoff�������ڰ��������κ����on��
��һ������Ϊƽ�����Ļ�����ô�������ӱ�Ȼ�ǳɶԳ��ֵģ�����6��7��5��
��һ����Ϊƽ������������������ͬ���ӵ�������Ӷ����»�������������ӣ����� 16 = 1*16=2*8=4*4������1��2��4��8��16 һ��5������
���磺9=1*9=3*3��1��3��9���������ӡ�
����ͳ��1-n֮���ж���ƽ�������ɣ�ֱ�Ӷ�n���п�������С��sqrt(n)�����ֵ�ƽ������n�ķ�Χ֮�ڣ�������Щ������ƽ������
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return (int) sqrt(n);
    }
};

int main() {
    Solution s;
    int ans = s.bulbSwitch(16);
    cout << ans << endl;
    return 0;
}
