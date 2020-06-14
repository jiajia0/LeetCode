class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        // bellman ford
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);
        prices[src] = 0; // ��src����Ϊ0
        for(int i = 0; i <= K; i++) {
            // ��Ҫ��������һ�������鿴ԭ���ļ�¼��������һ��ֻ��һ��������޸�ԭ�������飬����������еı��൱�����˺ܶಽ.eg:0->1 100, 1->2 100,0->2 500, ��0->2 ��K=0.
            int[] temp = Arrays.copyOf(prices, n);
            for(int[] e : flights) {
                if(prices[e[0]] != Integer.MAX_VALUE) { // ���==MAX��˵��֮ǰ�޷��������ת�㣬��������Ƚ�
                    temp[e[1]] = Math.min(temp[e[1]], prices[e[0]] + e[2]);
                }
            }
            prices = temp;
        }
        return prices[dst] == Integer.MAX_VALUE ? -1 : prices[dst];
    }
}