/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildHelper(inorder, inorder.length-1, 0, postorder, postorder.length-1);
    }
    private TreeNode buildHelper(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart){
        if (inEnd > inStart)
            return null;
            
        TreeNode root = new TreeNode(postorder[postStart]);
        
        if (inEnd == inStart)
            return root;
        
        int index = 0;
        for (int i = inStart; i >= inEnd; i--){
            if (inorder[i] == root.val){
                index = i;
                break;
            }
        }
        
        root.right = buildHelper(inorder, inStart, index+1, postorder, postStart-1);
        root.left = buildHelper(inorder, index-1, inEnd, postorder, postStart-(inStart-index)-1);
        return root;
    }
}
