    int mod=1e9+7;
    // sirf isko bahar define krne se tle set hora
class Solution {
public:
    
    // binary exponentiation wala get power funcn likho
    int getpower(long long a, long long b){
        if(b==0) return 1;

        long long half=getpower(a,b/2);
        long long ans=(half*half)%mod;

        if(b%2==1){
            ans=(ans*a)%mod;
        }

        return ans;
    }

    // ncr ka formula nikalne ke liye
    long long ncr(int n, int r,vector<long long>& fact, vector<long long>& fermatfact){
        // formula is 
        // ((n!)/((n-r!) * (r!)))%mod

        // which can be written as
        // n! -> fact[n]
        // 1/(n-r)! => ((n-r)!)^(mod-2) => fermatfact[n-r]

        return (((fact[n]* fermatfact[n-r])%mod)*(fermatfact[r]))%mod;

        // factorial ka need hoga bana lo
    }
    int countGoodArrays(int n, int m, int k) {

        // factorial array banao
        // n! tak ka need hoga toh n+1 size rakho
        vector<long long> fact(n+1,1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<n+1;i++){
            fact[i]=(i*(fact[i-1]))%mod;
        }

        // inverse factorial calculate karlo, using fermats little theorem
        vector<long long> fermatfact(n+1,1);
        for(int i=0;i<=n;i++){
            fermatfact[i]=getpower(fact[i],mod-2);
        }

        // ans was=> (n-1 C k)*(m)*((m-1)^(n-k-1))
        long long ans=ncr(n-1,k,fact,fermatfact);

        // ab ncr wala kaam done, *m karo
        ans=(ans*(m))%mod;

        // ab (m-1)^(n-k-1) karenge
        ans=(ans*(getpower(m-1,n-k-1)))%mod;

        return ans;
    }
};