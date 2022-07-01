#include <iostream>
#include <locale>
#include <string>
#include "windows.h"

using namespace std;

template <typename T>
class Stack {
public:
    Stack() {
        end = nullptr;
        Size = 0;
    }
    void push(const T& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->pNext = end;
        end = newNode;
        Size++;
    }
    bool empty() const {
        return end == nullptr;
    }
    T top() const {
        if (empty()) {
            return NULL;
        }
        return end->data;
    }
    T pop() {
        if (empty()) {
            return NULL;
        }
        Node* temp = end;
        T x = temp->data;
        end = temp->pNext;
        delete temp;
        Size--;
        return x;
    }
    int size() {
        return Size;
    }
    void print() {
        Stack<T> temp;
        while (!empty()) {
            temp.push(pop());
        }
        while (!temp.empty()) {
            T x = temp.pop();
            cout << x << ' ';
            push(x);
        }
    }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
private:
    int Size;
    struct Node {
        T data;
        Node* pNext;
    };
    Node* end;
};

string abc = "abcdefghigklmnopqrstuvwxyz";
void task1() {
    Stack<int> main;
    for (int i = 1; i != 10; i++) {
        main.push(i);
    }
    Stack<int> task;
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    Stack<int> temp;
    task.push(main.pop());
    while (!main.empty()) {
        temp.push(main.pop());
    }
    int first = temp.pop();
    while (!temp.empty()) {
        task.push(temp.pop());
    }
    task.push(first);
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task2() {
    Stack<char> main;
    Stack<char> temp;
    for (int i = 0; i != 11; i++) {
        main.push(abc[i]);
    }
    int s = main.size();
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    int counter=0;
    while (counter != s / 2) {
        temp.push(main.pop());
        counter++;
    }
    main.push('*');
    while (!temp.empty()) {
        main.push(temp.pop());
    }
    cout << "Кінцевий стек: ";
    main.print();
}
void task3() {
    Stack<int> main;
    Stack<int> temp;
    Stack<int> task;
    int min = 0;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() <= min) min = temp.top();
    }
    while (!temp.empty()) {
        task.push(temp.pop());
        if (task.top() == min) task.pop();
    }
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task4() {
    string palindrom;
    bool isEqual;
    Stack<char> word;
    cout << "Введіть слово: ";
    cin >> palindrom;
    for (int i = 0; i != palindrom.length(); i++) {
        word.push(palindrom[i]);
    }
    for (int i = 0; i != palindrom.length(); i++) {
        if (word.pop() != palindrom[i]) {
            isEqual = false;
            break;
        }
        else {
            isEqual = true;
        }
    }
    if (isEqual) {
        cout << "Слово є паліндромом";
    }
    else {
        cout << "Слово не є паліндромом";
    }
}
void task5() {
    string str;
    Stack<char> word;
    Stack<char> result;
    cout << "Введіть повідомлення для шифрування: ";
    cin >> str;
    for (int i = 0; i != str.length(); i++) {
        word.push(str[i]);
    }
    while (!word.empty()) {
        for (int i = 0; i != abc.length(); i++) {
            if (word.top() == abc[i]) {
                if (i + 3 >= abc.length()) {
                    i = abc.length() - i;
                 }
                 result.push(abc[i+3]);
                 word.pop();
                 break;
            }
        }
    }
    cout << "Зашифроване повідомлення: ";
    result.print();
}
void task6() {
    Stack<int> main;
    Stack<int> task;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        task.push(main.pop());
    }
    cout << "Кінцевий стек: ";
    task.print();
}
void task7() {
    Stack<int> main;
    Stack<int> temp;
    Stack<int> task;
    int max = 0;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() >= max) max = temp.top();
    }
    while (!temp.empty()) {
        task.push(temp.pop());
        if (task.top() == max) task.pop();
    }
    cout << "Максимальний елемент: " << max << endl;
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task8() {
    Stack<int> main;
    Stack<int> temp;
    Stack<int> task;
    int min = 0;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() <= min) min = temp.top();
    }
    while (!temp.empty()) {
        task.push(temp.pop());
        if (task.top() == min) { task.pop(); task.push(0); }
    }
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task9() {
    Stack<int> main;
    Stack<int> temp;
    int counter=0;
    for (int i = 1; i != 12; i++) {
        main.push(i);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    int s = main.size();
    if (main.size() % 2 == 0) {
        while (counter != s / 2) {
            temp.push(main.pop());
            counter++;
        }
        main.pop();
        temp.pop();
        while (!temp.empty()) {
            main.push(temp.pop());
        }
    }
    else {
        while (counter != s / 2) {
            temp.push(main.pop());
            counter++;
        }
        main.pop();
        //temp.pop();
        while (!temp.empty()) {
            main.push(temp.pop());
        }
    }
    cout << "Кінцевий стек: ";
    main.print();
}
void task10() {
    Stack<int> main;
    Stack<int> temp;
    Stack<int> task;
    int max = 0;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() >= max) max = temp.top();
    }
    while (!temp.empty()) {
        task.push(temp.pop());
        if (task.top() == max) task.push(0);
    }
    cout << "Максимальний елемент: " << max << endl;
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task11() {
    Stack<int> main;
    Stack<int> temp;
    for (int i = 0; i != 10; i++) {
        main.push((int)rand() % 20 - 10);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    int del = main.top();
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() == del) temp.pop();
    }
    while (!temp.empty()) {
        main.push(temp.pop());
    }
    cout << "Кінцевий стек: ";
    main.print();

}
void task12() {
    Stack<int> main;
    Stack<int> temp;
    for (int i = 1; i != 25; i++) {
        main.push(i);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    int counter = 1;
    while (!main.empty()) {
        temp.push(main.pop());
        counter++;
        if (counter % 2 == 0) temp.pop();
    }
    while (!temp.empty()) {
        main.push(temp.pop());
    }
    cout << "Кінцевий стек: ";
    main.print();
}
void task13() {
    Stack<int> main;
    Stack<int> temp;
    Stack<int> task;
    int min = 0;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 201 - 100);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
        if (temp.top() <= min) min = temp.top();
    }
    while (!temp.empty()) {
        task.push(temp.pop());
        if (task.top() == min) task.push(0);
    }
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Кінцевий стек: ";
    task.print();
    cout << endl;
}
void task14() {
    Stack<int> main;
    Stack<int> temp;
    for (int i = 0; i != 15; i++) {
        main.push((int)rand() % 14);
    }
    cout << "Початковий стек: ";
    main.print();
    cout << endl;
    while (!main.empty()) {
        temp.push(main.pop());
    }
    int del = temp.top();
    while (!temp.empty()) {
        main.push(temp.pop());
        if (main.top() == del) main.pop();
    }
    cout << "Кінцевий стек: ";
    main.print();

}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    int choise;
    cout << "Введіть номер завдання: ";
    cin >> choise;
    switch (choise) {
    case 1: {task1(); break; }
    case 2: {task2(); break; }
    case 3: {task3(); break; }
    case 4: {task4(); break; }
    case 5: {task5(); break; }
    case 6: {task6(); break; }
    case 7: {task7(); break; }
    case 8: {task8(); break; }
    case 9: {task9(); break; }
    case 10: {task10(); break; }
    case 11: {task11(); break; }
    case 12: {task12(); break; }
    case 13: {task13(); break; }
    case 14: {task14(); break; }
    }
}

