/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash;
        vector<int> al(256, 0);
        for(int i = 0; i < s.length(); ++i) {
            // �����ǰs[i]��û��ӳ��
            if(!hash.count(t[i]) && !al[s[i]]) {
                hash[t[i]] = s[i];
                al[s[i]] = 1;
            } else {
                if(hash[t[i]] != s[i])
                    return false;
            }
        }
        
        return true;
    }
};
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(int i = 0; i < s.length(); i++) {
            if(m1[s[i]] != m2[t[i]])
                return false;
            // i + 1 ��Ϊ�˱������0 ,��Ϊ hashĬ��Ϊ0
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};