class Solution {
public:
    bool isPalindrome(string s, int low, int high) {
        for(low;low < high; low++, high--) {
            if(s[low] != s[high])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i = 0 ; i < s.length() / 2; i++) {
            // �����ǰ��ƥ��Ļ����ֱ�ȥ����ߵĻ��ұߵĽ��м��
            if(s[i] != s[s.length() - 1 - i]) {
                return isPalindrome(s, i, s.length() - 1 - i - 1) || isPalindrome(s, i + 1, s.length() - 1 - i);
            }
        }
        return true;
    }
};