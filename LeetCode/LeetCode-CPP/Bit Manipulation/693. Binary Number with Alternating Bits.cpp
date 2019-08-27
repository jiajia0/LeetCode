#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n & 1; // ��¼ǰһ����1����0
        n = n >> 1;
        while(n) {
            int cur = n & 1; // ��¼��ǰ����1����0
            if(cur == pre)
                return false;
            n = n >> 1;
            pre = cur;
        }
        /*
        int flag = -1;
        while(n) {
            if(flag == -1) {
                flag = n&1;
            } else {
                if(flag == 1 && (n&1)) { // ǰһ��Ϊ1�����ڵ�ҲΪ1��return false
                    return false;
                }
                if(flag == 0 && !(n&1)) { // ǰһ��Ϊ1�����ڵ�ҲΪ0
                    return false;
                }
            }
            flag = (n & 1);
            n = n >> 1;
        }*/
        return true;
    }
};

int main() {
    Solution s;
    bool ans = s.hasAlternatingBits(10);
    cout << ans;
    return 0;
}
