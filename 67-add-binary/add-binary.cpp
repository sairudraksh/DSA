class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;

        string result="";

        int sum=0;
        int carry=0;


        while(i>=0 || j>=0){
            sum=carry;

            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }

            result.push_back((sum%2==0) ? '0' : '1');
            carry=(sum>1)?1:0;
        }
        if(carry) result.push_back('1');
        reverse(result.begin(),result.end());
        return result;
    }
};