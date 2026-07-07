class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n+1,0);
        v[0]=1;

        int i1=0;
        int i2=0;
        int i3=0;

        for(int i=1;i<=n;i++){
            int num=min({v[i1]*2,v[i2]*3,v[i3]*5});
            v[i]=num;
            if(v[i1]*2==num) i1++;
            if(v[i2]*3==num) i2++;
            if(v[i3]*5==num) i3++;
        }
        return v[n-1];
    }
};