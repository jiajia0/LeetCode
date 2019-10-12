/*
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 0) {
                count++;
                // �������ȫ��0�����
                if(i == seats.size() - 1 && count >= ans)
                    ans = count;
            } else {
                if(count >= ans) {
                    if(i == count) {// ����տ�ʼȫ��0�����
                        ans = count;
                    } else {
                        ans = max(int(ceil(count / 2.0)), ans);
                    }
                }
                count = 0;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        // ���������ȫ��0�����
        res = max(res, n - last - 1);
        return res;
    }
};