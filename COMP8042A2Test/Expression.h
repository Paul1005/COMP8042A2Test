#include <iostream>
#include <string>

using namespace std;

double evalPostFix() //TODO: complete
{
	string token;
	double result;
	cin >> token;
	stack<double> operands;
	while (token[0] != '=')
	{
		if (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/' && token[0] != '^' && token[0] != '@') {
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
				result = (first + second) / 2;
				break;
			}
		}
		//cout << result;
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
	cin >> token;
	{
		result = atof(token.c_str());
		cin >> token;
	}
	return false;
}
