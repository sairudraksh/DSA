class Solution {
    public int compress(char[] chars) {
        String ans="";
        int i=0;
        int n=chars.length;
        while(i<n){
            char ch=chars[i];
            int count=0;
            while(i<n && chars[i]==ch){
                count++;
                i++;
            }
            ans+=ch;
            if(count!=1){
                String s=Integer.toString(count);
                ans+=s;
            }
        }
        char[] arr=new char[ans.length()];
        for(int l=0;l<ans.length();l++){
            arr[l]=ans.charAt(l);
        }
        for(int l=0;l<arr.length;l++) {
            chars[l]=arr[l];
        }
        return ans.length();
    }
}