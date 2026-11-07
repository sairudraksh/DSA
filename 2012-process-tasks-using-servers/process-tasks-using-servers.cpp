class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> available;

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> busy;

        vector<int>ans(m);

        for(int i=0;i<n;i++){
            available.push({servers[i],i});
        }
        long long t=0;
        for(int i=0;i<m;i++){
            t=max(t,(long long)i);

            while(busy.size()>0 && busy.top()[0]<=t){
                available.push({(int)busy.top()[1],(int)busy.top()[2]});
                busy.pop();
            }

            if(available.size()==0){
                t=busy.top()[0];

                while(busy.size()>0 && busy.top()[0]<=t){
                    available.push({(int)busy.top()[1],(int)busy.top()[2]});
                    busy.pop();
                }
            }

            auto[weight,idx]=available.top();
            available.pop();

            ans[i]=idx;

            busy.push({t+tasks[i],weight,idx});
        }

        return ans;

    }
};