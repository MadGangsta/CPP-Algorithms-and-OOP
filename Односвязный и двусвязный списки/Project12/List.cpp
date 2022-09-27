#include "List.h"
List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

void List::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}


int& List::operator[](const int index)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext; // след элем. куррент будем иметь адрес на который ссылается предыдущий куррент
		//(*current).pNext;
		counter++;
	}
}

void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(int data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* newNode = new Node(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

List2::List2()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

List2::~List2()
{
	clear();
}

void List2::clear()
{
	while (Size)
	{
		pop_front();
	}
}


void List2::insert(int data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else if (index == Size || index > Size)
	{
		push_back(data);
	}
	else if (index <= Size / 2)
	{
		Node2* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node2* newNode = new Node2(data, previous->pNext, previous);
		previous->pNext = newNode;
		Node2* next = newNode->pNext;
		next->pPrev = newNode;
		Size++;
	}
	else if (index > Size / 2)
	{
		Node2* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node2* newNode = new Node2(data, next, next->pPrev);
		next->pPrev = newNode;
		Node2* previous = newNode->pPrev;
		previous->pNext = newNode;
		Size++;
	}
}
void List2::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else if (index == Size - 1 || index > Size)
	{
		pop_back();
	}
	else if (index <= Size / 2)
	{
		Node2* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node2* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node2* next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;
		Size--;
	}
	else if (index > Size / 2)
	{
		Node2* next = this->tail;
		for (int i = Size - 1; index+1 < i; i--)
		{
			next = next->pPrev;
		}
		Node2* toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node2* previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;
		Size--;
	}
}

int& List2::operator[](const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node2* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node2* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pPrev;
			counter--;
		}
	}
}

void List2::push_front(int data)
{
	if (Size > 1)
	{
		Node2* temp = head;
		head = new Node2(data, head);
		temp->pPrev = head;
	}
	else if (Size == 1)
	{
		head = new Node2(data, head);
		tail->pPrev = this->head;
	}
	else
	{
		head = tail = new Node2(data, head, tail);
	}
	Size++;
}

void List2::push_back(int data)
{
	if (Size > 1)
	{
		Node2* temp = tail;
		tail = new Node2(data, nullptr, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node2(data, nullptr, tail);
		head->pNext = this->tail;
	}
	else
	{
		head = tail = new Node2(data, head, tail);
	}
	Size++;
}

void List2::pop_back()
{
	if (Size > 1)
	{
		Node2* temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node2* temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}
	Size--;
}

void List2::pop_front()
{
	Node2 *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
