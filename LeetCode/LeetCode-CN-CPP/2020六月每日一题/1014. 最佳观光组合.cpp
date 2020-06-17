class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // ��A[i] + A[j] + i - j �ֽ�Ϊ��A[j] - j + A[i] + i
        int ans = 0;
        int mx = A[0] + 0; // ��¼����A[i] + i;
        for(int i = 1; i < A.size(); i++) {
            mx = max(mx, A[i - 1] + i - 1); // ��¼����A[i] + i
            ans = max(ans, A[i] - i + mx); // ��Ե�ǰj��˵����������A[i] + i + A[j] - j
        }
        return ans;
    }
};