#include <iostream>
#include <cmath>
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

bool isEmpty(){
    return top == -1;
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

int evaluatePostfix(char postfix[]){
    for (int i = 0; postfix[i] != '\0'; i++){
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9'){
            push(ch - '0');
        }
        else {
            int operand1 = pop();
            int operand2 = pop();
            int result = calculate(operand2, operand1, ch);
            push(result);
        }
    }
    return pop();
}

int main(){
    char postfix[100];
    cout << "Enter postfix expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;
    return 0;
}