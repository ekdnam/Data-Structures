#include <iostream>
# define MAX 25
# define ERROR -999
using namespace std;

class Stack {
	int top;
	int stack[MAX];
public:
	Stack() {
		top = -1;
		for (int i = 0; i < 25; i++) {
			stack[i] = -1;
		}
	}
	bool empty() {
		if (top == -1) {
			return 1;
		}
		return 0;
	}
	bool full() {
		if (top == MAX - 1) {
			return 1;
		}
		return 0;
	}
	void push(int);
	int pop();
};

void Stack::push(int x) {
	if (!full()) {
		stack[++top] = x;
	}
	else {
		cout << "Stack is empty.\n";
	}
}

int Stack::pop() {
	if (!empty()) {
		top -= 1;
		return stack[top + 1];
	}
	else {
		return ERROR;
	}
}

int main()
{
	Stack s;
	s.push(5);
	cout << s.pop();
}
