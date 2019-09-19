class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // ��С��positiveΪ1
        if(nums.size() == 0)
            return 1;
        for(int i = 0; i < nums.size();) {
            // ������������Ļ�����������ƶ�����Ϊ��ǰλ�ý�����֮����ܻ���Ҫ�ٴν���
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) {
                i++;
                continue;
            }
            
            // �ѵ�ǰλ���ϵ�value���ŵ�indexΪvalue-1��λ����ȥ
            int temp = nums[i]; // ��ǰλ���ϵ�Ԫ��
            nums[i] = nums[temp - 1]; // ��ǰλ���ϵ�������Ϊindex�����ҵ���Ӧ�����ֽ��н���
            nums[temp - 1] = temp;     
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
        
    }
};