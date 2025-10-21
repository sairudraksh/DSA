class Solution {
public:
    vector<vector<int>>ans;
    void find(int &k,int &target,vector<int>&v,int &sum){
        if(v.size()>k) return;
        if(sum>target) return;
        
        if(v.size()==k && sum==target){
            ans.push_back(v);
            return;
        }

        if(v.size()==0){
            for(int i=1;i<=9;i++){
                v.push_back(i);
                sum=sum+i;
                find(k,target,v,sum);
                sum=sum-i;
                v.pop_back();
            }
        }
        else{
            int x=v[v.size()-1];

            for(int i=x+1;i<=9;i++){
                v.push_back(i);
                sum=sum+i;
                find(k,target,v,sum);
                sum=sum-i;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        int sum=0;
        find(k,n,v,sum);
        return ans;
    }
};