/*class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        vector<int> sum(nums.size(), 0); // sum[i] Ϊ�� [0,i]�ĺ�
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        
        for(int n  : sum)
            cout << n << " ";
        
        int res = 0;
        
        for(int start = 0; start < nums.size(); start++) {
            
            for(int end = start; end < nums.size(); end++) {
                //cout << sum[end] - sum[start] + nums[start] << endl;
                if(sum[end] - sum[start] + nums[start] == k)
                    res++;
            }
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++){
                sum += nums[end];
                if(sum == k)
                    res++;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> preSum;
        preSum[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // ��ȡ��ǰ�ĺ�
            // ������������˵��������һ��֮ǰλ���ϵ�sum ����ǰ��sum �м��ֵΪ k
            if(preSum.count(sum-k)) {
                res += preSum[sum-k];
            }
            preSum[sum]++; // ǰһ��sum�ĺͿ����ж�������Զ��֮ǰ��sum����ǰ��sum����Ϊk�����ԣ�������Ҫ����֮ǰ���п��ܵ�sum
        }
        return res;
    }
};