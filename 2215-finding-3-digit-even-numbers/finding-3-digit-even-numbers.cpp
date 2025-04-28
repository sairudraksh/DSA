class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[digits[i]]++;
        }
        vector<int>ans;
        for(int i=100;i<999;i+=2){
            int x=i;
            int a=x%10;
            x=x/10;
            int b=x%10;
            x=x/10;
            int c=x;
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()){
                        ans.push_back(i);
                    }
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};