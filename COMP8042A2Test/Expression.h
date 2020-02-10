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
	int numOfOperands = 0;
	int numOfOperations = 0;
	while (token[0] != '=') {
		result = atof(token.c_str());
		if (result) { // is a number/operand
			if (expressionType == 0) {
				if (numOfOperations == 0) {
					return false;
				}
				else {
					if (numOfOperands == 0) {
						numOfOperands++;
					}
					else if (numOfOperands == 1) {
						numOfOperations--;
					}
					else if (numOfOperands == 2) {
						numOfOperations = numOfOperations - 2;
					}

				}
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
				if (numOfOperands == 0) {
					numOfOperands++;
				}
				else if (numOfOperands == 1) {
					numOfOperands++;
				}
				else if (numOfOperands == 2) {
					numOfOperands++;
				}
				else if (numOfOperands == 3) {
					return false;
				}

			}
		}
		else if (!result) { // is an operation
			if (isValidSymbol(token[0])) {
				if (expressionType == 0) {
					numOfOperations++;
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
					if (numOfOperands == 1) {
						return false;
					}
					else if (numOfOperands == 2) {
						numOfOperands--;
					}
					else if (numOfOperands == 3) {
						if (token[0] == '&') {
							numOfOperands = numOfOperands - 2;
						}
						else {
							return false;
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
	if (expressionType == 2 && numOfOperands != 1) {
		return false;
	}
	else if (expressionType == 0 && (numOfOperands != 1 || numOfOperations != 0)) {
		return false;
	}
	return true;
}