//Final Project
//Grace Pasternick

//Infix: (16 + 2) * 5 - 28 / 4
//Postfix: 16 2 + 5 * 28 4 / -
//Create Function to convert infix expression to postifx
//      using Shunting Yard algorithm
//Create Function that constructs the binary tree from postfix
//      use stack to create nodes and combine using operator nodes
//Evaulate the binary tree  from a function expression

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//from lecture notes
struct Node {
        string data;
        Node* left;
        Node* right;

        Node(string val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

int precedence(char c);
string infixToPostfix(string s);
bool isOperator(char c);
Node* constructTree(string postfix);
void printTree(Node* root, int space, int height);
int evaluate(Node* root);

int main(){

    string exp = "( ( 1 + 2 ) * ( 3 + 4 ) ) - 5";
    string postfix = infixToPostfix(exp);
    cout << "Infix: " << exp << endl;
    cout << endl;
    cout << "Postfix: " << postfix << endl;
    cout << endl;
    
    Node* r = constructTree(postfix);
    
    cout << "Tree Structure:" << endl;
    printTree(r, 0, 5);
    cout << endl;

    int eval = evaluate(r);
    cout << "The value of the expression is: " << eval << endl;
    
    return 0;
}

//Function to establish operator precedence
//Logic from project slides
int precedence(char c){
    //highest precedence
    if (c == '*' || c == '/'){
        return 2;
    }
    //lowest precedence
    else if (c == '+' || c == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

//from project slides
string infixToPostfix(string s){
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        //If scanned character is an operand, add it to output string
        if (isdigit(c)) {
            string num = "";

            while (i < s.length() && isdigit(s[i])) {
                num += s[i++];
        }

        i--; // back up since the for loop will increment again
        result += num + ' '; // space acts to separate terms
        }

        //If the scanned character is an '(', push it to the stack
        else if (c == '('){
            st.push('(');
        }
        //If the scanned character is an ')', pop and output string from the stack 
        //until an '(' is encountered
        else if (c == ')'){
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.pop();
        }
        //skip if a space
        else if (c == ' '){
            continue;
        }
        //If an operator is scanned
        else{
            while(!st.empty() && precedence(c) <= precedence(st.top())){
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    //Pop all the remaining elements from the stack
    while(!st.empty()){
        result += st.top();
        result += ' ';
        st.pop();
    }

    return result;
}

bool isOperator(char c){
    //testing if character is operator
    if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
        return true;
    }
    else{
        return false;
    }
}

//from project slides
Node* constructTree(string postfix){
    stack<Node*> st;
    Node* t, * t1, * t2;

    //Transverse through every character of input postfix
    for(int i = 0; i < postfix.length(); i++){
        //use to skip spaces
        if(postfix[i] == ' '){
            continue;
        }

        //if an operand, push into stack
        if(!isOperator(postfix[i])){
            // collect full multi-digit number
            string num = "";

            while(i < postfix.length() && postfix[i] != ' '){
                num += postfix[i++];
            }

            i--; // back up since for loop will increment
            t = new Node(num);  // now stores "16" not just "1"
            st.push(t);
        }
        //if an operator
        else{
            t = new Node(string(1, postfix[i])); //converts char to string

            //Pop two top nodes
            t1 = st.top(); //store top
            st.pop(); //remove top
            t2 = st.top();
            st.pop();

            //make them children
            t->right = t1;
            t->left = t2;

            //Add subexpression to stack
            st.push(t);
        }
    }

    //root of expression tree
    t = st.top();
    st.pop();

    return t;
}

//taken from lecture notes
void printTree(Node* root, int space, int height) {
    if (root == nullptr) return;
    space += height;
    printTree(root->right, space, height);
    //cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space, height);
}

int evaluate(Node* root){
    stack<Node*> s1, s2; //need to stacks to search and store
    
    s1.push(root); //start stack at top of tree (first operator)

    //convert tree into postfix to evaluate through stack
    while(!s1.empty()){ //while s1 is not empty
        //pop out parent node
        Node* node = s1.top();
        s1.pop();

        //push parent node into s2 so that root is at the bottom of the stack
        s2.push(node);

        //if left child, put in s1
        if (node->left){
            s1.push(node->left);
        }
        //if right child, put in s1
        if(node->right){
            s1.push(node->right);
        }
    }

    //create stack to hold integers
    stack<int> stack;

    //perform calculations
    while(!s2.empty()){ //while s2 is not empty
        //pop out parent node
        Node* new_node = s2.top();
        s2.pop();

        //check is data in node is an operator
        bool x = isOperator(new_node->data[0]);

        //if node is not an operator but rather a number
        if (x == false){
            int num = stoi(new_node->data); //convert data from string to int
            stack.push(num); //put num in stack
        }
        //if node is an operator, perform math
        else{
            //pop right side (pushed in last, popped out first)
            int val1 = stack.top();
            stack.pop();

            //pop left side (pushed in first, popped out last)
            int val2 = stack.top();
            stack.pop();

            //evaluate based on operator, push result onto stack to be used by next operator
            if (new_node->data == "+"){
                stack.push(val1+val2);
            }
            else if (new_node->data == "-"){
                stack.push(val2-val1);
            }
            else if (new_node->data == "*"){
                stack.push(val1*val2);
            }
            else if (new_node->data == "/"){
                stack.push(val2/val1);
            }
        }
    }
        return stack.top();
}