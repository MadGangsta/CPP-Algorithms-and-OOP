#pragma once
class List
{
public:
	List();
	~List();
	void clear();// очистить список
	int GetSize() { return Size; }// получить количество елементов в списке
	int& operator[](const int index);// перегруженный оператор [] 
	void insert(int data, int index);//добавление элемента в список по указанному индексу
	void removeAt(int index);//удаление элемента в списке по указанному индексу
	void pop_front();//удаление последнего элемента в списке
	void push_front(int data);//добавление элемента в начало списка
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
	void push_back(int data);//добавление элемента в конец списка
	void pop_back();//удаление последнего элемента в списке
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