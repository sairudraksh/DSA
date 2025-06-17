class Solution {
public:
    int find(int n){
        if(n==1 || n==0) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int k=1;k<=n;k++){
            sum=sum+find(k-1)*find(n-k);
        }
        return sum;
    }
    int numTrees(int n) {
        return find(n);
    }
};