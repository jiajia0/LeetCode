#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {// �����ǰλ������½��
                    ans += 4;// Χ�������4
                    if(j < grid[0].size()-1 && grid[i][j+1] == 1)// ����ұ�Ҳ��½�صĻ�
                        ans -= 2;// Χ�������2
                    if( i < grid.size() - 1 && grid[i+1][j] == 1)// �������Ҳ��½�صĻ�
                        ans -= 2;// Χ�������2
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {{0,1,0,0},
 {1,1,1,0},
 {0,1,0,0},
 {1,1,0,0}};

    int result = s.islandPerimeter(grid);
    cout << result;
    return 0;
}
