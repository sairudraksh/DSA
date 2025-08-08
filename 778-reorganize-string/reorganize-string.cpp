class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>map;

        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto &x:map){
            pq.push({x.second,x.first});
        }

        string ans="";

        while(pq.size()>0){
            auto largest=pq.top();
            pq.pop();

            ans+=largest.second;

            if(!pq.empty()){
                auto SLargest=pq.top();
                pq.pop();

                ans+=SLargest.second;
                if(SLargest.first-1!=0){
                    pq.push({SLargest.first-1,SLargest.second});
                }
            }
            else if(largest.first-1>=1) return "";

            if(largest.first-1!=0){
                pq.push({largest.first-1,largest.second});
            }
        }
        return ans;
    }
};