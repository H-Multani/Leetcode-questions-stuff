class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // okay toh eg2 dekh kar lagra ki khud ko count nai kar rahe hai ans me
        // , toh 1 wala bolra hai ki mere alaba mere clr ka 1 banda aur hai

        // tabhi dono 1 wale could be of same colour in eg1,

        // similarly eg2 me 10 wala banda bolra hai ki mere alava mere color ke
        // 10 bande aur hai , toh ttl 11  bande hue

        // toh agar banda bolra ki n bande hai mere color ke, toh including
        // itself there can be n+1 bande with same colour at minm

        // toh jo banda bolra hai 10 bande hai mere color ke, possible minm 11
        // bande ho sakte hai same color ke, uske baad color change hora hoga
        // pakka, and apan ko minm wala case nikalna hai toh apan club kar sakte
        // hai ki agar 10 wale 3 bande hai toh minm to minm saare same grp ke
        // honge toh overall grp me 11 log honge, which is ans for eg2

        // similary agar 1 bolne waale 2 bande hai toh they can be kepy on
        // common grp toh counted once only, ie we assume ki vo 2 bande common
        // grp me hai (same colour), hence apan cnt +2 karenge

        // if 2 bolne waale kitne bande hai, theres 2 cases here onwards
        // case 1: agar 2 bolne waale 2(<=n+1 basically) bande hai means ye
        // dono common grp ke hai and 3 rd waale(rest) se pucha nai hoga like
        // 2(asked),2(asked),2(not asked), toh common color waale 3 bande minm,
        // yehi count kar lenge

        // similar case agar 4 bolne wale 3 bande hai, means its like this
        // 4(asked),4(asked),4(asked),4(not asked),4(not asked)
        // ie jin 3 logo ne bola hai ki same color wale 4 bande aur hai, sabko
        // same grp me daal diya apan ne and minm ke liye 2 bande aur honge uss
        // grp me same colour kr jinho se pucha nai hoga forest me, toh cnt +5
        // add karenge apan to count the 5 rabits (3 that asnwered, 2 that
        // didnt)

        // case 2: agar 2 bolne waale 4,5,6(>n+1 basically),means ki 3-3(n+1) ke
        // grps banenge, and bache kuche alag rahenge,
        // like 2,2,2,2, isme se first 3 are of same grp(minimize krna hai apan
        // ko) and the last wala 2 bolne wala banda is in another grp with a
        // different color like {2(asked),2(asked),2(asked)}-> red color, then
        // {2(asked),2(not asked),2(not asked)}-> blur color, toh in total apan
        // cnt+=+6 karenge, for 4 bande that were asked, and 2 that were not
        // asked

        // grps ko biforcate karenge toh red color={2(asked),2(asked),2(asked)},
        // ye grp me 3 bande hai, each banda bolra hai ki mere color ke mere
        // alava 2 bande hai, idx 0 wala bolra mere color ke 2 bande hai idx 1
        // and 2 wale, idx 1 wala bolra mere color ke 2 bande idx 0 and 2
        // wale,idx 2 wala bolra mere color ke 2 bande idx 0 and 1 wale

        // blue color={2(asked),2(not asked),2(not asked)},
        // ye grp me 3 bande hai, each banda bolra hai ki mere color ke mere
        // alava 2 bande hai, idx 0 wala bolra mere color ke 2 bande hai idx 1
        // and 2 wale, idx 1 wala bolra mere color ke 2 bande idx 0 and 2
        // wale,idx 2 wala bolra mere color ke 2 bande idx 0 and 1 wale

        // yehi karna hai apan ko basically n+1 size kr grps banane hai cnt krna
        // hai

        // toh sabse pehle count karlo ki kitne bande kitni freq par hai
        unordered_map<int, int> mpp;
        // mpp per iterate krte time, it.first=4, it.second=6 means ki 6 bande
        // hai jo bolre hai ki mere alava, same color ke 4 bande hai, these 6 is
        // the no of people asked, toh bifurcation time, n+1=5, ie 5-5 ke grps
        // banenge like red->{4(asked),4(asked),4(asked),4(asked),4(asked)} and
        // blue->{4(asked),4(not asked),4(not asked),4(not asked),4(not asked)}

        // map bharo
        for (auto it : answers)
            mpp[it]++;

        int ans = 0;

        // ab map me iterate karke bharo ans ko
        for (auto it : mpp) {
            int n = it.first;
            // n+1 size ke groups banenge

            // no need for this edge case ig, since normal code handle kar lera
            // hai

            // edge case, n=0 waale bande iklote honge, ie vo bolre hai ki mere
            // alava mere color ka koi nai hai, toh unka freq seedhe seedhe add
            // kar denge apan

            // if (n == 0) {
            //     ans += it.second;
            //     continue;
            // }

            if (it.second <= n + 1) {
                // means saare 1 grp me hi aa jaenge, n+1 add karo bass ans me,
                // since minm n+1 bande honge 1 grp me including rabbits that
                // were asked and not asked
                ans += n + 1;
            } else {
                // we here means n+1 size each ke groups banenge,
                int freq = it.second;

                // itne bande apan ko n+1 ke grps me daalne hai laga do
                // no of grps=freq/(n+1)

                // har grp me n+1 bande rahenge minm, if 5 grps ban rahe hai toh
                // 4 grps me jitne bande hai sabse ask kiya tha, and last waale
                // grp me bas kuch rabbits honge jinse nai ask kiya
                // hoga(possibly 0 agar freq%(n+1)==0, ie all fit exactly in n+1
                // ke grps)

                // ye 4 grps ke colours separate rahenge btw, even though common
                // size h grp ka, colours mght be red,green, etc
                int grps = freq / (n + 1);

                // agar log bach rahe hai toh last wala grp me kuch rabbit honge
                // which were not asked, uss grp ko count kar lena
                if (freq % (n + 1) != 0)
                    grps++;

                // ab har grp me n+1 bande honge, toh count karlo
                ans += grps * (n + 1);
            }
        }

        return ans;
    }
};