class Solution {
public:
    int n;
    int m;
    vector<int>visited;
    void dfs(vector<vector<int>>& nums,int i){
        visited[i]=1;
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(visited[j]==0 && nums[i][j]==1){
                dfs(nums,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();

        visited.resize(n+1,0);

        int count=0;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(nums,i);
                count++;
            }
        }
        return count;
    }
};