class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int ans = 0;
        int left = 0, right = people.length - 1;
        Arrays.sort(people);
        while (left <= right) {
            if (left == right) {
                // means we have reached the last person, (since left==right pr ek hi person
                // rahega)
                // in which case we give him 1 boat and break frm the loop
                ans++;
                break;
            } else if (people[left] + people[right] <= limit) {
                // means this combination of current lightest and current heaviest can be put on
                // same boat, in such a case we need 1 boat more
                // left and right ko aage badha deo
                left++;
                right--;
                ans++;
            } else {
                // means curr pair ka sum is too much over the limit of the boat
                // in this case we give the boat to the current heaviest and move to the next
                // heaviest
                // overall 1 more boat reqd and 1 heavy person used, so right-- only

                ans++;
                right--;
            }
        }
        return ans;

    }
}