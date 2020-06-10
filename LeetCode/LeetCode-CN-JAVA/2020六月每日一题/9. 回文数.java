class Solution {
    public boolean isPalindrome(int x) {
        // С��0�϶����ǻ�����
        // ���һλΪ0����ô��һλ����Ϊ0�����Դ�ʱxӦ��Ϊ0
        if(x < 0 || (x%10 == 0 && x!=0)) {
            return false;
        }

        int reversedNumber = 0;
        while(x > reversedNumber) {
            reversedNumber = reversedNumber * 10 + x%10;
            x /= 10;
        }
        return reversedNumber == x || reversedNumber/10 == x;
    }
}