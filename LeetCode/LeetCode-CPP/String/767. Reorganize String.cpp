class Solution {
public:
    string reorganizeString(string S) {
        vector<int> l(26, 0);
        string res = "";
        res.resize(S.size());
        for(char ch : S) {
            l[ch-'a'] += 100;
        }
        // �����ҵ���ǰ���ĸ��ַ�
        for(int i = 0; i < 26; i++)
            l[i] += i;
        sort(l.begin(), l.end(), greater<int>()); // �Գ��ֵĴ�����һ����������
        int cur_index = 0; // ��¼��ǰ��䵽��һ��λ����
        int N = S.size();
        for(int i = 0; i < l.size(); i++) {
            int num = l[i] / 100;// ��ǰ�ַ����ֵĴ���
            char ch = 'a' + (l[i] % 100); // �õ���ǰ�ַ�
            //cout << ch << " " << num << endl;
            if(num > (N+1)/2)
                return "";
            for(int j = 0; j < num; j++) {
                if(cur_index >= N) // ��һ�������֮������Ϊ1����Ϊ0 2 4 �����ɣ� 1 3 5 ��û�����
                    cur_index = 1;
                res[cur_index] = ch;
                cur_index += 2;
            }
        }
        return res;
    }
};