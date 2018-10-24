/*
Fractal Analytics IITK 2018

Maintain a stack which can handle the following operations:

"push k": Push k at the top of stack
"pop": Remove the topmost element from the stack
"inc e k": Add k to the bottom e elements of the stack

pop is never called on an empty stack.

Given a vector of strings where each string is an operation as
defined above, print the top element after every operation. If
the stack is empty at some point, print "EMPTY" instead.

1 <= #operations <= 1E5
1 <= k <= size of stack at the time of operation
*/
#include <bits/stdc++.h>
using namespace std;

void superStack(vector<string> ops) {
    int n = ops.size();
    vector<int> a(n), b(n);

    int k = 0;
    for (string op : ops) {
        stringstream strin(op);
        
        string optype;
        strin >> optype;
        if (optype == "push") {
            int x;
            strin >> x;
            a[k++] = x;
        }
        if (optype == "pop") {
            if (--k) b[k - 1] += b[k];
            b[k] = 0;
        }
        if (optype == "inc") {
            int x, y;
            strin >> x >> y;
            b[x - 1] += y;
        }

        if (not k) {
            cout << "EMPTY";
        }
        else {
            cout << a[k - 1] + b[k - 1];
        }
        cout << " ";
    }
}

int main() {
    vector<string> operations = {
        "push 4", "pop", "push 3", "push 5", "inc 2 1",
        "pop", "push 5", "push -1", "inc 1 5", "pop"
    };
    superStack(operations);
    return 0;
}