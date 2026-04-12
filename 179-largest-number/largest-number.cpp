class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        int zerocount=0;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            ans.push_back(s);
            if(nums[i]==0) zerocount++;
        }
        if(zerocount==nums.size()) return "0";
        sort(ans.begin(),ans.end(),[](string &a,string &b){
            return a+b>b+a;
        });
        string result="";
        for(int i=0;i<nums.size();i++){
            result+=ans[i];
        }
        return result;
    }
};