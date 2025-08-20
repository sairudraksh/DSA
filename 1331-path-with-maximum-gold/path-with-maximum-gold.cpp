class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    int find(int i,int j,vector<vector<int>>&nums){
        if(i<0 || i>=n || j<0 || j>=m || nums[i][j]==0 || visited[i][j]) return 0;

        visited[i][j]=1;

        int a=nums[i][j]+max({find(i+1,j,nums),find(i,j+1,nums),find(i-1,j,nums),find(i,j-1,nums)});

        visited[i][j]=0;

        return a;
    }
    int getMaximumGold(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        int maximum=0;
        visited.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]!=0){
                    maximum=max(maximum,find(i,j,nums));
                }
            }
        }
        return maximum;
    }
};