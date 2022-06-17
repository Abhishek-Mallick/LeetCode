/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private int CameraCount = 0;
    private int needCamera = 0;
    private int hasCamera = 1;
    private int coveredNode = 2;
    private int notneeded = 3;
    
    public int minCameraCover(TreeNode root) {
        CameraCount = CameraPlacement(root) == needCamera?CameraCount+1:CameraCount;
        return CameraCount;
    }
    
    private int CameraPlacement(TreeNode root)
    {
        if(root == null)
            return notneeded;
        if(root.left == null && root.right == null)
            return needCamera;
        
        int left = CameraPlacement(root.left);
        int right = CameraPlacement(root.right);
        
        if(left == needCamera || right == needCamera)
        {
            CameraCount++;
            return hasCamera;
        } 
        
        if(left == hasCamera || right == hasCamera)
            return coveredNode;
        
        return needCamera;
    }
}