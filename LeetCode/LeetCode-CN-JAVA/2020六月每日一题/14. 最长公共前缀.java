// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         if(strs.length == 0) {
//             return "";
//         }
//         String ans = "";
//         for(int i = 0; i < strs[0].length(); i++) {
//             char ch = strs[0].charAt(i); // ÿ��ȡһ����ĸ��Ϊǰ׺��Ȼ���������ַ������ж��ڿ����Ƿ�һ��
//             for(int j = 1 ; j < strs.length; j++) {
//                 if(i >= strs[j].length() || ch != strs[j].charAt(i)) {
//                     return ans;
//                 }
//             }
//             ans += ch;
//         }
//         return ans;
//     }
// }


class Solution {

    // ʹ��Trie��
    class TrieNode {
        public char data;
        public TrieNode[] children = new TrieNode[26];
        public boolean isEndingChar = false;
        public TrieNode(char data) {
            this.data = data;
        }
    }

    private TrieNode root = new TrieNode('/'); // ����һ�����ڵ�
    private String ans = "";
    // ��trie���в���һ���ڵ�
    public void insert(String str) {
        TrieNode p = root;
        String temp_ans = "";
        for(int i = 0; i < str.length(); i++) {
            int index = str.charAt(i) - 'a'; // ���㵱ǰ�ַ�������
            if(p.children[index] != null) { // ������null˵������ǰ׺
                temp_ans += str.charAt(i);
            }
            if(p.children[index] == null) {
                TrieNode newNode = new TrieNode(str.charAt(i));
                p.children[index] = newNode;
            }
            p = p.children[index];
        }
        //System.out.println("ans:" + ans + ", temp_ans:" + temp_ans);
        if(str != ans) { // �����ǰ�ַ��ʹ�һ�������ظ��´�
            ans = temp_ans.length() < ans.length() ? temp_ans : ans;
        }
        
        p.isEndingChar = true;
    }
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        }
        ans = strs[0];
        for(int i = 0 ; i < strs.length; i++) {
            insert(strs[i]); // �����ͬʱ�����ǰ׺
        }
        return ans;
    }
}