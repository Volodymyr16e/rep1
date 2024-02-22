#include <iostream>
using namespace std;

// Функція для введення масиву
void inputArray(int*& arr, int& n) {
    cout << "Введіть розмір масиву: ";
    cin >> n;

    // Виділення пам'яті для масиву
    arr = new int[n];
    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i << ": ";
        cin >> arr[i];
    }
}

// Функція для підрахунку нульових елементів у масиві
int countZeroElements(const int* arr, int n) {
    int zeroCount = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

// Функція для пошуку останнього максимального від'ємного елемента
int findLastMaxNegativeIndex(const int* arr, int n, int T) {
    int maxNegativeIndex = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] < 0 && arr[i] > arr[T] && i > T) {
            // Шукаємо найбільший від'ємний елемент, що знаходиться правіше від елемента T
            if (maxNegativeIndex == -1 || arr[i] >= arr[maxNegativeIndex]) {
                maxNegativeIndex = i;
            }
        }
    }
    return maxNegativeIndex;
}

int main() {
    int choice = -1;
    int* arr = nullptr;
    int n = 0;
    int T = 0;

    while (choice != 0) {
        setlocale(LC_CTYPE, "Ukr");
        cout << "Виберіть дію:\n";
        cout << "1. Ввести розмір масиву та елементи\n";
        cout << "2. Знайти кількість нульових елементів\n";
        cout << "3. Знайти номер останнього максимального від'ємного елемента\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Викликаємо функцію для введення масиву
            inputArray(arr, n);
            break;
        case 2:
            if (arr == nullptr) {
                cout << "Масив ще не було введений!\n";
                break;
            }
            // Виводимо кількість нульових елементів
            cout << "Кількість нульових елементів у масиві: " << countZeroElements(arr, n) << endl;
            break;
        case 3:
            if (arr == nullptr) {
                cout << "Масив ще не було введений!\n";
                break;
            }
            cout << "Введіть значення T: ";
            cin >> T;
            // Знаходимо та виводимо індекс останнього максимального від'ємного елемента
            cout << "Номер останнього максимального від'ємного елемента, розташованого правіше елемента, рівного T: " << findLastMaxNegativeIndex(arr, n, T) << endl;
            break;
        case 0:
            cout << "Дякую за використання програми!\n";
            break;
        default:
            cout << "Невірний вибір!\n";
            break;
        }
    }

    // Звільняємо пам'ять, що була виділена для масиву
    delete[] arr;

    return 0;
}
