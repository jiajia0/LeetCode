class Solution {
    public int findBestValue(int[] arr, int target) {
        // C++ �õĶ��֣�����ʹ��ƽ��ֵ
        Arrays.sort(arr); // ���Ƚ�������
        int sum = 0;
        for(int i = 0 ; i < arr.length; i++) {
            int x = (target - sum) / (arr.length - i); // ���������ֵ��ʵ��ֵ��ƽ��ֵ
            if(arr[i] > x) { // �����ǵ�����ϵ�������ǰ����ֵ��ƽ��ֵ�����򲻿��ܸ��ӽ���
                double r =  (double)(target - sum) / (arr.length - i);
                return r - x > 0.5 ? x + 1 : x;
            }
            sum += arr[i];
        }
        return arr[arr.length - 1]; // ˵�����������е�Ԫ�ض�С�ڵ�����ƽ��ֵ����ô���鲻��Ҫ�Ķ�����Ϊֻ��Խ��ԽС
    }
}