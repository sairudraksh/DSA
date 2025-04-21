class Solution {
public:
    TreeNode* helper(vector<int>&arr,int lo,int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=helper(arr,lo,mid-1);
        root->right=helper(arr,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};