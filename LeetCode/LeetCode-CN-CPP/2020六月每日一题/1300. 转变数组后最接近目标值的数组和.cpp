class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // �Ƚ�������
        vector<int> prefix; // prefix ��i�������arr��i��i֮ǰ�ĺ�
        for(int i = 0; i < arr.size(); i++) {
            int sub_sum = i == 0 ? arr[i] : arr[i] + prefix[i-1];
            prefix.push_back(sub_sum);
            //cout << prefix[i] << " ";
        }
        
        int ans = 0;
        int max = *max_element(arr.begin(), arr.end()); // �õ������е����ֵ
        int diff = target; // ����Ŀǰ�Ĳ�࣬��ʼֵΪ���Ŀ��ܲ��

        // �𰸻���1-max֮��
        for(int i = 1; i <= max; i++) {
            int loc = lower_bound(arr.begin(), arr.end(), i) - arr.begin(); // �ҵ����ڻ��ߵ���i�ĵ�һ��λ��
            int cur = loc == 0 ? arr.size() * i :  prefix[loc - 1] + (arr.size() - loc) * i; // ����滻�����ֵ��С
            //cout << "cur:" << cur << ", loc "<< loc << " i:" << i << " " << ", prefix:" << prefix[loc];
            if(abs(cur - target) < diff) {
                diff = abs(cur - target);
                ans = i;
            }
        }
        return ans; 
    }
};