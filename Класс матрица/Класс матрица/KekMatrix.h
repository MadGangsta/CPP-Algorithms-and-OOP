#pragma once
#include<string>
#include <iomanip>
class KekMatrix
{
public:
	~KekMatrix();
	void setKekMatrix();
	void UmnojenieNaChislo(int n);
	void transpon();
	void det();
	void Obratnaya();
	void Zapoln();
private:
	int cols;
	int rows;
	double** p;
};
