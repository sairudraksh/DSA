class Solution {
    public boolean exists(TreeNode root,TreeNode p){
        if(root==null) return false;


        if(root==p) return true;

        return exists(root.right,p) || exists(root.left,p);
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null) return null;

        if((exists(root.left,p) && exists(root.right,q)) || (exists(root.left,q) && exists(root.right,p))) return root;
        else if(exists(root.left,p) && exists(root.left,q)) return lowestCommonAncestor(root.left,p,q);
        else if(exists(root.right,p) && exists(root.right,q)) return lowestCommonAncestor(root.right,p,q);
        return root;
    }
}