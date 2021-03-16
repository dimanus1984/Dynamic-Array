#include <iostream>
#include <ctime>
using namespace std;

void printArray(int* arr, int size);                  //Прототип функции
void printEven(int* arr, int size, int minSizeEven);  //Прототип функции
void printOdd(int* arr, int size, int minSizeOdd);    //Прототип функции

int main()
{
	setlocale(LC_ALL, "Russian");
	int minSizeEven = 7;
	int minSizeOdd = 7;
	int* arr = new int[10];                           //Выделяем память под массив arr

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 201 - 100;                  //Заполняем массив случайными числами в диапазоне от -100 до 100
	}
	cout << "\tИмеется 'arr' массив:\n\n";
	printArray(arr, 10);

	printEven(arr, 10, minSizeEven);

	printOdd(arr, 10, minSizeOdd);

	delete[] arr;                                     //Удалениие динамического массива:

	system("pause");                                  // Команда задержки экрана
	return 0;
}

void printArray(int* arr, int size)                   //Функция выводит массив arr в консоль
{
	cout << " | ";
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
		{
			cout << " | ";
		}
		cout << arr[i];
	}
	cout << " | " << "\n\n";
}

void printEven(int* arr, int size, int minSizeEven)
{
	//Новый массив с минимальным размером
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > 0)
		{
			minSizeEven++;
		}
	}

	int* even = new int[minSizeEven];            //Выделяем память под массив even для четных значений

	cout << "\tКопируем в 'even' массив положительные значения:\n\n";

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > 0)
		{
			even[i] = arr[i];
			cout << " | " << *(even + i);
		}
	}
	cout << " | " << "\n\n";

	delete[] even;                               //Удалениие динамического массива:
}

void printOdd(int* arr, int size, int minSizeOdd)
{
	//Новый массив с минимальным размером
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] < 0)
		{
			minSizeOdd++;
		}
	}

	int* odd = new int[minSizeOdd];              //Выделяем память под массив odd для нечетных значений

	cout << "\tКопируем в 'odd'  массив отрицательные значения:\n\n";

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] < 0)
		{
			odd[i] = arr[i];
			cout << " | " << *(odd + i);
		}
	}
	cout << " | " << "\n\n";

	delete[] odd;                                //Удалениие динамического массива:
}