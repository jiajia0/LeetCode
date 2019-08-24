#include <iostream>
#include <cmath>
using namespace std;
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n/2 && n%2==0) {
            n /= 2;
        }
        return n == 1;
    }
};*/

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;

        double x = log10(n) / log10(2);
        return floor(x) == x;
    }
};*/

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n > 0 && 1073741824 % n == 0;
    }
};*/

// ��Ϊ2�Ĵη�������������λΪ1������Ϊ0 �� ��ȥ1֮�����λΪ0�������0��Ϊ1������֮��Ϊ0.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n&(n-1)) == 0;
    }
};

int main() {
    Solution s;
    bool ans = s.isPowerOfTwo(1);
    cout << ans;
    return 0;
}
