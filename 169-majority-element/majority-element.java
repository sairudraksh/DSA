class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int n=nums.length;
        int maximum=Integer.MIN_VALUE;
        int ans=-1;
        for(int i=0;i<n;i++){
            int num=nums[i];
            map.put(num,map.getOrDefault(num,0)+1);
            if(map.get(num)>maximum){
                maximum=map.get(num);
                ans=nums[i];
            }
        }
        return ans;
    }
}