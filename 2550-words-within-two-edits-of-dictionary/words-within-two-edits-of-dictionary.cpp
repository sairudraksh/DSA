class Solution {
public:
    bool isTrue(string &s1,string &s2){
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) count++;
            if(count>2) return false;
        }
        return count<=2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string>v;
        for(int i=0;i<n;i++){
            string s1=queries[i];
            for(int j=0;j<m;j++){
                string s2=dictionary[j];
                if(isTrue(s1,s2)){
                    v.push_back(s1);
                    break;
                }
            }
        }
        return v;
    }
};