class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>map;
            int maximum=INT_MIN;
            int minimum=INT_MAX;
            for(int j=i;j<n;j++){
                map[s[j]]++;
                int maximum=INT_MIN;
                int minimum=INT_MAX;
                for(auto &x:map){
                    maximum=max(maximum,x.second);
                    minimum=min(minimum,x.second);
                }
                sum+=(maximum-minimum);
            }
        }
        return sum;
    }
};