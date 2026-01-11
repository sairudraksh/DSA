class Solution {
public:
    long long countPairs(vector<string>& nums) {
        unordered_map<string,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=nums[i];
            string str="";
            if(s.length()==1){
                str="a";
            }
            for(int j=1;j<s.length();j++){
                int ch1=(int)s[j];
                int ch2=(int)s[j-1];
                int diff = (ch1 - ch2 + 26) % 26; ;
                char ans=diff+'0';
                str+=ans;
            }
            map[str]++;
        }
        long long  ans=0;
        for(auto x:map){
             long long count = x.second;
             ans += (count * (count - 1)) / 2; 
            
        }
        return ans;
    }
};