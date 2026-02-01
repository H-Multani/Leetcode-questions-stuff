class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // okay toh ek cheez toh mandatory hai, ki kitna effort maar lo first
        // element ko hamesha consider karna padega ans me

        // ab best case scenario hai ki smallest element se start hone wale 3
        // subarrays bana sakte hai, if x,y,z are 3 smallest elemnts(x<y<z), and
        // array is like [f,....,x,...y,...,z...] toh iss case me first subarray
        // toh f se x tak banega, then x to y second subarray, then y to end
        // element will be last subarray, this way apan ne smallest elements
        // consider kar liye hai which start the subarrays

        // toh sbse pehle toh ek copy bana lo array ka, and uss copy ko sort
        // karlo

        vector<int> cpy = nums;

        sort(cpy.begin(), cpy.end());

        // ab first,second,third smallest nikalo

        int f = cpy[0], s = cpy[1], t = cpy[2];

        // ab check if first element of nums is any of these 3 elements

        if (nums[0] == f || nums[0] == s || nums[0] == t) {
            // means array is like [x,...y,....z....], iss case me smallest
            // element se hi start honge subarrays, which is best

            // iss case me ans will be x+y+z, since apne preferred element se hi
            // chalu hora hai first wala subarray, beech wale elements dont
            // matter, at worst case if case is like [x,y,z....] 100 elements,
            // then subarrays will be like [x],[y],[z...97 elements], iss case
            // me bhi ans will be x+y+z which is best ans we can get
            return f + s + t;
        }

        // we here means subarray is like [f,...x...y...z...], iss case me best
        // ans we can make is f+x+y, since first wala subarray f se hi start
        // hoga wether you like it or not, lekin baaki 2 subarrays apan x and y
        // se start karke khatam kar sakte , hence in such case ans will be
        // f+x+y, since x<y<z, essentially its
        // first_element+first_smallest+second_smallest, since iss case me hi
        // best ans aa sakta hai , since array wll be [f....x....y....], toh
        // worst case me agar array is like [f,x,y....] 100 elements, we can
        // make arrays like [f],[x],[y.....97 elements]

        // overall iss case me ans is first+x+y

        return nums[0]+f+s;
    }
};