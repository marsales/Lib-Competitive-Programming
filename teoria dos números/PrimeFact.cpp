vector<ii> getprimes(int n) {
    vector<ii> primes;

    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;

        while (n % i == 0) {
            n /= i;
            cnt++;
        }

        if (cnt > 0) primes.push_back({i, cnt});
    }

    if (n > 1) primes.push_back({n, 1});

    return primes;
}
