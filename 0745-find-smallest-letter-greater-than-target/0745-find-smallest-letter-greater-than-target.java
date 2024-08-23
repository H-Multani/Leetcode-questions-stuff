class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left=0,right=letters.length-1;
        int ans=right+1;
        while(left<=right){
            int mid=(right+left)/2;
            if(letters[mid]>target){
                // current is a possible ans update
                ans=mid;
                // and now we need to go left to chk out smallest values
                right=mid-1; 
            }
            else{
                left=mid+1;
            }
        }
        if(ans==letters.length) return letters[0];
        return letters[ans];

    }
}