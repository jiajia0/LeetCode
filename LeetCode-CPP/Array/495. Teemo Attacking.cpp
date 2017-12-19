#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        if(duration == 0 || timeSeries.empty() || timeSeries.size() == 0) {
            return 0;
        }

        int time = 0;
        int startTime = timeSeries[0];//��¼��ʼʱ��
        int endTime = timeSeries[0] + duration;//��¼����ʱ��

        for(int i=1; i < timeSeries.size(); i++) {
            //������ڵ�ʱ����ڽ���ʱ�䣬�ͼ���һ�����ʱ�䣬�������ÿ�ʼʱ��
            if(timeSeries[i] > endTime) {
                time += endTime - startTime;
                startTime = timeSeries[i];
            }
            //������һ������ʱ��
            endTime = timeSeries[i] + duration;
        }

        // �������һ�ν�����ʱ��Ϳ�ʼʱ��ļ��
        time += endTime - startTime;

        return time;
    }
};*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = duration * timeSeries.size();//�����ܵ�ʱ��
        for(int i=1; i < timeSeries.size(); i++) {
            // �������ʱ���е��ӣ������ӵ�ʱ���ȥ
            time -= max(0,duration - (timeSeries[i] - timeSeries[i-1]));
        }
        return time;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);


    int n = s.findPoisonedDuration(nums,5);
    cout << n;
    return 0;
}

