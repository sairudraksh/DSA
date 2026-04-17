class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            int num=nums[i];
            map.put(num,map.getOrDefault(num,0)+1);
            if(map.get(num)>=2) return true;
        }
        return false;
    }
}