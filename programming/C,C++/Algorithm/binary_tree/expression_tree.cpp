// Constructing expression tree from postfix representation
	// 3 4 + 6 -

/*
	Expression tree is a binary tree in which each internal node corresponds to operator and each leaf node corresponds to operand operand so for example expression tree for 3 + (5(5+9)*2)
    Inorder traversal of expression tree produces infix version of given postfix expression (same with preorder traversal it gives prefix expression)
*/

/* Algorithm
Let t be the expression tree

if t is not null then
	if t->value is operand then
		return t.value
	
	** t->value is then operator	
	A = solve(t->left)
	B = solve(t->right)

	return calculate(A, B, t.value)
*/

/* Construction of an expression tree 
 Now for constructing expression tree we use stack. We loop through input expression and do following for every character.
	If character is operand push that into stack
	If character is operator then pop two values from stack and make them its child and push current node again.
*/


#include <bits/stdc++.h>
using namespace std;

// An expression tree node
struct et
{
	char value;
	struct et *left; 
	struct et *right;
};

// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;

	return false;
}

// Utility function to do inorder traversal
void inorder(struct et *t) {
	if (t) {
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

// A utility function to create a new node
struct et* newNode(int v)
{
	struct et *temp = new et;
	temp->left = temp->right = NULL;
	temp->val = v;

	return temp;
}

struct et* constructTree(char postfix[])
{
	stack<struct et*> st;
	struct et *t, *t1, *t2;

	// Traverse through every character of input expression
	for (int i=0; i<strlen(postfix); i++)
	{
		// If operand, simply push into stack
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			st.push(t);
		} 
		// handle brackets also may be
		else // operator
		{
			t = newNode(postfix[i]);

			// Pop two top nodes	
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();

			// make them children
			t->right = t1;
			t->left = t2;

			// Add this subexpression to stack
			st.push(t);
		}
	}

	// only element will be root of expression tree
	t = st.top();
	st.pop();

	return t;
}

/*
	3 4 * 6 -
										stack
	char 3								empty
	new node 3       
	push node							3 
	char 4								3
	new node 4							3
	push node 							4 3
	char *								4 3
	new node *							4 3
	pop node 							3              
	add node 3 to right sub tree						 
										 *
									  	  \
											4	
	pop node 			empty
	add two nodes to left sub tree 
										 *
									   /   \
									  3		4	
    push node           				*
	char 6								*
	new node 6          				*
	push node 							6 *	
	char -
	new node -          				6 *
	pop node							*
	add node * to right sub tree						 
									 -
									   \
										 *
									  	  \
											4	
	pop node							empty
	add node to right sub tree						 
									 -
								   /    \
								  6	     *
									   /   \
									  3	    4	
	
	push node 							- 
*/
