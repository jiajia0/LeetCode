class Solution {
public:
    // ����ָ�룬һ��ָ����Ҫ������λ�ã�һ�����Ѱ�ҿ��Խ�����Ԫ��
    int removeElement(vector<int>& nums, int val) {
        int n=0;
        for(int i = 0; i < nums.size(); i++) {
            // ���н���
            if(nums[i] != val) {
                swap(nums[i], nums[n]);
                n++;
            }
        }
        return n;
    }
};