class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto x:mp){
            pq.push(x);
        }
        string str="";
        while(pq.size()>0){
            pair<char,int>largest=pq.top();
            pq.pop();
            int len=min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                str+=largest.first;
            }
            if(largest.second-len>0){
                if(pq.size()>0){
                    pair<char,int>secondlargest=pq.top();
                    pq.pop();
                    str+=secondlargest.first;
                    if(secondlargest.second-1>0){
                        pq.push({secondlargest.first,secondlargest.second-1});
                    }
                    pq.push({largest.first,largest.second-len});
                }
            }
        }
        return str;
    }
};