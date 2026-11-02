#include <iostream>
#include <cstring>
using namespace std;

char stackArr[100];
int top = -1;

void push(char ch){
    top++;
    stackArr[top] = ch;
}

char pop(){
    char ch = stackArr[top];
    top--;
    return ch;
}

bool isEmpty(){
    return top == -1;
}

int precedence(char ch){
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/' || ch == '%') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

bool isOperand(char ch){
    return ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'));
}

void infixToPostfix(char infix[]){
    char postfix[100];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++){
        char ch = infix[i];

        if (isOperand(ch)){
            postfix[j++] = ch;
        }
        else if (ch == '('){
            push(ch);
        }
        else if (ch == ')'){
            while (!isEmpty() && stackArr[top] != '('){
                postfix[j++] = pop();
            }
            if (!isEmpty()) pop();
        }
        else {
            while (!isEmpty() &&
                   stackArr[top] != '(' &&
                   precedence(stackArr[top]) >= precedence(ch)){
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

int main(){
    char infix[100];
    cout << "Enter infix expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}