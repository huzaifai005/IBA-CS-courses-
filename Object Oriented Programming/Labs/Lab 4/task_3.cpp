#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include<cstdlib>

class Stack {
private:
    struct node {
        char data;
        node* next;
    };

    node* head;
    int s;

public:
    Stack() : head(nullptr), s(0) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void push(char x) {
        node* newnode = new node();
        newnode->data = x;
        newnode->next = head;
        head = newnode;
        s++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        } else {
            node* val = head;
            char a = head->data;
            head = head->next;
            delete val;
            s--;
            return a;
        }
    }

    int top() {
        if (isEmpty()) {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        } else {
            return head->data;
        }
    }

    int size() {
        return s;
    }

    ~Stack() {
        while (head != nullptr) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class BracketChecker {
public:
    bool isBalanced(const std::string& s) {
        Stack st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.isEmpty()) return false;
                char top = st.pop();
                if (!matches(top, ch)) return false;
            }
        }
        return st.isEmpty();
    }

private:
    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

class TestCaseGenerator {
public:
    std::vector<std::string> generateTestCases(int n) {
        std::vector<std::string> testCases;
        std::string brackets = "(){}[]";

        for (int i = 0; i < n; ++i) {
            int length = (i % 20) + 1;
            std::string testCase;
            std::srand(std::time(0));
            for (int j = 0; j < length; ++j) {
                testCase += brackets[std::rand() % 6];
            }
            testCases.push_back(testCase);
        }
        return testCases;
    }
};

int main() {
    
    BracketChecker checker;
    TestCaseGenerator generator;

    int n = 10;
    std::vector<std::string> testCases = generator.generateTestCases(n);

    for (const auto& test : testCases) {
        std::cout << "Sequence: " << test << " -> "
                  << (checker.isBalanced(test) ? "Balanced" : "Unbalanced")
                  << std::endl;
    }

    return 0;
}
