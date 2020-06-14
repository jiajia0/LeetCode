class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // bellman ford
        vector<int> c(n,INT_MAX);
        c[src] = 0;
        // ͣ��K�Σ�����ҪK+1����
        for(int i = 0; i <= K; i++) {
            vector<int> temp(c); // ����һ��������������
            for(auto e : flights) {
                // ������һ����ľ��� = min(Ŀǰ������һ����ľ��룬ԭ��������ת��+ ��ת�㵽��һ���� �ľ��� );
                int k = c[e[0]] == INT_MAX ? INT_MAX : c[e[0]] + e[2];
                temp[e[1]] = min(temp[e[1]], k); // �������еıߣ������������һ�������С����
            }
                
            c = temp; // ���¾���
        }
        return c[dst] == INT_MAX ? -1 : c[dst];
    }
};