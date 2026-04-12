class Solution {
public:
    unordered_map<string,int>dp;
    int find(char finger1,char finger2,string &word,int i, unordered_map<char,pair<int,int>>&map){
        if(i>=word.size()) return 0;
        string key=string(1,finger1)+'$'+string(1,finger2)+'$'+to_string(i);
        if(dp.count(key)) return dp[key];
        if(finger2=='#'){
            auto p1=map[finger1];

            auto p2=map[word[i]];

            int i1=p1.first;
            int j1=p1.second;

            int i2=p2.first;
            int j2=p2.second;


            int dist=abs(i1-i2)+abs(j1-j2);

            return dp[key]=min(dist+find(word[i],finger2,word,i+1,map),find(finger1,word[i],word,i+1,map));
        }
        else{
            auto p1=map[finger1];
            auto p2=map[finger2];
            auto p3=map[word[i]];

            int i1=p1.first;
            int j1=p1.second;

            int i2=p2.first;
            int j2=p2.second;

            int i3=p3.first;
            int j3=p3.second;

            int dist1=abs(i1-i3)+abs(j1-j3);

            int dist2=abs(i2-i3)+abs(j2-j3);

            return dp[key]=min(dist1+find(word[i],finger2,word,i+1,map),dist2+find(finger1,word[i],word,i+1,map));
        }
    }
    int minimumDistance(string word) {
        unordered_map<char,pair<int,int>>map;
        int num=65;

        for(int i=0;i<=4;i++){
            for(int j=0;j<=5;j++){
                char ch=char(num);
                map[ch]={i,j};
                num++;
            }
        }

        return find(word[0],'#',word,1,map);
    }
};