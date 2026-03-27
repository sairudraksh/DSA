class Solution {
public:
    bool find(vector<int>&v,int &k){
        vector<int>v2=v;
        for(int j=0;j<k;j++){
            int num=0;
            for(int i=0;i<v.size();i++){
                if(i==0) num=v[0];

                else v[i-1]=v[i];
            }
            v[v.size()-1]=num;
        }

        for(int i=0;i<v2.size();i++){
            if(v[i]!=v2[i]) return false;
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