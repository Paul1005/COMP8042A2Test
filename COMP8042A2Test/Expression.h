#include <iostream>
#include <string>

using namespace std;

bool isValidSymbol(char symbol) {
	if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '^' && symbol != '@') {
		return false;
	}
	else {
		return true;
	}
}

double evalPostFix() //TODO: complete
{
	string token;
	double result;
	cin >> token;
	stack<double> operands;
	while (token[0] != '=')
	{
		if (isValidSymbol(token[0])) {
			result = atof(token.c_str());
		}
		else {
			double second = operands.top();
			operands.pop();
			double first = operands.top();
			operands.pop();
			switch (token[0]) {
			case '+':
				result = first + second;
				break;
			case '-':
				result = first - second;
				break;
			case '*':
				result = first * second;
				break;
			case '/':
				result = first / second;
				break;
			case '^':
				result = pow(first, second);
				break;
			case '@':
				double third = operands.top();
				operands.pop();
				second = operands.top();
				operands.pop();
				first = operands.top();
				operands.pop();
				result = (first + second + third) / 3;
				break;
			}
		}
		operands.push(result);

		cin >> token;
	}
	return operands.top();
}

bool isValidExpression(int expressionType) {
	// expressionType==0 means prefix;
	// expressionType==1 means infix;
	// expressionType==2 means postfix'
	string token;
	bool result;
	bool wasSymbol = true;
	cin >> token;
	while (token[0] != '=') {
		result = atof(token.c_str());

		if (result) {
			if (expressionType == 0) {

			}
			else if (expressionType == 1) {
				if (wasSymbol) {
					wasSymbol = false;
				}
				else if (!wasSymbol) {
					return false;
				}
			}
			else if (expressionType == 2) {

			}
		}
		else if (!result) {
			if (isValidSymbol(token[0])) {
				if (expressionType == 0) {

				}
				else if (expressionType == 1) {
					if (wasSymbol) {
						return false;
					}
					else if (!wasSymbol) {
						wasSymbol = true;
					}
				}
				else if (expressionType == 2) {

				}
			}
			else {
				return false;
			}
		}
		cin >> token;
	}
	return true;
}