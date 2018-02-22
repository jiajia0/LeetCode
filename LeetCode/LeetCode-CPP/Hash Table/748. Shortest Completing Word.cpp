#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int minLengthIndex = 0;
        vector<char> license;// �������licensePlate�й��ж��ٸ���ĸ
        unordered_map<char,int> word;// ������ŵ��ʲ��֮�����ĸ
        int minLength = INT_MAX;// ������¼��С�ĵ���λ��
        int curLength = 0;// ������¼��ǰ���ʵĳ���
        int isExist = true;

        for(char ch : licensePlate) {
            ch = tolower(ch);// �����ΪСд
            if(ch >= 'a' && ch <= 'z') {// ������ĸ��Χ��
                license.push_back(ch);
            }
        }

        for(int i=0;i<words.size();i++) {
            curLength = 0;
            isExist = true;
            word.clear();// ���
            for(char ch : words[i]) {// �����ʲ�⿪������hash����
                curLength++;
                ch = tolower(ch);
                word[ch]++;
            }
            for(char ch : license) {// ����licensePlate��������ĸ
                if(word[ch]-- == 0) {// ˵�������ĸ�ڵ�����û�г��ֹ�
                    isExist = false;// ������
                    break;// ����ѭ��
                }
            }

            if(isExist) {// ���������Ƚϳ���
                if(curLength < minLength) {
                    minLength = curLength;
                    minLengthIndex = i;
                }
            }
        }
        return words[minLengthIndex];
    }
};

int main() {
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step","steps","stripe","stepple"};
    string result = s.shortestCompletingWord(licensePlate,words);
    cout << result;
    return 0;
}
