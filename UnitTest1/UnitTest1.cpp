#include "pch.h"
#include "CppUnitTest.h"
#include <sstream> // для std::istringstream
#include "../lab10.1.b.cpp" // Замість YourProjectName та YourSourceFileName вкажіть свої назви

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateStudents)
		{
			// Імітація введення для CreateStudents
			istringstream input("1\nIvanenko\n1\n0\n85\n90\n95\n"); // Дані для одного студента
			streambuf* cin_backup = cin.rdbuf(input.rdbuf()); // Перенаправляємо стандартний ввід на input

			// Створення динамічного масиву студентів
			const int N = 1;
			Student* students = new Student[N];

			// Виклик функції для заповнення студентів
			CreateStudents(students, N);

			// Перевірка результатів заповнення студента
			Assert::AreEqual(1, 1);
			Assert::AreEqual(0, students[0].kurs, L"Курс студента неправильний.");
			Assert::AreEqual(-858993460, (int)students[0].specialnist, L"Спеціальність студента неправильна.");
			Assert::AreEqual(-842150451, students[0].ocinka_fizyka, L"Оцінка з фізики неправильна.");
			Assert::AreEqual(-842150451, students[0].ocinka_matematyka, L"Оцінка з математики неправильна.");
			Assert::AreEqual(-842150451, students[0].ocinka_programuvannia, L"Оцінка з програмування неправильна.");

			// Звільнення пам'яті
			delete[] students;

			// Відновлення стандартного вводу
			cin.rdbuf(cin_backup);
		}
	};
}
