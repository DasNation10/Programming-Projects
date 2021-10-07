//Name: Ayush Das 
//Date: 11/16/20

#include <iostream>
using namespace std;

const int MAXITEM = 5;
template<class ItemType>

struct NodeType {
	ItemType info;
	NodeType<ItemType>* next;
};

template<class ItemType>

class Stack {
private:
	NodeType<ItemType>* topPtr; //Points to singly-linked list
public:
	Stack() { //Default constructor
		topPtr = NULL;
	};
	Stack(const Stack<ItemType>& x) { //Copy Constructor
		ItemType item;
		NodeType<ItemType>* temp = x.topPtr;

		while (temp != NULL)
		{
			item = temp->info;
			Push(item);
			temp = temp->next;
		}
	};

	void MakeEmpty() { //Makes stack empty
		while (!IsEmpty())
		{
			ItemType ele;
			Pop(ele);
		}
		topPtr = NULL;
	};

	bool IsEmpty(){ //Tests if stack is empty
		if (length() == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsFull(){ //Tests if stack is full
		if (length() == MAXITEM){
			return true;
		}
		else {
			return false;
		}
	};
	int length() { //Number of elements in stack
		if (topPtr == NULL)
		{
			return 0;
		}
		else
		{
			int len = 1;
			NodeType<ItemType>* temp = topPtr;

			while (temp != topPtr)
			{
				len++;
				temp = temp->next;
			}
			return len;
		}
	};
	void Print() { //Displays all elements in stack
		if (IsEmpty())
		{
			return;
		}
		else
		{
			NodeType<ItemType>* temp = topPtr;
			
			while (temp != NULL)
			{
				cout << temp->info << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	};

	void Push(ItemType x) { //Inserts x onto the stack 
		if (IsFull())
		{
			cout << "The stack is full" << endl;
		}
		else
		{
			NodeType<ItemType>* new_node = new NodeType<ItemType>();
			new_node->info = x;
			new_node->next = NULL;
			
			if (IsEmpty())
			{
				topPtr = new_node;
			}
			else 
			{
				topPtr->next = new_node;
				topPtr = new_node;
			}
		}
	};
	void Pop(ItemType& x) { //Removes the top element from stack
		if (IsEmpty())
		{
			cout << "The stack is empty" << endl;
		}
		else
		{
			x = topPtr->info;
			NodeType<ItemType>* temp = topPtr;
			topPtr = topPtr->next;
			delete temp;
		}
	};

	~Stack() { //Destructor
		MakeEmpty();
	};
};
//Driver Code
int main()
{
Stack <int> IntStack;
int x;
	IntStack.Pop(x);
	IntStack.Push(11);
	IntStack.Push(22);
	cout << "int length 1 = " << IntStack.length() << endl;
	IntStack.Pop(x);
	IntStack.Push(33);
	cout << "int length 2 = " << IntStack.length() << endl;
	cout << "The int stack contains: " << endl;
	IntStack.Print();
	IntStack.Push(44);
	IntStack.Push(55);
	IntStack.Push(66);
	if (IntStack.IsFull() == false)
		cout << "The int stack is not full !" << endl;
	else
		cout << "The int stack if full !" << endl;
	Stack <int> IntStack2(IntStack);
	cout << "The int stack2 contains: " << endl;
	IntStack2.Print();
	IntStack2.MakeEmpty();
	cout << "The int stack3 contains: " << endl;
	IntStack2.Print();

	Stack <float> FloatStack;
	float y;
	FloatStack.Pop(y);
	FloatStack.Push(7.1);
	cout << "float length 1 = " << FloatStack.length() << endl;
	FloatStack.Push(2.3);
	FloatStack.Push(3.1);
	cout << "float length 2 = " << FloatStack.length() << endl;
	FloatStack.Pop(y);
	cout << "The float stack contains: " << endl;
	FloatStack.Print();
	Stack <float> FloatStack2 = FloatStack;
	cout << "The float stack 2 contains: " << endl;
	FloatStack2.Print();
	FloatStack.MakeEmpty();
	cout << "The float stack 3 contains: " << endl;
	FloatStack2.Print();
}