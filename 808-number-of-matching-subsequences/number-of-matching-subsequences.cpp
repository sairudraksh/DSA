class Solution {
public:
    int isSubsequence(string &s1,string &s2){
        int n=s1.length();
        int m=s2.length();

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else i++;
        }

        return j==m;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;

        unordered_map<string,bool>map;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            if(map.find(str)!=map.end()){

                if(map[str]==true){
                    count++;
                }
                continue;

            }

            map[str]=isSubsequence(s,str);
            if(map[str]==true) count++;
        }

        return count;
    }
};