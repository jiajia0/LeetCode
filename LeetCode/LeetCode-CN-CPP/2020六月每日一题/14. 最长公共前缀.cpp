class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string ans = strs[0]; // Ĭ�ϵ�һ���ַ���Ϊ����ǰ׺
        for(int i = 1; i < strs.size(); i++) {
            string temp_ans = "";
            // ���ڵ�ǰ��ǰ׺����һ���ַ������ҵ�����������Ϊ����ǰ׺
            for(int j = 0 ; j < min(strs[i].size(), ans.size()); j++) {
                if(ans[j] == strs[i][j]) {
                    temp_ans += ans[j];
                } else {
                    break;
                }
            }
            ans = temp_ans;
            if(ans == "") {
                break;
            }
        }
        return ans;
    }
};