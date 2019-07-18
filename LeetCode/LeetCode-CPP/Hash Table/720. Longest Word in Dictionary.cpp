#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        unordered_set<string> prefixes;
        for(string word: words)
            prefixes.insert(word);
        for(string word : words) {
            int flag = 1;
            string prefixe = "";
            for(int i = 0; i < word.size(); i++) {
                prefixe += word[i];
                if(prefixes.find(prefixe) == prefixes.end()) { // ˵����ǰǰ׺�ܹ��������������Ҳ���
                    if(i != word.size() - 1) { // ˵��û���ߵ���� , ����������
                        flag = 0;
                        prefixes.insert(word);
                        break;
                    } else  { // ˵���������һ���ַ�֮���������ܹ��ҵ������ʱӦ���Ƿ���
                        prefixes.insert(word);
                    }
                }
            }
            if(flag) {
                if(word.size() > ans.size())
                    ans = word;
                else if(word.size() == ans.size()) { // ����������ʳ�����ȣ���Ա����ǵ��ֵ�˳��
                    //cout << word << " " << ans << endl;
                    for(int i = 0; i < word.size(); i++) {
                        if(word[i] < ans[i]) {
                            //cout << word[i] << "," << ans[i] << endl;
                            ans = word;
                            break;
                        } else if(word[i] > ans[i])
                            break;;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    string ans = s.longestWord(words);
    cout << ans << endl;
    return 0;
}
