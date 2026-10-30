class Solution {
    public int totalFruit(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>map=new HashMap<>();
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<n){
            map.put(nums[j],map.getOrDefault(nums[j],0)+1);
            while(map.size()>2){
              
                map.put(nums[i],map.getOrDefault(nums[i],0)-1);
                if(map.getOrDefault(nums[i],0)==0) map.remove(nums[i]);
                i++;
            }
            if(map.size()<=2) maxlen=Math.max(maxlen,j-i+1);
            j++;
        }
        j--;
        while(i<n){
            if(map.size()<=2) maxlen=Math.max(maxlen,j-i+1);
            map.put(nums[i],map.getOrDefault(nums[i],0)-1);
            if(map.getOrDefault(nums[i],0)==0) map.remove(nums[i]);
            i++;
        }
        return maxlen;
    }
}