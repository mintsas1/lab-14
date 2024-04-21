#include <iostream>
using namespace std;


void getDivisors(int n, int divisors[], int& size) {
    size = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors[size++] = i;
            if (i != n / i) {
                divisors[size++] = n / i;
            }
        }
    }
}


bool binarySearch(const int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int number;
    cout << "Enter a six-digit decimal integer: ";
    cin >> number;

    const int MAX_SIZE = 100; 
    int divisors[MAX_SIZE];
    int size; 

    getDivisors(number, divisors, size);

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (divisors[j] > divisors[j + 1]) {
                int temp = divisors[j];
                divisors[j] = divisors[j + 1];
                divisors[j + 1] = temp;
            }
        }
    }

    int goal;
    cout << "Enter the divisor to find: ";
    cin >> goal;

    bool found = binarySearch(divisors, size, goal);

    if (found) {
        cout << "Divisor " << goal << " found." << endl;
    }
    else {
        cout << "Divisor " << goal << " not found." << endl;
    }

    return 0;
}

