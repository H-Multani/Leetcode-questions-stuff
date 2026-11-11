class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        // 1 wala need1 jitna chahiye
        // 2 wala need2 jitna chahiye
        // dono items common kitne chahiye min(need1,need2)
        // nikal lo yehi pehle
        int cnt = min(need1, need2);

        // ab ye cnt jitne need1 items chahiye AND need2 items chahiye, toh ye
        // lene ke 2 ways hai

        // way 1-> costboth utha lo cnt jitne, equivalent ho jayega
        // way 2-> cnt jitna cost1 uthao and cnt jitna cost2 uthao

        // dono me se jo minm cost dega wahi lenge

        // toh cnt bande uthane ka 2 tareeka either take (cnt*countboth) or
        // (cnt*cost1+ cnt*cost2), dono me se jo minm cost dede vo utha lo

        long long ans = min(1LL*cnt * costBoth, 1LL*cnt * (cost1 + cost2));

        // apne aap cnt jitne items ka minm cost ke hisab se utha lega aur kya

        // remaining items

        // type 1-> need1-cnt
        // type 2-> need2-cnt

        // ab itne toh lene hi hai alag se toh inke liye shanti se cost1 and
        // cost2 wale bande nikal lo


        // like maan lo type 1 ke 15 items needed and type 2 ke 8 items needed

        // toh cnt=min(need1,need2)-> cnt=8

        // toh itne 8 bande costBoth wale utha lenge apan (ya separate depending
        // on minm costing jo dede)

        // remaining items
        // type 1 -> 15-8=7
        // type 2 -> 8-8=0

        // toh type1 ke 7 items chahiye cost1 ke hisab se lelo aur kya

        // and type2 ke 0 items chahiye cost2 ke hisab se lelo aur kya

        // accha scene ye hai ab ki minm need1 and need2 jitna chahiye tha, toh
        // remaining ke liye bhi options rahenge

        // like maan lo eg1 me hi, cost1=3 and cost2=2, and costboth=1, meaning
        // type 1 akele lenge toh 3 ka cost, type 2 akele lenge toh 2 ka cost,
        // lekin sath me lenge toh 1 ka cost

        // iss case me toh jab apan ko sirf type1 wala banda chahiye iss case me
        // bhi both wala le lenge apan, since dekho we needed 7 items of type1->
        // cost1 ke hisab se lenge toh total cost=7*3=21, lekin both wala lenge
        // toh 7*1=7, haan yaha par type2 wale extra items aa gaye lekin overall
        // toh sasta pada na kaha 21 kaha 7 yehi logic laga denge


        // toh remaining ke liye normal ke alava costboth wale ka bhi dekh lena since ho sakta vo better deal ho
        ans += min(1LL*(need1 - cnt) * cost1, 1LL*(need1-cnt)*costBoth);
        ans += min(1LL*(need2 - cnt) * cost2, 1LL*(need2-cnt)*costBoth);

        // pura kaam khatam hone ke baad return krdo ans
        return ans;
    }
};