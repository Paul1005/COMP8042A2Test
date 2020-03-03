#include <iostream>
#include <string>

using namespace std;

/*
Checks to see if the symbol is a valid operation symbol, returns true if yes, false if no.
*/
bool isValidSymbol(char symbol) {
	if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '^' && symbol != '@') {
		return false;
	}
	else {
		return true;
	}
}

double evalPostFix()
{
	string token;
	double result;
	cin >> token;
	stack<double> numbers; // stack of operands
	while (token[0] != '=')
	{
		if (!isValidSymbol(token[0])) { // if symbol is an operation
			result = atof(token.c_str());
		}
		else { // if symbol is an operand 
			double second = numbers.top();
			numbers.pop();
			double first = numbers.top();
			numbers.pop();
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
				double third = numbers.top();
				result = (first + second + third) / 3;
				break;
			}
		}
		numbers.push(result);

		cin >> token;
	}
	return numbers.top();
}

bool isValidExpression(int expressionType) {
	// expressionType==0 means prefix;
	// expressionType==1 means infix;
	// expressionType==2 means postfix'
	string token;
	bool result;
	bool wasSymbol = true;
	cin >> token;
	int numOfNumbers = 0;
	int numOfOperations = 0;
	stack<double> operations;
	while (token[0] != '=') {
		result = atof(token.c_str());
		if (result) { // is a number/operand
			if (expressionType == 0) { // is prefix expression
				if (numOfOperations == 0) {
					return false;
				}
				else {
					if (numOfNumbers == 0) {
						numOfNumbers++;
					}
					else if (numOfNumbers == 1) {
						if (operations.top() == '@') {
							numOfNumbers++;
						}
						else {
							numOfOperations--;
							operations.pop();
						}
					}
					else if (numOfNumbers == 2) {
						if (operations.top() == '@') {
							numOfNumbers--;
						}
						operations.pop();
						numOfOperations--;
					}
				}
			}
			else if (expressionType == 1) { // is infix expression
				if (wasSymbol) {
					wasSymbol = false;
				}
				else if (!wasSymbol) {
					return false;
				}
			}
			else if (expressionType == 2) { // is postfix expression
				if (numOfNumbers == 0) {
					numOfNumbers++;
				}
				else if (numOfNumbers == 1) {
					numOfNumbers++;
				}
				else if (numOfNumbers == 2) {
					numOfNumbers++;
				}
				else if (numOfNumbers == 3) {
					return false;
				}
			}
		}
		else if (!result) { // is an operation
			if (isValidSymbol(token[0])) {
				if (expressionType == 0) { // is prefix expression
					operations.push(token[0]);
					numOfOperations++;
				}
				else if (expressionType == 1) { // is infix expression
					if (wasSymbol) {
						return false;
					}
					else if (!wasSymbol) {
						wasSymbol = true;
					}
				}
				else if (expressionType == 2) { // is postfix expression
					if (numOfNumbers == 1 || numOfNumbers == 0) {
						return false;
					}
					else {
						numOfNumbers--;
						if (token[0] == '&') {
							if (numOfNumbers == 2) {
								return false;
							}
							else {
								numOfNumbers--;
							}
						}
					}
				}
			}
			else {
				return false;
			}
		}
		cin >> token;
	}
	if (expressionType == 2 && numOfNumbers != 1) {
		return false;
	}
	else if (expressionType == 0 && (numOfNumbers != 1 || numOfOperations != 0)) {
		return false;
	}
	return true;
}