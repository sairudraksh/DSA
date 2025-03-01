class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i=0;i<=n;i++){
            int k=i;
            int count=0;
            while(k>0){
               if(k%2!=0) count++;
                k=k/2;
            }
            v[i]=count;
        }
        return v;
    }
};