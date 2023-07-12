int rand(long long a, long long b) {return a + rand() % (b - a + 1);}
ll add(ll x, ll y) {ll res=x+y; return(res>=mod?res-mod:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=mod?res%mod:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+mod:res);}
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
ll cubic_root(ll x) {
    ll l = 0, r = 1e6;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x) r = m - 1;
        else l = m;
    }
    return l;
}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x) { return x && (!(x&(x-1)));}
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}