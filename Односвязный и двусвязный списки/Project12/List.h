#pragma once
class List
{
public:
	List();
	~List();
	void clear();// �������� ������
	int GetSize() { return Size; }// �������� ���������� ��������� � ������
	int& operator[](const int index);// ������������� �������� [] 
	void insert(int data, int index);//���������� �������� � ������ �� ���������� �������
	void removeAt(int index);//�������� �������� � ������ �� ���������� �������
	void pop_front();//�������� ���������� �������� � ������
	void push_front(int data);//���������� �������� � ������ ������
protected:
	class Node
	{
	public:
		Node* pNext;
		int data;
		Node(int data = int(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
private:
	Node* head;
};

class List2 : public List
{
public:
	List2();
	~List2();
	void clear();
	void insert(int, int);
	int& operator[](const int); 
	void removeAt(int index);
	void push_back(int data);//���������� �������� � ����� ������
	void pop_back();//�������� ���������� �������� � ������
	void pop_front();
	void push_front(int);
protected:
	class Node2 : public List::Node
	{
	public:
		Node2* pNext;
		Node2* pPrev;
		Node2(int data = 0, Node2 *pNext = nullptr, Node2 *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
private:
	Node2* head;
	Node2* tail;
};