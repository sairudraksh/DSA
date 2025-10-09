class Solution {
public:
    vector<vector<int>>ans;
    void find(int i,int &n,int &k,vector<int>&v){
        if(v.size()==k){
            ans.push_back(v) ;
            return ;
        }
        if(i>n){
            if(v.size()==k) ans.push_back(v);
            return;
        }
        v.push_back(i);
        find(i+1,n,k,v);
        v.pop_back();
        find(i+1,n,k,v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        find(1,n,k,v);
        return ans;
    }
};