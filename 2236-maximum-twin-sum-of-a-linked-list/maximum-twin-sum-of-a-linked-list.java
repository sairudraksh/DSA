class Solution {
    public int pairSum(ListNode head) {
        int size=0;
        ListNode temp=head;
        while(temp!=null){
            temp=temp.next;
            size++;
        }
        int[] arr=new int[size];
        int i=0;
        int j=size-1;
        int maximum=0;
        temp=head;
        int idx=0;
        while(temp!=null){
            arr[idx]=temp.val;
            temp=temp.next;
            idx++;
        }
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum>maximum) maximum=sum;
            i++;
            j--;
        }
        return maximum;
    }
}