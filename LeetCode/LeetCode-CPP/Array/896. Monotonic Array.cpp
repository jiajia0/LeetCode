#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        if(A.size() == 1)
            return true;

        int i=1;
        bool increase=false;
        bool decrease=false;
        while(i<A.size()) {
            if(A[i] == A[i-1]) {
                i++;
                continue;
            }

            if(A[i] > A[i-1]){//����
                if(increase==false&&decrease==true)
                    return false;
                increase = true;
                decrease = false;
            }else {
                if(decrease==false&&increase==true)
                    return false;
                decrease = true;
                increase = false;
            }
            i++;
        }
        return true;
    }
};*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        int sign = 0;//��¼�ϴεı仯
        int n = A.size();
        for (int i = 0; i < n - 1; i++) {
            int new_sign;
            if (A[i+1] > A[i])
                new_sign = 1;
            else if (A[i+1] < A[i])
                new_sign = -1;
            else
                new_sign = 0;

            if (new_sign != 0 && new_sign == -sign)//��������˱仯��������֮ǰ�ı仯�෴�򷵻�false
                return false;

            if (sign == 0)//�����һ�δ����Ų��䣬�����Ϊ��һ�εı仯
                sign = new_sign;
        }
        return true;
    }

};

int main() {
    Solution s;
    vector<int> A = {1,1,0};
    bool ret = s.isMonotonic(A);
    cout << ret;
    return 0;
}
