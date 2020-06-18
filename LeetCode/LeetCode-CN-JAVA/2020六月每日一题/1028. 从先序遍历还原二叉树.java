/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String S) {
        Stack<TreeNode> path = new Stack<TreeNode>();
        int pos = 0;
        while(pos < S.length()) {
            int level = 0;
            while(S.charAt(pos) == '-') { // ������¸�����
                level++;
                pos++;
            }
            int value = 0; // ������¸�����
            while(pos < S.length() && Character.isDigit(S.charAt(pos))) {
                value = value*10 + Integer.valueOf(S.charAt(pos) - '0');
                pos++;
            }
            // System.out.println(value);
            TreeNode node = new TreeNode(value);
            // level == size() ��ʱ��˵����level������size()����һ�㣬��Ϊsize()��ʾ�Ѿ������˶��ٲ㣬�����Ǵ�0�㿪ʼ�����Լ���size=2��˵���Ѿ�������0���1�㣬��ʱlevel=2˵���¸��ڵ�����Ӧ������һ�㡣
            if(level == path.size()) { // ֱ�����ʱ˵����ǰ�ڵ�Ӧ�ò��뵽�ϸ��ڵ�����
                if(!path.empty()) { // ֻ����ȵ�����£����ܻ����level = 0 , size = 0 �ĳ�ʼ��������������ջ����Ϊ��
                    path.peek().left = node;
                }
            } else {
                while(level != path.size()) { // ����ʱ˵����ǰ�ڵ�Ӧ����֮ǰ·����ĳ���ڵ���ҽڵ㣬������Ҫ���ݵ�֮ǰ�Ĳ��
                    path.pop();
                }
                path.peek().right = node;
            }
            path.push(node);
        }
        while(path.size() > 1) {
            path.pop();
        }
        return path.peek();
    }
}