#include <iostream>
#include <fstream>
using namespace std;

/*
* Лабораторная работа 10. Индивидуальный вариант 24.
* Реализовать любое задание лабораторной работы №5 с использованием файлового ввода-вывода.
* return 0 - все ок. return 1 - ошибка.
*/

int main() {
    setlocale(LC_ALL, "ru");

    int N, kol, length;
    length = 0;
    kol = 0;

    cout << "Введите количество элементов в массиве: ";
    cin >> N;

    if (N > 50) {
        cerr << "Количество элементов должно быть не более 50!";
        return 1;
    }

    ifstream inputfile("C:\\laba 10\\input.txt");
    ofstream outputfile("C:\\laba 10\\output.txt");

    if (!inputfile.is_open()) {
        cerr << "Не удалось открыть файл для чтения" << endl;
        return 1;
    }

    if (!outputfile.is_open()) {
        cerr << "Не удалось открыть файл для записи" << endl;
        return 1;
    }

    int A[50];

    for (int i = 0; i < N; i++) {
        inputfile >> A[i];
    }

    cout << "Ваш массив: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    for (int i = 1; i < N; i++) {
        if (A[i] < A[i - 1]) {
            length++;
        }
        else {
            if (length > 0) {
                kol++;
                length = 0;
            }
        }
    }

    if (length > 0) {
        kol++;
    }

    cout << "\nКоличество убывающих участков: " << kol;
    outputfile << "Ваш массив: ";
    for (int i = 0; i < N; i++) {
        outputfile << A[i] << " ";
    }
    outputfile << "\nКоличество убывающих участков: " << kol;

    inputfile.close();
    outputfile.close();
}
