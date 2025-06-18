class Solution {
public:
    int find(int n){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+find(i-1)*find(n-i);
        }
        return sum;
    }
    int numTrees(int n) {
        return find(n);
    }
};