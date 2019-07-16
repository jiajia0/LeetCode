#include <iostream>
#include <unordered_map>

using namespace std;

/*Input:
"abccccdd"

Output:
7*/
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> alphabet;
        for(char ch : s)
            alphabet[ch]++;
        int flag = 1;
        for(auto it = alphabet.begin(); it != alphabet.end(); it++) {
            /*if(flag && (it->second == 1 || it->second % 2 == 1)) { // �����ڶ������ĸ�� ����Լ��뵽�����У���ֻ��һ��
                ans++;
                flag = 0;
            }*/
            if(ans % 2== 0 && it->second %2 ==1) // �����ڶ������ĸ�� ����Լ��뵽�����У���ֻ��һ�� , ans++֮�����������
                ans++;
            ans += (it->second/2)*2; // ͳ�ƳɶԵ��ַ�����
        }
        return ans;
    }
};

int main() {
    Solution s;
    string s1 = "abccccdd";
    int ans = s.longestPalindrome(s1);
    cout << ans;
    return 0;
}
