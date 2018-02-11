#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 1;
        int curLen = 1;

        for(int i=0; i < nums.size(); i++) {
            curLen = 1;//��1��ʼ���㣬��Ϊ�������±�Ϊ0�Ļ��ͽ����ˣ�������ʵ��ʼ��λ��
            int curIndexNum = nums[i];//��ǰ�±��Ӧ������

            //�����ǰ�±��Ӧ�����ֲ�����0�����Ҳ���������
            while(curIndexNum && curIndexNum!=i) {
                curLen++;
                curIndexNum = nums[curIndexNum];//�ҵ���һ������
            }
            maxLen = max(maxLen,curLen);
        }
        return maxLen;
    }
};*/


/*class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;

        //��֮ǰ�Ľ����Ż������ʹ��Ĳ���Ҫ�ٴη�����
        for(int i=0; i < nums.size(); i++) {
            curLen = 0;//��0��ʼ����Ϊ�������±���0�Ļ�Ҳ����ʣ�������Ҫ��0��ʼ����
            if(nums[i] != INT_MAX) {
                int curIndexNum = nums[i];//�ҵ���һ��Ԫ������

                while(nums[curIndexNum] != INT_MAX) {//�����ǰԪ�������ֵ�Ļ���˵���Ѿ����ʹ��˲���Ҫ�ٴη����ˣ�����������
                    curLen++;
                    int temp = curIndexNum;//��¼�¸ղŷ��ʵ�����
                    curIndexNum = nums[curIndexNum];//�ҵ���һ��Ԫ������
                    nums[temp] = INT_MAX;//���ղŷ��ʹ�������ΪINT_MAX
                }

                maxLen = max(maxLen,curLen);

            }
        }
        return maxLen;
    }
};*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;
        vector<bool> visied(nums.size());//�����Ŷ�Ӧλ����û�б����ʹ�

        for(int i=0; i<nums.size(); i++) {
            curLen = 0;
            int curIndexNum = nums[i];

            while(!visied[curIndexNum]) {//�鿴��Ӧλ���Ƿ񱻷��ʹ�
                curLen++;
                int temp = curIndexNum;
                curIndexNum = nums[curIndexNum];
                visied[temp] = true;
            }
            maxLen = max(maxLen,curLen);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,4,0,3,1,6,2};

    int result = s.arrayNesting(nums);
    cout << result;
    return 0;
}



