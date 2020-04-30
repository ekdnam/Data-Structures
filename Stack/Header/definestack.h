#pragma once
#ifndef _DEFINESTACK_H
#define _DEFINESTACK_H
# define MAX 25
template<typename T>
class Stack {
	T stack[MAX];
	int top;
public:
	Stack() {
		top = -1;
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
	T pop() {
		if (!empty()) {
			top -= 1;
			return stack[top + 1];
		}
	}
	void push(T x) {
		if (!full()) {
			stack[++top] = x;
		}
	}
};

#endif // !_DEFINESTACK_H
