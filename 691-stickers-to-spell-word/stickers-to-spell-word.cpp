class Solution {
public:
    unordered_map<string,int> dp;

    int find (vector<string>& stickers, string &ans){
        if(ans=="") return 0;

        int minimum=INT_MAX;

        string key = ans;
        if(dp.find(key)!=dp.end()) return dp[key];

        for(int i=0;i<stickers.size();i++){

            if(stickers[i].find(ans[0]) == string::npos) continue;// skip if sticker is useless means already used

            int a=INT_MAX;
            unordered_map<char,int>map;

            string org=ans;
            string s=stickers[i];

            for(int j=0;j<s.length();j++){
                map[s[j]]++;
            }

            string str="";
            for(int j=0;j<ans.length();j++){
                if(map[ans[j]]>0){
                    map[ans[j]]--;
                }
                else{
                    str+=ans[j];
                }
            }

            if(str.length()<ans.length()){
                a=find(stickers,str);
                ans=org;
                if(a!=INT_MAX) a+=1;
            }
            minimum=min(minimum,a);
        }

        return dp[key]=minimum;
    }

    int minStickers(vector<string>& stickers, string target) {
        int a=find(stickers,target);   
        if(a==INT_MAX) return -1;
        return a;
    }
};