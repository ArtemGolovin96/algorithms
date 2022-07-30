#include <iostream>

using namespace std;

int fib(int n) {

    int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int readStringToNumber() {
    try {
        string n;
        cout << "Введите любое положительное число" << "\n";
        cin >> n;
        return stoi(n);
    } catch(const invalid_argument& e) {
        cout << "Введенные данные не подходят под условие" << "\n";
        return 0;
    };
};


int main() {
    int n;
    n = readStringToNumber();

    if (n >= 47) {
        cout << "Данное число Фибоначчи выходт за пределы типа int";
        return 0;
    }
    
    cout << " - result is -> " << fib(n) << "\n";

};