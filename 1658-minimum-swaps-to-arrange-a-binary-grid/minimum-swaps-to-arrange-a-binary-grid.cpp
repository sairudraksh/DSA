class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v1;

        for(int i=0;i<n;i++){
            auto v=grid[i];
            int count=0;
            for(int j=v.size()-1;j>=0;j--){
                if(v[j]!=0) break;
                else count++;
            }
            v1.push_back(count);
        }
        int count=0;
        for(int i=0;i<n;i++){
            int currpos=-1;
            int required=n-i-1;

            for(int j=i;j<n;j++){
                if(v1[j]>=required){
                    currpos=j;
                    break;
                }
            }
            if(currpos==-1) return -1;

            for(int j=currpos;j>i;j--){
                swap(v1[j],v1[j-1]);
                count++;
            }
        }
        return count;
    }
};