/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = 0, count = 1;
        for(int i = 1; i < nums.size(); i++) {
            // ������ͬ�Ĵ�������û�г������Σ���n����ƶ�
            if(nums[n] == nums[i] && count < 2) {
                n++;
                nums[n] = nums[i]; 
                count++;
            } else {
                // ��ʱ��Ҫ������ǰ����ͬ�ĳ��������λ���һ��
                if(nums[n] != nums[i]) {
                    n++;
                    nums[n] = nums[i];
                    count = 1;
                }
            }
        }
        return n + 1;
    }
};
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums) {
            // ǰ������Ȼ������������������
            if(i < 2 || n > nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};