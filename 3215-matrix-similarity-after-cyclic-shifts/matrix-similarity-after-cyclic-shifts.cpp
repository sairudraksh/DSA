class Solution {
public:
    bool find(vector<int>v,int &k){
        int n=v.size();
        for(int i=0;i<n;i++){
            v.push_back(v[i]);
        }

        for(int i=0;i<n;i++){
            if(v[i]!=v[i+k]) return false;
        }
        return true;

    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;

        for(int i=0;i<n;i++){
            bool a=find(mat[i],k);
            if(a==false) return false;
        }
        return true;
    }
};