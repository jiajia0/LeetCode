#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueMorse;// ����Ħ˹���룬setȷ��Ψһ��

        // ����Ħ˹����
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};

        // �������еĵ���
        for(string word : words) {
            string morseForWord = "";// ���浥�ʵ�Ħ˹����
            for(char ch : word) { //������ת��Ϊ��Ӧ��Ħ˹����
                morseForWord += morse[ch - 'a']; // ��Ħ˹�����¼����
            }
            uniqueMorse.insert(morseForWord);
        }
        return uniqueMorse.size();
    }
};

int main() {
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    int result = s.uniqueMorseRepresentations(words);
    cout << result;
}
