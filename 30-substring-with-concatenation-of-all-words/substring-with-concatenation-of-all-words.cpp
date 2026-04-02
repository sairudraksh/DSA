class Solution {
public:
    bool isTrue(int l,int m,unordered_map<string,int>&map,int &len,string &str){
        string s="";

        int i=l;
        int j=i;
        unordered_map<string,int>map2;
        while(j<=m){
            s+=str[j];
            if(j-i+1==len){
                if(map.find(s)!=map.end()){
                    map2[s]++;
                    


                    s="";
                    i=j+1;
                    j=i;
                }
                else return false;
            }
            else{
                j++;
            }
        }
        if(map.size()==map2.size()){
            for(auto x:map2){
                if(map2[x.first]!=map[x.first]) return false;
            }
            return true;
        }
        return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length();
        int len=words[0].length();
        int length=len*words.size();

        int i=0;
        int j=length-1;


        unordered_map<string,int>map;
        unordered_map<char,int>character;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
            character[words[i][0]]++;
        }   
        vector<int>v;
        while(j<n){
            if(character.find(s[i])==character.end()){
                i++;
                j++;
                continue;
            }
            if(isTrue(i,j,map,len,s)){
                v.push_back(i);
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return v;
    }
};