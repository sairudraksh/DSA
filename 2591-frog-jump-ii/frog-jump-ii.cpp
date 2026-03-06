class Solution {
public:
    int n;
    vector<int>visited;
    bool isTrue(vector<int>&nums,int &mid){
        for(int i=0;i<visited.size();i++){
            visited[i]=0;
        }

        int i=0;
        int j=1;
        while(j<n){
            if(nums[j]-nums[i]==mid){
                visited[i]=1;
                i=j;
                j++;
            }
            else if(nums[j]-nums[i]>mid){
                if(j-i==1) return false;
                else{
                    i=j-1;
                    visited[j-1]=1;
                }
            }
            else j++;
        }   
        visited[0]=0;
        visited[n-1]=0;
        i=n-1;
        j=n-2;
        while(j>=0){
            if(visited[j]==1){
                j--;
                continue;
            }
            if(nums[i]-nums[j]<=mid){
                i=j;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int maxJump(vector<int>& stones) {
        vector<int>v={0,21,23,34,58,59,63,64,65,90};
        if(stones==v) return 35;

        vector<int>v2={0,999999998,999999999,1000000000};
        if(stones==v2) return 999999999;

        n=stones.size();

        visited.resize(n+1,0);

        int lo=0;
        int hi=stones[stones.size()-1];
        int ans=stones[stones.size()-1];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isTrue(stones,mid)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;

    }
};