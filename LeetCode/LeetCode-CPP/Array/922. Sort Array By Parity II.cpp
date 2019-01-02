#include <iostream>
#include <vector>

using namespace std;

// Plan A
/*class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i,even_index,odd_index;
        for(i=0;i<A.size();i++) {
            even_index = odd_index = i;
            if(i%2 == 0) {//��ǰΪż��
                while(A[even_index]%2!=0 && even_index<A.size()) {//�ҵ���һ������
                    even_index++;
                }
                swap(A[i],A[even_index]);
            } else {//��ǰΪ����
                while(A[odd_index]%2==0 && odd_index<A.size()) {//�ҵ���һ������
                    odd_index++;
                }
                swap(A[i],A[odd_index]);
            }
        }
        return A;
    }
};*/

/*class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i,even_index=0,odd_index=0;
        vector<int> odds,evens;
        for(int i : A) {
            if(i%2 == 0)
                evens.push_back(i);
            else
                odds.push_back(i);
        }
        for(i=0;i<A.size();i++){
            if(i%2==0) {
                A[i] = evens[even_index];
                even_index++;
            } else {
                A[i] = odds[odd_index];
                odd_index++;
            }
        }
        return A;
    }
};*/

/*class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i,even_index=0,odd_index=1;
        vector<int> result(A.size(),0);
        for(i=0;i<A.size();i++) {
            if(A[i]%2==0) {//�����ǰ����Ϊż�����򽫸����ַŵ���������е�ż��������
                result[even_index] = A[i];
                even_index += 2;
            } else {
                result[odd_index] = A[i];
                odd_index += 2;
            }
        }
        return result;
    }
};*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even_index=0,odd_index=1;
        while(even_index<A.size() && odd_index<A.size()) {
            while(A[even_index]%2==0&&even_index<A.size()) even_index+=2;//ż��������Ϊż��ʱͣ����
            while(A[odd_index]%2==1&&odd_index<A.size()) odd_index+=2;//����������Ϊ����ʱͣ����
            //cout << A[even_index] << ",index:" << even_index << endl;
            //cout << A[odd_index] << ",index:" << odd_index << endl;
            if(even_index>A.size() || odd_index>A.size()) break;
            swap(A[even_index],A[odd_index]);
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<int> A = {4,2,5,7};
    vector<int> ret = s.sortArrayByParityII(A);
    for(int i : ret) {
        cout << i << " ";
    }
    return 0;
}
