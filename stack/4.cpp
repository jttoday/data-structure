#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <ctype.h>
#include <cmath>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

int isOp(char ch)
{
	switch (ch) {
		case '*':
		case '/':
		case '+':
		case '-':
		case '^':
		case '(':
		case ')':
			return 1;
		default:
			return 0;
	}
}


double simpleCal(double v1 , char op , double v2)
{
	switch (op) {
		case '+': return v1 + v2;  
		case '-': return v1 - v2;
		case '*': return v1 * v2;
		case '/': if (v2 ==0) throw runtime_error( "ERROR:Divided by zero!");
					  return v1 / v2;
		case '^': return pow(v1,v2);
		default:  throw runtime_error ( " Bad Expresion !");

	}
}

double cal(const string &exp)
{
	stack<double> numStack;
	
	int i=0;
	while (i < exp.size()) {
		if (isblank(exp[i])) {++i; continue;}

		if (isdigit(exp[i])) {
			string ts;
			ts += exp[i++];
			while (i < exp.size() &&
					(isdigit(exp[i])|| exp[i] == '.')) ts+= exp[i];
			double val = atof(ts.c_str());
			numStack.push(val);
		} else if (isOp(exp[i])){
			char op = exp[i++];
			double val2 = numStack.top();
			numStack.pop();
			double val1 = numStack.top();
			numStack.pop();
			numStack.push(simpleCal(val1 , op , val2));
		}else throw runtime_error("Bad Expression!  !!");	
	}
	return numStack.top();
}

int main()
try {
	string exp;
	getline(cin, exp);
	cout << cal(exp) <<endl;
	return 0;
} catch(runtime_error & e){
	cerr << e.what() << endl;
}
		

