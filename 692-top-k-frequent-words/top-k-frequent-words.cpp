class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>map;

        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }

        priority_queue<pair<int,string>>pq;

        for(auto x:map){
            pq.push({x.second,x.first});
        }
        vector<string>ans;
        while(k){
            vector<string>v;
            auto p=pq.top();
            v.push_back(p.second);
            pq.pop();
            
            while(pq.size()>0 && pq.top().first==p.first){
                auto q=pq.top();
                pq.pop();
                v.push_back(q.second);
            }
            sort(v.begin(),v.end());
            ans.push_back(v[0]);
            for(int i=0;i<v.size();i++){
                if(v[i]==ans[ans.size()-1]) continue;
                else pq.push({p.first,v[i]});
            }
            k--;
        }
        return ans;
    }
};