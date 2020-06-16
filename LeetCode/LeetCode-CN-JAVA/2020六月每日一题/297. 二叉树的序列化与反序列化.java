/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "";
        }
        String data = "";
        // BFS �������
        Stack<TreeNode> stk = new Stack<TreeNode>();
        while(root != null || !stk.empty()) {
            while(root != null) {
                data += String.valueOf(root.val) + ","; 
                stk.push(root);
                root = root.left;
                if(root == null) { // ��ڵ�Ϊ��ʱ��null
                    data += "null,";
                }
            }
            TreeNode node = stk.pop();
            root = node.right;
            if(root == null) { // �ҽڵ�Ϊ��ʱ��null
                data += "null,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data == "") {
            return null;
        }
        String[] tree_data = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(tree_data[0]));
        TreeNode ans = root;
        int i = 1;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        while(root != null || !stk.empty()) {
            while(root != null) {
                TreeNode node = null;
                if(!tree_data[i].equals("null")) {
                    node = new TreeNode(Integer.valueOf(tree_data[i]));
                    stk.push(node);
                }
                i++;
                root.left = node;
                root = node;
            }
            
            TreeNode p = stk.pop(); // ջ��ȡ��һ��Ԫ��
            TreeNode node = null;
            if(!tree_data[i].equals("null")) { // �����һ���ڵ㲻Ϊ��null������Ϊp���ҽڵ�
                node = new TreeNode(Integer.valueOf(tree_data[i]));
                stk.push(node);
            }
            p.right = node;
            root = node;
            i++;
            //System.out.println(i + "," + stk.size());
            
        }
        return ans;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));