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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0) {
            return null;
        }
        Stack<Integer> l_r_index = new Stack<Integer>();
        Stack<TreeNode> path = new Stack<TreeNode>();
        l_r_index.push(0);
        l_r_index.push(nums.length - 1);
        TreeNode root = new TreeNode(0);
        path.push(root);
        while(!path.isEmpty()) {
            int r_index = l_r_index.pop();
            int l_index = l_r_index.pop();
            //System.out.println(l_index + " " + r_index);
            int mid = l_index + (r_index - l_index) / 2;
            TreeNode node = path.pop(); // ȡ����ŵĽڵ㣬��������Ϊmid
            node.val = nums[mid];
            // ���ø�node�����ҽڵ�
            if(l_index <= mid - 1) { // ȷ��mid��߻��нڵ�
                node.left = new TreeNode(0);
                path.push(node.left);
                l_r_index.push(l_index);
                l_r_index.push(mid - 1);
            }
            if(r_index >= mid + 1) { // ȷ��mid�ұ߻��нڵ�
                node.right = new TreeNode(0);
                path.push(node.right);
                l_r_index.push(mid + 1);
                l_r_index.push(r_index);
            }
        }
        return root;
    }
}