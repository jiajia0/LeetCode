class Solution {
public:
    // ��Ҫ˼����δ洢hashmap
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> seen;
        int ans = 0;
        for(vector pair : dominoes) {
            int k = min(pair[0], pair[1]) * 10 + max(pair[0], pair[1]);
            if(seen.count(k)) {
                // ��key�Ѿ�����
                ans += seen[k];
            }
            seen[k]++;
        }
        return ans;
    }
};