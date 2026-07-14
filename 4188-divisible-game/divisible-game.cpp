class Solution {
public:
    int n;
    long long find(vector<int>&nums,int k){
        long long currsum=0;
        long long maxsum=LLONG_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]%k==0) currsum+=nums[i];
            else currsum-=nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0) currsum=0;
        }
        return maxsum;
    }
    int divisibleGame(vector<int>& nums) {
        n=nums.size();
        set<int>st;
        st.insert(2);
        int n=nums.size();

        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=2;j*j<=num;j++){
                if(num%j==0) st.insert(j);
                if(num/j!=j) st.insert(num/j);//important
            }
            if(num!=1) st.insert(num);
        }
        long long maximum=LLONG_MIN;
        long long ans=0;
        for(auto x:st){
            int a=find(nums,x);

            if(a>maximum){
                maximum=a;
                ans=maximum*x;
            }
        }
        return (ans%1000000007+1000000007)%1000000007;
    }
};