class Solution {
public:
    bool isAnagram(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2) return true;
        else return false;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<int>visited(n,false);
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            ans.push_back(words[i]);
            for(int j=i+1;j<n;j++){
                if(visited[j]) continue;

                else if(isAnagram(words[i],words[j])){
                    visited[j]=true;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};