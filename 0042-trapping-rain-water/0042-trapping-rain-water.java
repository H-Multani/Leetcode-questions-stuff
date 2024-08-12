class Solution {
    public int trap(int[] height) {
        int len = height.length;
        int[] LtoR_Height = new int[len];
        int[] RtoL_Height = new int[len];

        LtoR_Height[0] = height[0];
        RtoL_Height[len - 1] = height[len - 1];

        // fill maxm height going L to R
        // current element ke left me konsa value maxm hai, coz uss height tk paani bhar
        // sakte hai, vo maxm value stored in LtoR_Height[i]
        for (int i = 1; i < len; i++) {
            LtoR_Height[i] = Math.max(LtoR_Height[i - 1], height[i]);
        }
        // fill maxm height going R to L
        // current element ke right me konsa value maxm hai, coz uss height tk paani bhar
        // sakte hai, vo maxm value stored in RtoL_Height[i]
        for (int i = len - 2; i >= 0; i--) {
            RtoL_Height[i] = Math.max(RtoL_Height[i + 1], height[i]);
        }

        // compare the 2 values, and add the amt of rainwater to ans
        int ans = 0;
        for (int i = 1; i < len - 1; i++) {
            int MaxmHeightJismePaaniBharSakta = Math.min(LtoR_Height[i], RtoL_Height[i]);

            int ActualHeightJismePaaniBharSakte = MaxmHeightJismePaaniBharSakta - height[i];

            ans += ActualHeightJismePaaniBharSakte;
        }


        return ans;

    }
}