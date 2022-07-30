#include <iostream>

using namespace std;

int cache[50];
bool calc[50];

int f(int n) {
    if (calc[n]) {
        return cache[n];
    }

    if (n <= 1) {
        cache[n] = n;
    } else {
        cache[n] = f(n - 2) + f(n - 1);
    }
    
    calc[n] = true;
    
    return cache[n];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << f(i) << " ";
    }
}