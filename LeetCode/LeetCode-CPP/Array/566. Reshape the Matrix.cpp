#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if(nums.size() == 0 || nums.size() * nums[0].size() != r*c) {//�������0���߲���ת��Ϊָ����Ҫ���򷵻�ԭ����
            return nums;
        }

        queue<int> all_nums;
        vector<vector<int>> new_nums;
        int i,j;
        new_nums.resize(r);//�趨Ϊr��
        for(i=0;i<r;i++) {
            new_nums[i].resize(c);//�趨ÿ�ж��ٸ�Ԫ��
        }
        for(i=0;i<nums.size();i++) {//�����е����ַŵ�һ��������
            for(j=0;j<nums[i].size();j++) {
                //cout << nums[i][j] << endl;
                all_nums.push(nums[i][j]);
            }
        }

        for(i=0;i<r;i++) {//�µ�����
            for(j=0;j<c;j++) {//�µ�����
                new_nums[i][j] = all_nums.front();
                all_nums.pop();
            }
        }

        return new_nums;
    }
};*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if(nums.size() == 0 || nums.size() * nums[0].size() != r*c) {//�������0���߲���ת��Ϊָ����Ҫ���򷵻�ԭ����
            return nums;
        }

        vector<vector<int>> new_nums(r,vector<int>(c));
        int i,j;
        int row=0,col=0;

        for(i=0;i<nums.size();i++) {//������
            for(j=0;j<nums[0].size();j++) {//������
                new_nums[row][col] = nums[i][j];//ȡ��һ��Ԫ�ظ�ֵ���µ�����
                col++;//�м�һ������ƶ�һ��
                if(col == c) {//����˿̵������Ѿ����ӵ��˹涨������������������һ����������
                    col = 0;
                    row++;
                }
            }
        }

        return new_nums;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums;
    vector<int> num1;
    vector<int> num2;
    num1.push_back(1);
    num1.push_back(4);
    num2.push_back(2);
    num2.push_back(3);
    nums.push_back(num1);
    nums.push_back(num2);
    vector<vector<int>> n = s.matrixReshape(nums,1,4);
    int i,j;
    for(i=0;i<n.size();i++) {//�����е����ַŵ�һ��������
        for(j=0;j<n[i].size();j++) {
            cout << n[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}
