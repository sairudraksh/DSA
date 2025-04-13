class Solution {
public:
    void combinations(vector<vector<int>>&ans,vector<int>v,vector<int>candidates,int n,int target,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=idx;i<n;i++){
            v.push_back(candidates[i]);
            combinations(ans,v,candidates,n,target-candidates[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>v;
        vector<vector<int>>ans;
        combinations(ans,v,candidates,n,target,0);
        return ans;
    }
};