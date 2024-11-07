#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// Перелік спеціальностей
enum Specialnist { KN, INF, ME, FI, TN };
string specialnistStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

// Структура для зберігання інформації про студента
struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    union {
        int ocinka_programuvannia;
        int ocinka_chyselni_metody;
        int ocinka_pedahohika;
    };
};

// Функція для створення масиву студентів
void CreateStudents(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << " Прізвище: ";
        cin >> students[i].prizv;
        cout << " Курс: ";
        cin >> students[i].kurs;

        int specialnist;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // Введення оцінок з фізики та математики
        cout << " Оцінка з фізики: ";
        cin >> students[i].ocinka_fizyka;
        cout << " Оцінка з математики: ";
        cin >> students[i].ocinka_matematyka;

        // Введення третьої оцінки залежно від спеціальності
        if (students[i].specialnist == KN) {
            cout << " Оцінка з програмування: ";
            cin >> students[i].ocinka_programuvannia;
        }
        else if (students[i].specialnist == INF) {
            cout << " Оцінка з чисельних методів: ";
            cin >> students[i].ocinka_chyselni_metody;
        }
        else {
            cout << " Оцінка з педагогіки: ";
            cin >> students[i].ocinka_pedahohika;
        }
        cout << endl;
    }
}

// Функція для виведення таблиці студентів
void PrintStudents(const Student* students, const int N) {
    cout << "==============================================================================================================================" << endl;
    cout << "| № | Прізвище          | Курс | Спеціальність          | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << "|  " << setw(16) << left << students[i].prizv
            << " | " << setw(4) << right << students[i].kurs
            << " |" << setw(23) << left << specialnistStr[students[i].specialnist]
            << " | " << setw(6) << right << students[i].ocinka_fizyka
            << " | " << setw(10) << right << students[i].ocinka_matematyka;

        if (students[i].specialnist == KN) {
            cout << " |  " << setw(12) << right << students[i].ocinka_programuvannia
                << " | " << setw(15) << "-"
                << " | " << setw(10) << "-";
        }
        else if (students[i].specialnist == INF) {
            cout << " | " << setw(12) << "-"
                << "  | " << setw(15) << students[i].ocinka_chyselni_metody
                << " | " << setw(10) << "-";
        }
        else {
            cout << " |" << setw(14) << "-"
                << " | " << setw(15) << "-"
                << " | " << setw(10) << students[i].ocinka_pedahohika;
        }
        cout << " |" << endl;
    }
    cout << "==============================================================================================================================" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    // Динамічний масив для студентів
    Student* students = new Student[N];

    // Виклик функцій для заповнення і виведення студентів
    CreateStudents(students, N);
    PrintStudents(students, N);

    // Звільнення пам'яті
    delete[] students;
    return 0;
}

//Введіть кількість студентів : 3
//
//Студент № 1 :
//    Прізвище : Іваненко
//    Курс : 2
//    Спеціальність(0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): 0
//        Оцінка з фізики : 4
//        Оцінка з математики : 5
//        Оцінка з програмування : 3
//
//        Студент № 2 :
//        Прізвище : Петренко
//        Курс : 1
//        Спеціальність(0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): 1
//            Оцінка з фізики : 3
//            Оцінка з математики : 5
//            Оцінка з чисельних методів : 5
//
//            Студент № 3 :
//            Прізвище : Коваленко
//            Курс : 3
//            Спеціальність(0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): 3
//                Оцінка з фізики : 4
//                Оцінка з математики : 5
//                Оцінка з педагогіки : 5
