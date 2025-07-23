class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        priority_queue<string, vector<string>, greater<string>> minheap;
        priority_queue<string>maxheap;

        for(int i=0;i<products.size();i++){
            minheap.push(products[i]);
        }
        vector<vector<string>>finalans;
        vector<string>ans;
        for(int i=0;i<searchWord.size();i++){
            string s=searchWord.substr(0,i+1);
            while(true){
                if(minheap.empty() && ans.size()==0) break;
                else if(minheap.empty()){
                    while(!maxheap.empty()){
                        minheap.push(maxheap.top());
                        maxheap.pop();
                    }
                    break;
                }
                string s1=minheap.top().substr(0,i+1);

                if(s1==s){
                    if(ans.size()<3) ans.push_back(minheap.top());
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
            }
            finalans.push_back(ans);
            ans.clear();
        }
        return finalans;
    }
};