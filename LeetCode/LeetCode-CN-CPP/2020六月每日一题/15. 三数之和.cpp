class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // ���Ƚ�������
        for(int a = 0; a < nums.size(); a++) { // ��ȷ��һ��a��Ȼ���ҳ���aȷ���µ�����b��c���
            if(a > 0 && nums[a] == nums[a - 1]) { // �����ǰ��a�Ѿ����ҹ��ˣ�����
                continue;
            }
            int c = nums.size() - 1; // a+b+c=0ʱ����aȷ���ˣ�b����ѭ���������Ҫ���㹫ʽ����c����ѭ����С������c�Ӻ��滹�Ǳ���
            for(int b = a + 1; b < nums.size(); b++) { // ��ȷ��һ��b , ��ʱȷ����a��b��Ȼ���ҵ����з���������c
                if(b > a + 1 && nums[b] == nums[b - 1]) { // �����ǰ��a��b�Ѿ����ҹ��ˣ�����
                    continue;
                }
                // c��λ�ò����ܱ�bС�������ʱa+b+c>0��˵��c������ҪСһ��
                while(b < c && nums[a] + nums[b] + nums[c] > 0) {
                    c--;
                }
                // ��������while������b==c or a+b+c <= 0
                // �����b==c ��˵��b��������е�c����a+b+c>0����������b�����󣬺������е�ʽ�Ӷ���>0
                if(b == c) {
                    break;
                }
                // ����������<0ʱ���ô�����Ϊ����b������ܾ�������
                if(nums[a] + nums[b] + nums[c] == 0) {
                    ans.push_back({nums[a],nums[b],nums[c]});
                }
            }
        }
        return ans;
    }
};