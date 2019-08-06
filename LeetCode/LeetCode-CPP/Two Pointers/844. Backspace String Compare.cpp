#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int Send = S.size() - 1;
        int Tend = T.size() - 1;
        int Scount = 0; // ͳ��
        int Tcount = 0;
        while(Send >= 0 || Tend >= 0) {
            // ��ѭ��������ʱ�򣬾���backspace ��ʣ�µ��ַ�
            while(Send >= 0) {
                if(S[Send] == '#') { // ͳ�ƿ���backspace �Ĵ���
                    Send--;
                    Scount++;
                } else if(Scount > 0) {  // ����backspace
                    Send--;
                    Scount--;
                } else
                    break;
            }

            while(Tend >= 0) {
                if(T[Tend] == '#') {
                    Tend--;
                    Tcount++;
                } else if(Tcount > 0) {
                    Tend--;
                    Tcount--;
                } else
                    break;
            }

            //cout << S[Send] << " " << T[Tend] << endl;

            if((Send >= 0) != (Tend >= 0)) // ���� bxj##tw bxj###tw �������ֹһ���ַ��������꣬��һ��û�б�����
                return false;


            if(Send >= 0 && Tend >= 0 && S[Send] != T[Tend])
                return false;

            Send--;
            Tend--;
        }
        return true;
    }
};

int main() {
    string S = "bbbextm";
    string T = "bbb#extm";
    Solution s;
    bool ans = s.backspaceCompare(S, T);
    cout << ans << endl;
    return 0;
}
