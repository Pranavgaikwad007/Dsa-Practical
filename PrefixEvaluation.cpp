#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int stackArr[100];
int top = -1;

void push(int value){
    top++;
    stackArr[top] = value;
}

int pop(){
    int value = stackArr[top];
    top--;
    return value;
}

int calculate(int a, int b, char op){
    switch (op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePrefix(char prefix[]){
    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--){
        char ch = prefix[i];

        if (ch >= '0' && ch <= '9'){
            push(ch - '0');
        }
        else {
            int operand1 = pop();
            int operand2 = pop();
            int result = calculate(operand1, operand2, ch);
            push(result);
        }
    }
    return pop();
}

int main(){
    char prefix[100];
    cout << "Enter prefix expression: ";
    cin >> prefix;
    int result = evaluatePrefix(prefix);
    cout << "Result = " << result << endl;
    return 0;
}
