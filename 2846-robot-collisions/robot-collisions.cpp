class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n=positions.size();
        stack<pair<pair<int,int>,pair<char,int>>> st1;
        vector<pair<pair<int,int>,pair<char,int>>> v;

        for(int i=0;i<n;i++){
            v.push_back({{positions[i],health[i]},{directions[i],i}});
        }

        sort(v.begin(),v.end());

        for(int i=n-1;i>=0;i--){
            st1.push(v[i]);
        }

        stack<pair<pair<int,int>,pair<char,int>>> st2;

        st2.push(st1.top());
        st1.pop();

        while(st1.size()>0){
            if(st2.size()>0){

                char ch1 = st2.top().second.first;
                char ch2 = st1.top().second.first;

                if(ch1=='R' && ch2=='L'){
                    
                    auto top2 = st2.top(); st2.pop(); // save before pop
                    auto top1 = st1.top(); st1.pop();

                    int h2 = top2.first.second;
                    int h1 = top1.first.second;

                    int idx2 = top2.second.second;
                    int idx1 = top1.second.second;

                    if(h1 == h2){
                        // both die
                    }
                    else if(h1 < h2){
                        st2.push({{top2.first.first,h2-1},{ch1,idx2}});
                    }
                    else{
                        // current survives → push back to st1 for chain collision
                        st1.push({{top1.first.first,h1-1},{ch2,idx1}});
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

        vector<int> ans(n,-1);
        while(st2.size()>0){
            auto p=st2.top();
            ans[p.second.second]=p.first.second;
            st2.pop();
        }

        vector<int>v1;
        for(int i=0;i<n;i++){
            if(ans[i]!=-1){
                v1.push_back(ans[i]);
            }
        }
        return v1;
    }
};