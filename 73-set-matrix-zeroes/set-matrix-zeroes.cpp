class Solution {
public:
    void setZeroes(vector<vector<int>>&nums) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        int n=nums.size();
        int m=nums[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==0){
                    map1[i]=1;
                    map2[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1.find(i)!=map1.end() || map2.find(j)!=map2.end()){
                    nums[i][j]=0;
                }
            }
        }

    }
};