#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

map<ll, ll> memo;

// Calculates the sum of digits for all numbers from 1 to n
ll sum_of_digits_up_to(ll n) {
    if (n < 10) {
        return n * (n + 1) / 2;
    }
    if (memo.count(n)) {
        return memo[n];
    }
    string s = to_string(n);
    int d = s.length();
    ll p10 = 1;
    for (int i = 0; i < d - 1; ++i) p10 *= 10;
    ll first_digit = n / p10;
    // The recursive formula to calculate sum of digits up to n is:
    // fd * sum_of_digits_up_to(p10 - 1) -> Sum of digits for the remaining d-1 positions for each block
    // + (fd * (fd - 1) / 2) * p10 -> Sum of the most significant digit for all blocks before the current one
    // + fd * (n % p10 + 1) -> Sum of the most significant digit for the current partial block
    // + sum_of_digits_up_to(n % p10) -> Recursive call for the remaining part of the number
    ll res = first_digit * sum_of_digits_up_to(p10 - 1) +
             (first_digit * (first_digit - 1) / 2) * p10 +
             first_digit * (n % p10 + 1) +
             sum_of_digits_up_to(n % p10);
    return memo[n] = res;
}

void solve(){
    ll k;
    cin >> k;

    ll num_len = 1;
    ll count_of_numbers = 9;

    // 1. Find the block (num_len) where the k-th digit lies
    while (k > num_len * count_of_numbers) {
        k -= num_len * count_of_numbers;
        num_len++;
        count_of_numbers *= 10;
    }

    // 2. Find the number N that is being written at the k-th position
    ll start_num = 1;
    if (num_len > 1) {
        for (int i = 0; i < num_len - 1; ++i) start_num *= 10;
    }

    ll full_numbers_count = (k - 1) / num_len;
    ll last_full_number = start_num + full_numbers_count - 1;

    ll total_sum = 0;
    if (last_full_number >= 0) {
        total_sum = sum_of_digits_up_to(last_full_number);
    }

    ll current_number = start_num + full_numbers_count;
    ll remaining_digits = (k - 1) % num_len + 1;

    string s_current = to_string(current_number);
    for (int i = 0; i < remaining_digits; ++i) {
        total_sum += s_current[i] - '0';
    }

    cout << total_sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}