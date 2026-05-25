class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>v;

        for(int i=1;i<=n;i++){
            string s=to_string(i);

            v.push_back(s);
        }

        sort(v.begin(),v.end());

        vector<int>ans;

        for(int i=0;i<v.size();i++){
            int num=stoi(v[i]);

            ans.push_back(num);
        }
        return ans;
    }
};