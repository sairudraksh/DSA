class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n=positions.size();
        stack<pair<pair<int,int>,pair<char,int>>>st1;
        vector<pair<pair<int,int>,pair<char,int>>>v;

        for(int i=0;i<n;i++){
            v.push_back({{positions[i],health[i]},{directions[i],i}});
        }

        sort(v.begin(),v.end());

        for(int i=n-1;i>=0;i--){
            st1.push(v[i]);
        }

        stack<pair<pair<int,int>,pair<char,int>>>st2;

        st2.push(st1.top());
        st1.pop();

        while(st1.size()>0){
            if(st2.size()>0){
                if(st2.top().second.first=='R' && st1.top().second.first=='L'){
                    char ch1=st2.top().second.first;
                    char ch2=st1.top().second.first;

                    auto p1=st1.top().first;
                    auto p2=st2.top().first;

                    int idx2=st2.top().second.second;
                    int idx1=st1.top().second.second;

                    if(p1.second==p2.second){
                        st1.pop();
                        st2.pop();
                    }
                    else if(p1.second<p2.second){
                        st2.pop();
                        st1.pop();
                        st2.push({{p2.first,p2.second-1},{ch1,idx2}});
                    }
                    else{
                        st2.pop();
                        st1.pop();
                        st1.push({{p1.first,p1.second-1},{ch2,idx1}});
                    }
                }
                else{
                    st2.push(st1.top());    
                    st1.pop();
                }
            }
            else{
                st2.push(st1.top());    
                st1.pop();
            }
        }
        unordered_map<int,int>map;
        while(st2.size()>0){
            auto p=st2.top().second;
            auto p2=st2.top().first;
            map[p.second]=p2.second;
            st2.pop();
        }
        vector<int>v1;
        for(int i=0;i<positions.size();i++){
            if(map.find(i)!=map.end()){
                v1.push_back(map[i]);
            }
        }
        return v1;
    }
};