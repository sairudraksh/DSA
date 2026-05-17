class Solution {
    int res;
    public int find(TreeNode root){
        if(root==null) return 0;

        int left=find(root.left);
        int right=find(root.right);

        if(res<left+right){
            res=left+right;
        }
        return 1+Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        res=0;
        find(root);
        return res;
    }
}