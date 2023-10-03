// to find primes optimally  ----
// is q=1e7 and n=1e7 traditionally time=1e7*sqrt(1e7) this will not pass tle..
// so precompute..
#include<bits./stdc++.h>
using namespace std;
const int N=1e7;
vector<bool> isprime(N,1); // intially all primes  --ispirme[i]-->means i is prime;
vector<int> lp(N,0),hp(N,0); // lp stores lowest prime for a number i; means if i=12 lp=2;hp=3;
int main(){
    isprime[0]=isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i]==true){
            lp[i]=hp[i]=i;// trivial for prime highest and lowest both same
            for(int j=2*i;j<N;j+=i){
                isprime[j]=false;   // j ka mtlb hain multiples of i means j is like i,2i,3i,4i... and mark all these numbers as not prime 
                hp[j]=i;  // ab tk kaunsa prime divide kr chuka hain
                if(lp[j]==0){   // till now no prime came for it than only
                    lp[j]=i;
                }
            }
        }
    }
    // finding prime factorisation
    int num;cin>>num;
    vector<int> prime_factors;
    while(num>1){
        int factor=hp[num];
        while(num%factor==0){
            num/=factor;
            prime_factors.push_back(factor);
        }
    }
    for(auto it:prime_factors){
        cout << it << " ";
    }
// time complexity of this now--
//n/2+n/3+n/4+n/5... if for all n =nlog(n);
// but this code is like n/2+n/3+n/5+n/7+n/7... for all primes in n time=nlog(log(n));
}
//ques--https://codeforces.com/contest/230/problem/B
