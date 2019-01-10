#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--) { // �Ӻ���ǰλ�����μ�һ
            digits[i]++;// ��ǰλ��һ
            if(digits[i]==10) {// �����Ҫ��λ
                digits[i]=0;// ����ǰλ��Ϊ0
                if(i==0) // ����ǵ�һλ���һ���Ҫ��λ��������ǰ�����һ��1������ 9��99
                    digits.insert(digits.begin(),1);
            } else {//�������λ����ֱ�ӷ��ؼ�һ�������
                return digits;
            }
        }
        return digits;
    }
};

// �����ô���
/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end=digits.size();
        long long sum=0,n=1;
        vector<int> result;
        while(end--) { // ����������õ�ԭ��������
            sum += digits[end]*n;
            n *= 10;
        }
        sum++;// plus one
        while(sum) {
            result.insert(result.begin(),sum%10);
            sum /= 10;
        }
        return result;
    }
};*/

int main() {
    Solution s;
    vector<int> digits = {9,8,7,6,5,4,3,2,1,0};

    vector<int> result = s.plusOne(digits);

    for(int num : result)
        cout << num << " ";

    return 0;
}
