class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&v,int &sum,int i,int &n,int &k){
        if(v.size()>k) return;

        if(v.size()==k){
            if(sum==n){
                ans.push_back(v);
            }
            return;
        }
        if(sum>n) return;
        if(i>9) return;

        int orgsum=sum;

        v.push_back(i);
        sum+=i;
        find(v,sum,i+1,n,k);

        v.pop_back();
        sum=orgsum;

        find(v,sum,i+1,n,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        vector<int>v;

        find(v,sum,1,n,k);
        return ans;
    }
};