class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int ans=letters.length;
        int left=0,right=letters.length-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(letters[mid]>target){
                ans=mid;
                // to decrease index, we go to left side
                right=mid-1;
            }
            else{
                // go right
                left=mid+1;
            }
        }
        if(ans==letters.length) return letters[0];

        return letters[ans];

    }
}