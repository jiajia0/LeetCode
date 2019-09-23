class Solution {
public:
    vector<int> indexs; // ���ͬһ�����index
    vector<bool> visited; // ����ַ����е��ַ��Ƿ���ʹ�
    vector<vector<int>> same_group; // ���ͬһ����ͨ���index
    string sort_string; // �������ͬһ����ͨ���е��������ַ���
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        same_group.resize(s.size()); // ����Ҫ����Ϊs�ĳ��ȣ���Ϊpairs��Ӧ���±귶ΧΪs����
        visited.resize(s.size(), false);
        
        // ���з��飬union ������!!!
        for(vector<int>& v : pairs) {
            same_group[v[0]].push_back(v[1]);
            same_group[v[1]].push_back(v[0]);
        }
        
        /*
        for(vector<int> v : same_group) {
            for(int n : v)
                cout << n << " ";
            cout << endl;
        }*/
        
        queue<int> q; // ����ʵ��union�����������ŵ��� 2 �� ��ȥ�ҵ�2����û�з��ʹ���index
        
        for(int i = 0; i < s.size(); i++) {
            if(visited[i]) // ���ʹ���ֱ������
                continue;
            sort_string = "";
            indexs.clear();
            
            q.push(i); // �Ե�ǰindex��ʼ����̽������������
            while(!q.empty()) {
                int start = q.front();
                q.pop();
                
                if(!visited[start]) {
                    sort_string += s[start];
                    indexs.push_back(start);
                    visited[start] = true;
                }
                
                
                
                for(int n : same_group[start]) {
                    if(!visited[n])
                        q.push(n);
                }
            }
            
            sort(sort_string.begin(), sort_string.end()); // ��������ַ���������
            sort(indexs.begin(), indexs.end()); // ������������������
            //cout << endl << sort_string << endl;
            // ��s�ַ����е�������ַ���������
            for(int k = 0; k < indexs.size(); k++) {
                s[indexs[k]] = sort_string[k];
            }
            //cout << s << endl;
        }
        
        return s;
    }
};