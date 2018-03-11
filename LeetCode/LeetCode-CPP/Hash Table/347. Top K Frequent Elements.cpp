#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size() || nums.size()==k) return nums;

        unordered_map<int,int> frequentMap;// ����ͳ��ÿ��Ԫ�س��ֵ�Ƶ��
        for(int i=0;i<nums.size();i++)
            frequentMap[nums[i]]++;// ����ͳ��

        vector<vector<int>> bucket(nums.size()+1);// ����һ��Ͱ
        for(auto kv : frequentMap) {// ����ͳ������
            bucket[kv.second].push_back(kv.first);// �������Ͱ��
        }

        vector<int> result;
        for(int i=bucket.size()-1;i>=0;i--) {
            for(int j=0;j<bucket[i].size();j++){
                if(!k) return result;// ����Ѿ��ҳ������е�K������ֱ�ӷ���
                result.push_back(bucket[i][j]);
                k--;
            }
        }
        return result;
    }
};


/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size() || nums.size()==k) return nums;
        unordered_map<int,int> frequentMap;// ����ͳ��Ƶ��
        for(int i=0;i<nums.size();i++)
            frequentMap[nums[i]]++;// ����ͳ��

        vector<int> result;
        priority_queue<pair<int,int>> pq;// ʹ�����ȶ��У�Ĭ������ԽС���ȼ�Խ������Ƶ�ʴ�Ŀ�ǰ
        for(auto kv : frequentMap) {
            pq.push(make_pair(kv.second,kv.first));
        }

        while(!pq.empty() && k--) {// ��ȡǰK��
            //cout << pq.top().first << "," << pq.top().second << endl;
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};*/


int main() {
    Solution s;
    vector<int> nums = {2,2,3,3,1,4,4,4};
    vector<int> result = s.topKFrequent(nums,2);
    for(int item : result)
        cout << item << ",";
    return 0;
}
