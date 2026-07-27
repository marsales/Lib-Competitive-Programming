ll fexp(ll a, ll e, ll mod) {
    ll r = 1 % mod;
    a %= mod;

    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }

    return r;
}
