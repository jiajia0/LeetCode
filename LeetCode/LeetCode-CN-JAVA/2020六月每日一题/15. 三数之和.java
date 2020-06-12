class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int n = nums.length;
        // ȷ��a֮�󣬲�������b��c�����
        for(int a = 0; a < n && nums[a] <= 0; a++) {
            if(a > 0 && nums[a] == nums[a - 1]) { // ���a�Ѿ����ҹ��ˣ���ֱ������
                continue;
            }
            int c = n - 1;
            // ȷ��a��b���������з���������c
            for(int b = a + 1; b < n && nums[a] + nums[b] <= 0 ; b++) {
                if(b > a + 1 && nums[b] == nums[b - 1]) { // ���b���ҹ����ٲ���
                    continue;
                }
                while(b < c && nums[a] + nums[b] + nums[c] > 0) {
                    c--;
                }
                // b==c˵��b���������c������a+b+c>0����ô����b��c�����ӣ��򲻻����a+b+c==0�����
                if(b == c) {
                    break;
                }
                // <0��������Ϊ�������ź��b�������������
                if(nums[a] + nums[b] + nums[c] == 0) {
                    ArrayList<Integer> subans = new ArrayList<>();
                    subans.add(nums[a]);
                    subans.add(nums[b]);
                    subans.add(nums[c]);
                    ans.add(subans);
                }
            }
        }
        return ans;
    }
}