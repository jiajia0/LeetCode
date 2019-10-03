class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> nums(26, INT_MAX); // ����ͳ�����е����У�ÿ����ĸ���ֵ����ٴ���
        vector<string> res;
        for(string str : A) {
            vector<int> cnt(26, 0);
            for(char ch : str) { // ͳ�Ƶ�ǰ���ʸ�����ĸ���ֵĴ���
                cnt[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                nums[i] = min(cnt[i], nums[i]); // ��¼��26����ĸ���ִ������ٵ�
            }
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < nums[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};