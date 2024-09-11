#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Kelas untuk menghasilkan deret Fibonacci
class Fibonacci {
public:
    // Konstruktor
    Fibonacci(int n) : n(n) {}

    // Fungsi untuk menghasilkan deret Fibonacci
    vector<int> generate() {
        vector<int> fib;
        if (n <= 0) return fib;
        fib.push_back(0);
        if (n == 1) return fib;
        fib.push_back(1);

        for (int i = 2; i < n; ++i) {
            int next = fib[i - 1] + fib[i - 2];
            fib.push_back(next);
        }
        return fib;
    }

private:
    int n; // Jumlah elemen Fibonacci yang diinginkan
};

// Kelas untuk memeriksa bilangan prima
class Prime {
public:
    // Fungsi untuk memeriksa apakah bilangan adalah bilangan prima
    static bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }
};

// Program Utama
int main() {
    int n;

    // Input jumlah elemen Fibonacci yang diinginkan
    cout << "Masukan jumlah Fibonaci yang diinginkan : ";
    cin >> n;

    // Membuat objek Fibonacci
    Fibonacci fibGenerator(n);

    // Menghasilkan deret Fibonacci
    vector<int> fibonacciSeries = fibGenerator.generate();

    cout << "Deret Fibonaci : ";
    for (int num : fibonacciSeries) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Angka Bilangan prima pada deret Fibonaci di atas adalah :  ";
    for (int num : fibonacciSeries) {
        if (Prime::isPrime(num)) {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}
