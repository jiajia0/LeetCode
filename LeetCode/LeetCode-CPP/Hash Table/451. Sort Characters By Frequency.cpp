#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> chCount;// ͳ�Ƹ�����ĸ���ֵĴ���
        string ans;

        for(char c : s) chCount[c]++;

        map<int,string> bucket;// ʹ��map��ԭ���ǣ�map�Ѿ����������

        for(auto it : chCount) {
            char ch = it.first;
            int n = it.second;
            bucket[n] += string(n,ch);// ��ӵ�map�У������ͳ��λ���Ѿ���Ԫ���ˣ���ӵ���λ����
        }

        // ��β��ͷ��������ʱ�Ѿ��������
        for(auto rit = bucket.rbegin();rit != bucket.rend();rit++) {
            ans += rit->second;
        }

        return ans;
    }
};

int main() {
    Solution s;
    string word = "tree";
    string result = s.frequencySort(word);
    cout << result;
    return 0;
}
