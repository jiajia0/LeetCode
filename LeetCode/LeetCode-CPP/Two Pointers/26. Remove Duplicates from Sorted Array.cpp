class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        // n��i��һλ
        int n = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[n] != nums[i]) {
                n++;
                nums[n] = nums[i];
            }
        }
        // ����ĳ���Ҫ��index��һ
        return n + 1;
    }
};