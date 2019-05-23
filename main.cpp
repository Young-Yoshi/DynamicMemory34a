#include <iostream>
using namespace std;
#define tab "\t"

/*
TODO:
1. git clone https://github.com/okovtun/DynamicMemory2_34a
2. Вместо передачи массива в функцию по указателю, сделать передачу по ссылке.
void push_row_back(int**& Arr, int& m, const int n);

*/

/*
DONE:
0. Вывести двумерный динамический массив на экран, используя Арифметику указателей, и оператор разыменования;
1. Написать функцию ??? push_row_back(???), которая добавляет пустую строку (заполненную нулями) в конец массива;
2. Написать функцию ??? push_row_front(???), которая добавляет пустую строку в начало массива;
3. Написать функцию ??? insert_row(???), которая добавляет пустую строку в массив по указанному индексу;
4. Написать функцию ??? pop_row_back(???), которая удаляет строку из конца массива;
5. Написать функцию ??? pop_row_front(???), которая удаляет строку с начала массива;
6. Написать функцию ??? erase_row(???), которая удаляет строку из массива, по указанному индексу;
*/
//ROWS
void FillRand(int** Arr, const int m, const int n);
void Print(int** Arr, const int m, const int n);
void Delete(int** Arr, const int m, const int n);

void PushRowBack(int **& Arr, int& m, int& n);
void PushRowFront(int **& Arr, int& m, int& n);
void InsertRow(int **& Arr, int& m, int& n, long long int& index);

void PopRowBack(int **& Arr, int& m, int& n);
void PopRowFront(int **& Arr, int& m, int & n);
void EraseRow(int **& Arr, int& m, int& n, long long int& index);

//COLS
void PushColBack(int** Arr, int& m, int& n);
void PushColFront(int** Arr, int& m, int& n);
void InsertCol(int** Arr, const int m, int& n, long long int& index);

void PopColBack(int** Arr, const int m, int& n);
void PopColFront(int** Arr, const int m, int& n);
void EraseCol(int** Arr, const int m, int& n, long long int& index);

void main()
{
	setlocale(0, "");
	for (int i = 0; i < 85; i++)
	{
		if (i >= 40 && i < 41)
		{
			cout << "---ROWS---";
		}
		else
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 85; i++)
	{
		cout << "=";
	}
	cout << endl;

	int m;		//Строки
	int n;		//Элемент строки
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введиет количество элементов строк: "; cin >> n;
	cout << endl;

	int** Arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n] {};
	}
	FillRand(Arr, m, n);
	Print(Arr, m, n);

	cout << "---PushRowBack---";
	cout << endl;
	PushRowBack(Arr, m, n);
	Print(Arr, m, n);

	cout << "---PushRowFront---";
	cout << endl;
	PushRowFront(Arr, m, n);
	Print(Arr, m, n);

	cout << "---InsertRow---";
	cout << endl;
	long long int index;
	cout << "Add to row by index: "; cin >> index;
	InsertRow(Arr, m, n, index);
	Print(Arr, m, n);

	cout << "---PopRowBack---";
	cout << endl;
	PopRowBack(Arr, m, n);
	Print(Arr, m, n);

	cout << "---PopRowFront---";
	cout << endl;
	PopRowFront(Arr, m, n);
	Print(Arr, m, n);

	cout << "---EraseRow---";
	cout << endl;
	cout << "Remove the to row by index: "; cin >> index;
	EraseRow(Arr, m, n, index);
	Print(Arr, m, n);
	cout << endl;
	cout << endl;

	cout << "---COLS---";
	cout << endl;
	FillRand(Arr, m, n);
	Print(Arr, m, n);

	cout << "---PushColBack---";
	cout << endl;
	PushColBack(Arr, m, n);
	Print(Arr, m, n);
	cout << endl;

	cout << "---PushColFront---";
	cout << endl;
	PushColFront(Arr, m, n);
	Print(Arr, m, n);
	cout << endl;

	cout << "---InsertCol---";
	cout << endl;
	cout << "Введите элемент строки: "; cin >> index;
	InsertCol(Arr, m, n, index);
	Print(Arr, m, n);
	cout << endl;

	cout << "---PopColBack---";
	cout << endl;
	PopColBack(Arr, m, n);
	Print(Arr, m, n);
	cout << endl;
	cout << "---PopColFront---";
	cout << endl;
	PopColFront(Arr, m, n);
	Print(Arr, m, n);
	cout << endl;

	cout << "---EraseCol---";
	cout << endl;
	cout << "Введите интекс: "; cin >> index;
	EraseCol(Arr, m, n, index);
	Print(Arr, m, n);
	cout << endl;

	Delete(Arr, m, n);
}
//ROWS
void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(*(Arr + i) + j) = rand() % (80 - 50) + 50;
		}
	}
}
void Print(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
void Delete(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}

void PushRowBack(int **& Arr, int& m, int& n)
{
	int** Buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i];
	}
	delete[]Arr;
	Arr = Buffer;
	Arr[m] = new int[n] {};
	m++;
	//return *Arr;
}
void PushRowFront(int **& Arr, int& m, int& n)
{
	int** Buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)
	{
		Buffer[i + 1] = Arr[i];
	}
	delete[] Arr;
	Arr = Buffer;
	Arr[0] = new int[n] {};
	m++;
	//return *Arr;
}
void InsertRow(int **& Arr, int& m, int& n, long long int& index)
{

	int** Buffer = new int*[m + 1];
	for (int i = 0; i < index; i++)
	{
		Buffer[i] = Arr[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i + 1] = Arr[i];
	}
	delete[] Arr;
	Arr = Buffer;
	Arr[index] = new int [n] {};
	m++;

	//return Arr;
}

void PopRowBack(int **& Arr, int& m, int& n)
{
	int** Buffer = new int*[--m];
	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i];
	}
	delete[] Arr;
	Arr = Buffer;
	//m--;
	//return Arr;
}
void PopRowFront(int **& Arr, int& m, int & n)
{
	int** Buffer = new int*[m - 1];
	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i + 1];
	}
	delete[] Arr;
	Arr = Buffer;
	m--;
	//return Arr;
}
void EraseRow(int **& Arr, int& m, int& n, long long int& index)
{
	int** Buffer = new int*[m];

	for (int i = 0; i < index; i++)
	{
		Buffer[i] = Arr[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i] = Arr[i + 1];
	}
	Arr = Buffer;
	m--;
	//return Arr;
}

//COLS
void PushColBack(int** Arr, int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}
void PushColFront(int** Arr, int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}
void InsertCol(int** Arr, const int m, int& n, long long int& index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}

void PopColBack(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
	//return Arr;
}
void PopColFront(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int*Buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
	//return Arr;
}
void EraseCol(int** Arr, const int m, int& n, long long int& index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
	//return Arr;
}