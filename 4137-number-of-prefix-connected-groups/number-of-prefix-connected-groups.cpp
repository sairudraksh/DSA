class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>map;
        for(int i=0;i<words.size();i++){
            if(words[i].length()>=k){
                string str=words[i];
                string s=str.substr(0,k);
                map[s]++;
            }
        }

        int count=0;
        for(auto &x:map){
            if(x.second>=2) count++;
        }
        return count;
    }
};