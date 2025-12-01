class Solution {
    public static void rotate(int i,int j,int[] nums){
        while(i<=j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
        rotate(0,n-k-1,nums);
        rotate(n-k,n-1,nums);
        rotate(0,n-1,nums);
    }
}