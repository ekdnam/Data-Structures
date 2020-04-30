#include <iostream>
# include "definestack.h"
using namespace std;
int main()
{
	Stack<int>s;
	s.push(20);
	cout << s.pop();
}
