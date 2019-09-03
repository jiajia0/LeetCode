/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> ha;
        vector<int> ans;
        for(int n : nums) {
            ha[n]++;
        }
        for(auto it=ha.begin();it!=ha.end();it++) {
            if(it->second == 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};
*/
// ���е����ֽ���������֮����ͬ��������Ȼ����Ϊ0.
// ��ͬ���������ֽ�������ڲ�Ϊ0��λ���ϣ�Ҳ����1��λ���ϣ��������������õ���1�������ڸ�λ����һ��Ϊ1��һ��Ϊ0��
// ����ֻҪ�������1�����������ֱַ������򼴿ɡ�
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        vector<int> res(2,0);
        for(int i : nums)
            diff ^= i;
        diff &= -diff; // ��ȡ�����һ��1
        int a = 0, b = 0;
        for(int i : nums)
            if((diff & i) == 0)
                a ^= i;
            else
                b ^= i;
        res[0] = a;
        res[1] = b;
        return res;
    }
};
