class Solution {
public:
    int n;
    int valid(string s){
        sort(s.begin(),s.end());
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) return 0;
        }
        return s.length();
    }
    int find(vector<string>&nums,string &str,int i){
        if(i>=n){
            int a=valid(str);
            return a;
        }
        if(str.length()>0){
            int a=valid(str);
            if(a==0) return 0;
        }
        string org=str;
        str+=nums[i];
        int a=find(nums,str,i+1);
        str=org;
        int b=find(nums,str,i+1);
        return max(a,b);
    }
    int maxLength(vector<string>& nums) {
        n=nums.size();
        string s="";
        return find(nums,s,0);
    }
};