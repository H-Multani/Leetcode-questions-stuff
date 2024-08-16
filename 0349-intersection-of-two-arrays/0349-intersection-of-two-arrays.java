class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        ArrayList<Integer> ans = new ArrayList<>();
        int[] finalans;
        ArrayList<Integer> num = new ArrayList<>();

        for (int it : nums2) {
            if (!num.contains(it)) {
                num.add(it);
            }
        }

        for (int i = 0; i < nums1.length; i++) {
            if (!ans.contains(nums1[i]) && num.contains(nums1[i])) {
                ans.add(nums1[i]);
            }
        }

        finalans = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            finalans[i] = ans.get(i);
        }

        return finalans;

    }
}