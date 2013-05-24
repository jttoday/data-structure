#include <iostream>
#include <string>
#include <stack>

using namespace std;

const char BEGIN = 'B';

int isOp(char ch)
{
	switch(ch) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
		return 1;
	default:
		return 0;
	}
}

int CMP(char op1 , char op2)
{
	switch (op1) {
	case BEGIN:case '(':
		return 0;
	case '+':case '-':
		if (op2 == ')' || op2 == '+' || op2 == '-' ) return 1;
		else return 0;
	case '*':case '/':
		if (op2 == '^' || op2 == '(') return 0;
		else return 1;
	case '^':
		return 1;
	}
}

void toSuffix(const string &exp)
{
	stack<char> opStack;
	opStack.push(BEGIN);

	int i=0;
	while (i < exp.size()) {
		while (i<exp.size() && !isOp(exp[i])){
			cout << exp[i++];
		}
		cout << ' ';
		
		char op2 = exp[i];
		char op1 = opStack.top();
		while (CMP(op1 , op2)) {
			cout << op1 ;
			opStack.pop();
			op1 = opStack.top();
		}
		if (op1 == '(' && op2 == ')') {
			opStack.pop();
			++i;
			continue;
		}
		opStack.push(op2);
		++i;
	}
	while (opStack.top() != BEGIN) {
		cout << opStack.top() ;
		opStack.pop();
	}
	cout << endl;
}

int main(int argc ,char * argv[])
{
	string exp;
	getline(cin,exp);
	toSuffix(exp);
	return 0;
}
