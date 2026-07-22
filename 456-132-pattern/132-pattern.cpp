class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        set<int> st3;
        priority_queue<int, vector<int>, greater<int>> st1;

        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            st3.insert(nums[i]);
            map[nums[i]]++;
        }

        map[nums[0]]--;
        st1.push(nums[0]);
        if(map[nums[0]]<=0) map.erase(nums[0]);
        st3.erase(nums[0]);
        if(map[nums[0]]>0) st3.insert(nums[0]);


        for(int i=1;i<n;i++){
            int least=st1.top();
            int curr=nums[i];
           

            auto it = st3.lower_bound(curr);
            if (it != st3.begin()) {
                --it;
                if (*it > least) {
                    return true;
                }
            }
           
            st3.erase(curr);
            map[curr]--;
            if(map[curr]==0) map.erase(curr);
            if(map[curr]>0) st3.insert(curr);
            st1.push(curr);
        }
        return false;
    }
};