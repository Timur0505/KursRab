#pragma once
#include <string>
#include <iostream>
#include<cmath>
#include"Stack.h"

using namespace std;

class calculation
{
private:
	class Node
	{
	public:
		enum class Type {
			undef = 0,
			plus,
			minus, 
			multiply, 
			divide, 
			raise,
			sin, 
			cos, 
			tg,
			ctg,
			ln,
			lg, 
			sqrt,
			cuber, 
			int_number,
			double_number,
			bracket,
		};

		enum class Priopity {
			undef = -1,
			operands = 10,
			brackets = 0,
			plus = 1, minus = 1,
			multiply = 2, divide = 2,
			raise = 3,
			func = 4,
		};

		Node(string data, double result, Type statement, Priopity sequence, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->result = result;
			this->next = next;
			this->prev = prev;
			this->statement = statement;
			this->sequence = sequence;
		};
		~Node() {};

		string data;
		double result;
		Node* next;
		Node* prev;
		Type statement;
		Priopity sequence;
	};

	void add_first(string newElem, double result, Node::Priopity sequence, Node::Type exp);
	void reset_list();

	Node* head;
	Node* tail;

	size_t size;

public:

	calculation();
	~calculation();

	void input();
	void check(string str);
	void push_back(string newElem, double result, Node::Priopity sequence, Node::Type exp);
	void push_front(string newElem, double result, Node::Priopity sequence, Node::Type exp);
	void print_to_console();
	void clear();
	void infixToPrefix();
	void pop_back();
	bool isEmpty();
	double count();
	string return_data();
};
