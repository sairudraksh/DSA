class Solution {
public:
    string replaceWords(vector<string>& nums, string s) {
        int n=nums.size();
        int m=s.length();

        string ans="";

        int i=0;
        unordered_map<string,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        while(i<m){
            string word="";
            string prefix="";
            bool found=false;
            while(i<s.length() && s[i]!=' '){
                word+=s[i];

                if(!found){
                    if(map[word]>0){
                        ans+=word;
                        found=true;
                        while(i<s.length() && s[i]!=' ') i++;
                        break;
                    }
                }
                i++;
            }
            if(found==false){
                ans+=word;
                if(i<=s.length()-1) ans+=" ";
                i++;
            }
            else{
                if(i<=s.length()-1) ans+=" ";
                i++;
            }
        }
        return ans;
    }
};