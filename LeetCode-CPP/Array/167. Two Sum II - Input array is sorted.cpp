#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> m;
        if (!nums.empty()) {
            int i;
            for (i = 0; i < nums.size(); i++) {
                //if (m.find(nums[i]) == m.end()) {//��ʱmap�в����ڴ�hash
                if(!m.count(nums[i])) {
                    m[target-nums[i]] = i;
                } else {
                    ret.push_back(m[nums[i]] + 1);//��һ�����±�����
                    ret.push_back(i + 1);//��ʱ���±�����
                    return ret;
                }
            }
        }
        return ret;
    }
};*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int start = 0;//��ͷ��ʼ����
        int end = nums.size() - 1;//��β����ʼ����
        int sum;//��¼startλ�ú�endλ�õĺ�
        while(start < end) {//�����߿�ʼ���м俿��
            sum = nums[start] + nums[end];
            if(sum == target) {//�����ʱ��ȣ���˵���ҵ�����ȷ��λ��
                ret.push_back(start + 1);
                ret.push_back(end + 1);
                break;
            } else if (sum < target) {//�������λ��֮��С��Ŀ����������start����ƶ�һλ
                start++;
            } else {//������end��ǰ�ƶ�һλ
                end--;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);
    vector<int> ret = s.twoSum(num,9);
    cout << ret[0] << " " << ret[1];
}

