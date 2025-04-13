#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7; // Remove or change if no modulus

struct Matrix {
    ll a, b, c, d;
    Matrix(ll a=1, ll b=1, ll c=1, ll d=0) : a(a), b(b), c(c), d(d) {}
};

Matrix multiply(Matrix m1, Matrix m2) {
    return Matrix{
        (m1.a * m2.a + m1.b * m2.c) % MOD,
        (m1.a * m2.b + m1.b * m2.d) % MOD,
        (m1.c * m2.a + m1.d * m2.c) % MOD,
        (m1.c * m2.b + m1.d * m2.d) % MOD
    };
}

Matrix power(Matrix m, ll n) {
    if (n == 1) return m;
    if (n % 2 == 0) {
        Matrix half = power(m, n / 2);
        return multiply(half, half);
    } else {
        return multiply(m, power(m, n - 1));
    }
}

ll fib(ll n) {
    if (n == 0) return 0;
    Matrix base;
    Matrix result = power(base, n - 1);
    return result.a; // F(n)
}

int main() {
    ll n;
    cin >> n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    cout << fib(n) << endl;
    return 0;
}
