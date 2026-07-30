class Solution {
public:
    int minimumPushes(string word) {
        // toh ghum fir kar we have 8 keys to be mapped, 

        // simple way is to map each character to 1 key, according to frequency, like agar baar baar aara hai toh usko pehle map karna 1 push par,agar 1 push sab khatam ho jaaye fir 2 push par mapping karna

        // lekin question bola hai sab distinct hai letters,

        // iss case me simple rakho, har character ek button par map hoga, incase button kam pad jaaye toh 2 click par map hoga and so onn

        // toh like iss prblem bas ke liye, first 8 characters get 1 click, next 2 characters get 2 clicks and so on

        int click=0;
        int n=word.size();
        int ans=0;
        for(int i=0;i<n;i++){
            // current character ke liye kitne clicks lagenge
            click=i/8;

            ans+=click+1;

        }

        return ans;

    }
};