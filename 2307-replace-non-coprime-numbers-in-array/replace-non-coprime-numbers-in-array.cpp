class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>st;

        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            st.push(x);
            while(st.size()>1){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();

                long long gcd= __gcd(a, b);
                if(gcd>1){
                    st.push((a*b)/gcd);
                }
                else{
                    st.push(b);// push b first because this was the order of pushing ,like in thus way b will be bellow and a above
                    st.push(a);
                    break;
                }
            }
        }
        vector<int>ans;
        while(st.size()>0){
            ans.push_back((int)st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};