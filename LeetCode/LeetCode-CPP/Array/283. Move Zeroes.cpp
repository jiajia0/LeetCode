#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;//��ʾ���һ��0���±�
        int num = 0;//��ʾ��0���±�
        for(int i=0; i < nums.size() ;i++) {
            if(nums[i] != 0) {//�����ʱ������0������num��¼�����˿̵�����
                //cout << "�˿̲�����0��" << i << endl;
                num = i;
            }

            if(zero == -1 && nums[i] == 0) {
                //cout << "�ҵ������еĵ�һ��0�±꣺" << i << endl;
                zero = i;
            }

            if(zero != -1) {
                if(num > zero) {//���num����zero��˵��������һ����0���˿���Ҫ����λ���ˣ�������zero�����Ժ�һ��0���±�
                    //cout << "���������������±�Ϊ����0��" << num << "��0��" << zero << endl;
                    swap(nums[zero],nums[num]);
                    //cout << "������֮��zero�±��Ԫ��Ϊ��" << nums[zero] << "��num�±��Ԫ��Ϊ��" << nums[num] << endl;
                    while(nums[zero] != 0) {
                        //cout << "�����zero������0��������Ҫ�����ң��˿�zeroΪ��" << zero << endl;
                        zero++;
                        //i++;
                    }
                    if(zero>=nums.size()) {//˵���Ѿ������
                        break;
                    }
                }
            }
        }

        //for(int i=0;i<nums.size();i++) {
          //  cout << nums[i] << ",";
        //}

    }
};

/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0,j=0;i<nums.size();i++) {
            if(nums[i]) {//�����ʱ������0,���м���
                if(i!=j) {//��ȵĻ�˵��j�˿�Ҳ�Ǵ���һ����0λ��
                    swap(nums[i],nums[j]);
                }
                j++;//���������������Ҫ��һ�����������Ҳ��Ҫ��һ
            }
        }

        //for(int i=0;i<nums.size();i++) {
            //cout << nums[i] << ",";
        //}
    }
};*/

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(12);

    s.moveZeroes(nums);
    return 0;
}
