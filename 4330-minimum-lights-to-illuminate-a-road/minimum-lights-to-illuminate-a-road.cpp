class Solution {
public:
    int minLights(vector<int>& lights) {
         int n=lights.size();
        
        vector<int>diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]==0) continue;
            int l=max(0,i-lights[i]);
            int r=min(n-1,i+lights[i]);

            diff[l]++;
            diff[r+1]--;
        }

        vector<int>v;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];

            if(sum>0) v.push_back(1);
            else v.push_back(0);
        }


        int i=0;
        int count=0;
        while(i<n){
            if(v[i]==1){
                i++;
                continue;
            }

            int j=i;

            while(j<n && v[j]==0){
                j++;
            }

            int len=j-i;

            count+=(len+2)/3;
            i=j;
        }
        return count;
    }
};