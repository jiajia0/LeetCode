/*class Solution {
public:
    
    int res = 0;
    int path = 0;
    
    int x_y_1[2] = {-1,1};
    int x_y_2[2] = {-2,2};
    
    //vector<vector<bool>> v; //m*n�Ķ�άvector��ע������ "> "֮��Ҫ�пո�
    map<int,map<int,bool>> v;
    void dfs(int cur_x, int cur_y, int target_x, int target_y) {

        if(cur_x > 0 && cur_x > target_x)
            return;
        if(cur_y > 0 && cur_y > target_y)
            return;
        if(cur_x < 0 && cur_x < target_x)
            return;
        if(cur_y < 0 && cur_y < target_y)
            return;
        
        
        if(cur_x == target_x && cur_y == target_y) {
            cout << path << endl;
            res = path; 
            //return;
        }
            
        
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                    if(v[cur_x + x_y_1[i]][cur_y + x_y_2[j]] == false) {
                        v[cur_x + x_y_1[i]][cur_y + x_y_2[j]] = true;
                        path++;
                        dfs(cur_x + x_y_1[i], cur_y + x_y_2[j], target_x, target_y);
                        v[cur_x + x_y_1[i]][cur_y + x_y_2[j]] = false;
                        path--;
                    }
                
                    if(v[cur_x + x_y_2[i]][cur_y + x_y_1[j]]  == false) {
                        v[cur_x + x_y_2[i]][cur_y + x_y_1[j]]  = true;
                        path++;
                        dfs(cur_x + x_y_2[i], cur_y + x_y_1[j], target_x, target_y);
                        v[cur_x + x_y_2[i]][cur_y + x_y_1[j]]  = false;
                        path--;
                    }
            }
        }
        
        path--;
        
    }
    
    int minKnightMoves(int x, int y) {
        //for(int i = 0; i < v.size(); i++) {
            //v.push_back(new vector<bool>(300, false));
        //}
        dfs(0, 0, x, y);
        return res;
    }
};*/

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0)
            return 0;
        int x_y_1[2] = {-1,1};
        int x_y_2[2] = {-2,2};
        map<int, map<int,bool>> visited;
        queue<vector<int>> q;
        q.push({0, 0});
        int res = 0; // ��¼���
        while(!q.empty()) {
            int size = q.size();
            res++;
            while(size--) {
                vector<int> temp =  q.front();
                //cout << temp[0] << " " << temp[1] << endl;
                q.pop();
                // ÿһ������˸�������
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        int next_x = temp[0] + x_y_1[i]; // x ȡ 1 ����
                        int next_y = temp[1] + x_y_2[j]; // y ȡ 2 ����
                        if(next_x == x && next_y == y) // ����һ������ָ���ص�
                            return res;
                        // next_x * x >= 0 �ܹ���֤ǰ���ķ�����Ŀ�귽��һ�£� = 0 ������x����
                        if(visited[next_x][next_y] == false && next_x * x >= 0 && next_y * y >= 0) { // ����һ��û�з��ʹ�������������
                            visited[next_x][next_y] = true;
                            q.push({next_x, next_y});
                        }
                        // x ȡ 2 ���ϣ� y ȡ 1 ���� 
                        next_x = temp[0] + x_y_2[i];
                        next_y = temp[1] + x_y_1[j];
                        if(next_x == x && next_y == y)
                            return res;
                        if(visited[next_x][next_y] == false && next_x * x >= 0 && next_y * y >= 0) { // ����һ��û�з��ʹ�������������
                            visited[next_x][next_y] = true;
                            q.push({next_x, next_y});
                        }
                    }
                }
            }
        }
        return res;
    }
};