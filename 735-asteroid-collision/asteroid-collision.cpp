class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(nums[i]);
        }
        stack<int>helper;
        vector<int>ans;
        while(st.size()>0){
            while(st.size()>0 && st.top()>0){
                ans.push_back(st.top());
                st.pop();
            }

            while(st.size()>0 && st.top()<0){
                helper.push(st.top());
                st.pop();
            }

            if(st.size()>0){
                int x=st.top();
                st.pop();

                int y=helper.top();
                helper.pop();

                y=-y;
                if(y>x) st.push(-y);
                else if(x>y) st.push(x);
            }
            else if(st.size()==0){// means all were negative
                while(helper.size()>0){
                    st.push(helper.top());
                    helper.pop();
                }
                while(st.size()>0){
                    ans.push_back(st.top());
                    st.pop();
                }
                break;
            }
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};