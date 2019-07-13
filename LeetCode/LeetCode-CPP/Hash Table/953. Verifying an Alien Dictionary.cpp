#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // ����ĸ��Ϊmap��ʽ��a : 0 , b : 1�� ����Աȴ�С
        unordered_map<char, int> alphabet;
        int i = 0;
        while(i < 26) {
            alphabet[order[i]] = i;
            i++;
        }

        for(i = 0; i < words.size() - 1; i++) {
            string word1 = words[i]; // ��һ������
            string word2 = words[i + 1]; // �ڶ�������

            int flag = 1;

            // �ҵ���һ����һ������ĸ
            for(int j = 0; j < min(word1.size(), word2.size()); j++) {
                if(word1[j] != word2[j]) {
                    if(alphabet[word1[j]] < alphabet[word2[j]]) { // ������sorted�� ������һ��
                        flag = 0;
                        break;
                    } else
                        return false;
                }
            }

            if(word1.size() > word2.size() && flag) // 'apple' > 'app' return false
                return false;

        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words = {"kuvp", "q"};
    string order = "ngxlkthsjuoqcpavbfdermiywz";
    bool ans = s.isAlienSorted(words, order);
    cout << ans;
    return 0;
}
