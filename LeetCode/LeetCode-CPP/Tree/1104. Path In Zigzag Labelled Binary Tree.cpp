// �������Ҫ�ؼ�����Ǽ��㾵���������Ӧλ���ϵ����
// k���������������ܹ��Ľڵ㣬Ȼ��õ���Ӧλ���ұ�ʣ��Ľڵ㣬Ȼ�����֮ǰ�Ľڵ�
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int k = log(label)/log(2) + 1; // ���label��Ӧ�����Ĳ���Ƕ���
        // 2^k-1 ��������һ���Ľڵ��������ȥlabel�õ��Ľ��Ϊ���ڵ�k�㣬label�ұ߻��ж��ٸ��ڵ㡣
        // Ȼ���ұ�ʣ��Ľڵ㣬������һ��Ľڵ���������Ǿ��������label��Ӧλ�õĽڵ���
        int mirror_label = pow(2,k) - 1 - label + pow(2,k-1); // �������Ķ�������ʱ��Ӧ�������Ƕ���
        bool is_mirror = false;
        // ���������ﵽһ���ʱ�����
        while(mirror_label != 0 && label != 0) {
            if(is_mirror) {
                res.insert(res.begin(), mirror_label);
            } else {
                res.insert(res.begin(), label);
            }
            is_mirror = !is_mirror;
            label /= 2;
            mirror_label /= 2;
        }
        return res;
    }
};