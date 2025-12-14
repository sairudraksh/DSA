class Solution {
    public static int[] find1(int[] arr,int n){
        int[] nse=new int[n];
        nse[n-1]=n;
        Stack<Integer>st= new Stack<>();
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                nse[i]=st.peek();
            }
            else{
                nse[i]=n;
            }
            st.push(i);
        }
        return nse;
    }
    public static int[] find2(int[] arr,int n){
        int[] pse=new int[n];
        pse[0]=-1;
        Stack<Integer>st= new Stack<>();
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && arr[st.peek()]>=arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                pse[i]=st.peek();
            }
            else{
                pse[i]=-1;
            }
            st.push(i);
        }
        return pse;
    }
    public int largestRectangleArea(int[] heights) {
        int n=heights.length;
        int[] nse=find1(heights,n);
        int[] pse=find2(heights,n);
        int maximum=0;
        for(int i=0;i<n;i++){
            int length=nse[i]-pse[i]-1;
            int height=heights[i];
            maximum=Math.max(maximum,length*height);
        }
        return maximum;
    }
}