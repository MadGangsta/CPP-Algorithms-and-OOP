#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Derevo
{
public:
	Derevo();
	class Node
	{
	public:
		double data;
		Node* left;
		Node* right;
		Node(double data = 0, Node* left = nullptr, Node* right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	Node* centr;
	void Dobavit(double, Node*&);
	void SetArr();
	int Visota(Node*&);
	void sortrovka(Node*&);
	void SozdanieDereva();
	void Otrisovka(Node*&);

private:
	int k = 0;
	int Size = 0;
	int HeightTree = 1;
	double* a;
};