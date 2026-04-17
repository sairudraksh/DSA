class Solution {
    int n;
    List<List<Integer>>ans=new ArrayList<>();
    void find(int[] visited,List<Integer>v,int[] nums){
        if(v.size()==nums.length){
            ans.add(new ArrayList<>(v));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i]==1) continue;
            v.add(nums[i]);
            visited[i]=1;
            find(visited,v,nums);
            v.remove(v.size()-1);
            visited[i]=0;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        n=nums.length;

        List<Integer>v=new ArrayList<>();
        int[] visited=new int[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        find(visited,v,nums);
        return ans;
    }
}