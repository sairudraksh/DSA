class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        for(int i=0;i<strs[0].length();i++){
            string ans="";
            for(int j=0;j<strs.size();j++){
                ans+=strs[j][i];
            }
            string t=ans;
            sort(t.begin(),t.end());
            if(ans!=t) count++;
        }
        return count;
    }
};