// O(sqrt(N))
vector<ll> getFactors(ll n){
    vector<ll> v;
    for(ll i=1; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i != n/i)
                v.push_back(n/i);
        }
    }
    return v;
}