class Solution {
public:
    int minCost(string s, vector<int>& needs) {
        int n=needs.size();
        int maximum=needs[0];
        int sum=needs[0];

        int ans=0;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                maximum=max(maximum,needs[i]);
                sum+=needs[i];
            }
            else{
                ans+=sum-maximum;
                sum=needs[i];
                maximum=needs[i];
            }
        }
        ans+=sum-maximum;
        return ans;
    }
};