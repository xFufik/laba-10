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

    ifstream inputFile("C:\\laba 10\\input.txt"); 
    ofstream outputFile("C:\\laba 10\\output.txt");  

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл для чтения" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Не удалось открыть файл для записи" << endl;
        return 1;
    }

    inputFile >> N;

    if (N <= 0 || N > 50) {
        cerr << "Размер массива должен быть от 1 до 50" << endl;
        return 1;
    }

    int A[50];

    for (int i = 0; i < N; i++) {
        inputFile >> A[i];
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
    outputFile << "Количество убывающих участков: " << kol << endl;

    inputFile.close();
    outputFile.close();
}