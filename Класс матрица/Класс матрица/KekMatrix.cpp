#include "KekMatrix.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>  // Описания функций ввода-вывода
#include <stdlib.h> // Описания функций malloc и free

KekMatrix::~KekMatrix()
{
	for (int i = 0; i < rows; i++)
		delete p[i];
	delete[] p;
}
void KekMatrix::setKekMatrix()
{
	std::ifstream fin("Task.txt");
	if (fin.is_open())
	{
		char buf[256];// массив чаров
		char symbol;
		if (cols == 0 || rows == 0)
		{
			for (char buf[256]; fin.getline(buf, 256); cols++);
		fin.clear();  // очищает флаги ошибок
		fin.seekg(0, std::ios_base::beg);// вот это позволяет выбрать любую позицию в файле, 
			for (int n = 0; !fin.eof(); n++)// eof - конец файла
			{
				double kek;
				fin >> kek;
				rows++;
				fin.get(symbol);
				if (symbol == '\n') break;
			}
		}
		fin.seekg(0, std::ios::beg);
		p = new double* [cols];
		for (int i = 0; i < cols; i++)
		{
			p[i] = new double[rows];
		}
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				fin >> p[i][j];
				std::cout << p[i][j] << "\t";
			}
			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "Файл не найден." << std::endl;
	}
	std::cout << "--------------------------^^Матрица из файла^^-----------------------" << std::endl;
}
void KekMatrix::UmnojenieNaChislo(int num)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			p[i][j] *= num;
		}
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			std::cout << std::showpoint << std::fixed << std::setprecision(4) << p[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "-------------------------------^^Умноженная на число^^-------------------------------" << std::endl;
}
void  KekMatrix::transpon()
{
	double** tmp = new double* [cols];
	for (int i = 0; i < cols; i++)
	{
		tmp[i] = new double[rows];
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			tmp[i][j] = p[j][i];
		}
	}
	p = tmp;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			std::cout << std::showpoint << std::fixed << std::setprecision(4) << p[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "-----------------------------------------^^Транспонированная^^---------------------------------------" << std::endl;
}
double gaussMethod(int n,int m,double** a)
{
	double det = 1;
  	for (int i = 0; i < n; ++i) 
	{
		int k = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (abs(a[j][i]) > abs(a[k][i]))   
			{
				k = j;
			}
		}
		std::swap(a[i], a[k]);
		if (i != k)
		{
			det = -det;
		}
		for (int j = i + 1; j < n; ++j)
		{
			a[i][j] /= a[i][i];
		}
		for (int j = 0; j < n; ++j)
		{
			if (j != i)
			{
				for (int k = i + 1; k < n; ++k)
				{
					a[j][k] -= a[i][k] * a[j][i];
				}
			}
		}
		det *= a[i][i];
	}
	return det;
}
void  KekMatrix::det()
{
	double det;
	det = gaussMethod(cols, rows, p);
	std::cout << det << std::endl;
	std::cout << "---------------------------^^Определитель^^---------------------------" << std::endl;
}
void inversion(double** A, int N)
{
	double x;
	double** E = new double* [N];
	for (int i = 0; i < N; i++)
	{
		E[i] = new double[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			E[i][j] = 0.0;

			if (i == j)
			{
				E[i][j] = 1.0;
			}
		}
	}
	for (int k = 0; k < N; k++)
	{
		x = A[k][k];

		for (int j = 0; j < N; j++)
		{
			A[k][j] /= x;
			E[k][j] /= x;
		}

		for (int i = k + 1; i < N; i++)
		{
			x = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * x;
				E[i][j] -= E[k][j] * x;
			}
		}
	}
	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			x = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * x;
				E[i][j] -= E[k][j] * x;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = E[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		delete[] E[i];
	}
	delete[] E;
}
void KekMatrix::Obratnaya()
{
	inversion(p, cols);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			std::cout << std::showpoint << std::fixed << std::setprecision(4) << p[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "---------------------------------^^Обратная^^-------------------------------------" << std::endl;
}
void KekMatrix::Zapoln()
{
	std::fstream fs;
	fs.open("1.Txt", std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Ne otkril file" << std::endl;
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			fs << std::showpoint << std::fixed << std::setprecision(4) << p[i][j] << "\t";
		}
		fs << std::endl;
	}
	fs.close();
	std::cout << "---------------------------------Произошла запись-------------------------------------" << std::endl;
}