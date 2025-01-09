#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to check if a number is palindromic
bool isPalindrome(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

// Function to generate a specific number of palindromic primes
vector<int> generatePalindromicPrimes(int count) {
    vector<int> palindromicPrimes;
    int num = 2;
    while (palindromicPrimes.size() < count) {
        if (isPrime(num) && isPalindrome(num)) {
            palindromicPrimes.push_back(num);
        }
        num++;
    }
    return palindromicPrimes;
}

int main() {
    int count;
    // cout << "Enter the number of palindromic primes to generate: ";
    cin >> count;

    vector<int> result = generatePalindromicPrimes(count);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
