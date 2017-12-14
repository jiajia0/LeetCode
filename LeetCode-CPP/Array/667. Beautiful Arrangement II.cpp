#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);//����һ��n��Ԫ�ص�����
        int num=0;//������±�

        //����ǰ�벿�֣�ֻ�����1�ֽ��
        for(int i=1; i < n-k; i++) {
            result[num++] = i;
        }

        //�����벿�֣��ܹ�����k-1�ֽ��
        for(int i=0; i <= k; i++) {
            //������±�Ϊż����ȡ��һ����������ȡ���һ����
            result[num++] = (i%2 == 0) ? (n-k + i/2) : (n - i/2);
        }

        return result;

    }
};*/

class Solution{
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) res.push_back(k-- % 2 ? i++ : j--);
            else res.push_back(i++);
        }
        return res;
    }
};


int main() {
    Solution s;

    vector<int> n = s.constructArray(6,5);
    int i;
    for(i=0;i<n.size();i++) {//�����е����ַŵ�һ��������
        std::cout << n[i] << std::endl;
    }
    return 0;
}

