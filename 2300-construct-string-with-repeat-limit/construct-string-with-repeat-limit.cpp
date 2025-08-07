class Solution {
public:
    string repeatLimitedString(string str, int repeatLimit) {
        unordered_map<char,int>map;
        int n=str.length();
        for(int i=0;i<n;i++){
            map[str[i]]++;
        }

        priority_queue<pair<char,int>>pq;//pair

        for(auto &x:map){
            pq.push(x);
        }
        string s="";
        while(pq.size()>0){
            auto largest=pq.top();
            pq.pop();
            int len=min(largest.second,repeatLimit);

            for(int i=0;i<len;i++){
                s+=largest.first;
            }


            if(largest.second-len>0){
                if(!pq.empty()){
                    auto secondLargest=pq.top();
                    pq.pop();
                    s+=secondLargest.first;

                    if(secondLargest.second-1>0){
                        pq.push({secondLargest.first,secondLargest.second-1});
                    }
                }
                else return s;

                pq.push({largest.first,largest.second-len});
            }
        }
        return s;
    }
};