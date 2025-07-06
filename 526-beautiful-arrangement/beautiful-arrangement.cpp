class Solution {
public:
    int count=0;
    void find(vector<int>&v,int idx){
        if (idx==v.size() - 1) {
            if (v[idx]%(idx+1)==0 || (idx+1)%v[idx]==0)
                count++;
            return;
        }
        for(int i=idx;i<v.size();i++){
            swap(v[idx],v[i]);
            if(v[idx]%(idx+1)==0 || (idx+1)%v[idx]==0) find(v,idx+1);
            swap(v[idx],v[i]);
        }
    }
    int countArrangement(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        find(v,0);
        return count;
    }
};