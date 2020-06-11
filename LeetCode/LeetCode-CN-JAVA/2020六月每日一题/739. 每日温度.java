class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Stack<Integer> stk = new Stack<Integer>();
        for(int i = T.length - 1; i >= 0; i--) {
            // ջ�б���ȵ�ǰ���¸ߵ�λ��
            while(!stk.empty() && T[i] >= T[stk.peek()]) {
                stk.pop();
            }
            // ���ջΪ����˵��û�бȵ�ǰ���¸ߣ���Ϊ0.�����������һ���ȵ�ǰ���¸߾���Ŀǰ�ľ��롣
            ans[i] = stk.empty() ? 0 : stk.peek() - i;
            stk.push(i);
        }
        return ans;
    }
}