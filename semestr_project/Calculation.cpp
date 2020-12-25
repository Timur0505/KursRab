#include "Calculation.h"

double pi = 3.14159265358979323846;
double e = 2.71828182845904523536;

void calculation::reset_list()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

calculation::calculation()
{
	reset_list();
}

calculation::~calculation() {
	if (head) {
		while (head->next) {
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void calculation::add_first(string newElem, double result, Node::Priopity sequence, Node::Type exp)
{
	head = new Node(newElem, result, exp, sequence);
	tail = head;
}

bool calculation::isEmpty()
{
	return (head == nullptr);
}

void calculation::push_back(string newElem, double result, Node::Priopity sequence = Node::Priopity::undef, Node::Type exp = Node::Type::undef) 
{
	if (size == 0) {
		add_first(newElem, result, sequence, exp);
	}
	else {
		Node* temp = new Node(newElem, result, exp, sequence);
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void calculation::push_front(string newElem, double result, Node::Priopity sequence, Node::Type exp) 
{
	if (size == 0) {
		add_first(newElem, result, sequence, exp);
	}
	else {
		Node* temp = new Node(newElem, result, exp, sequence);
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	size++;
}


void calculation::pop_back() 
{
	if (size == 0) {
		throw out_of_range("Error");
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* cur = tail->prev;
		cur->next = nullptr;
		delete tail;
		tail = cur;
		size--;
	}
}

void calculation::input() { 
	bool flag = true;
	string infix;
	int bracket = 0;

	if (!head) {
		cin >> infix;
		if (infix[0] == '(') {
			tail->statement = static_cast<Node::Type>(16);
			tail->sequence = static_cast<Node::Priopity>(0);
			bracket++;
		}
		if (infix[infix.length() - 1] == ';') {
			flag = false;
			infix.erase(infix.length() - 1, 1);
		}
		push_back(infix, 0, Node::Priopity::undef, Node::Type::undef);
		check(infix);
		if (tail->statement == static_cast<Node::Type>(0)) {
			cout << endl << "Error" << endl;
			flag = false;
			return;
		}
	}

	while (flag) {
		cin >> infix;
		if (infix[infix.length() - 1] == ';') {
			flag = false;
			infix.erase(infix.length() - 1, 1);
		}
		if (infix[0] == '(') { bracket++;}
		if (infix[0] == ')') { bracket--;}
		push_back(infix, 0, Node::Priopity::undef, Node::Type::undef);
		check(infix);
		if (tail->statement == static_cast<Node::Type>(0)) {
			cout << endl << "Error" << endl;
			return;
		}
	}
	if (bracket != 0) {
		cout << "Error" << endl;
		return;
	}
}

void calculation::check(string str) {
	if (str.length() == 1) { 
		if (str == "+") { 
			tail->statement = static_cast<Node::Type>(1); 
			tail->sequence = static_cast<Node::Priopity>(1); 
		
		}
		else if (str == "-") { 
			tail->statement = static_cast<Node::Type>(2); 
			tail->sequence = static_cast<Node::Priopity>(1); 
			
		}
		else if (str == "*") { 
			tail->statement = static_cast<Node::Type>(3); 
			tail->sequence = static_cast<Node::Priopity>(2); 

		}
		else if (str == "/") { 
			tail->statement = static_cast<Node::Type>(4); 
			tail->sequence = static_cast<Node::Priopity>(2); 
		
		}
		else if (str == "^") { 
			tail->statement = static_cast<Node::Type>(5); 
			tail->sequence = static_cast<Node::Priopity>(3); 
		
		}
		else if (str == "(") {
			tail->statement = static_cast<Node::Type>(16);
			tail->sequence = static_cast<Node::Priopity>(0);
		}
		else if (str == ")") {
			tail->statement = static_cast<Node::Type>(16);
			tail->sequence = static_cast<Node::Priopity>(0);
		}
		else {
			tail->statement = static_cast<Node::Type>(14);
			tail->sequence = static_cast<Node::Priopity>(10);
			tail->result = (double)(stoi(tail->data));
		}
	}
	else if ((str[0] == 'p') && (str[1] == 'i')) { 
		tail->statement = static_cast<Node::Type>(15); 
		tail->sequence = static_cast<Node::Priopity>(10); 
		tail->result = pi;
	}
	else if ((str[0] == 'e') && (str[1] == 'p') && (str[2] == 's')) { 
		tail->statement = static_cast<Node::Type>(15); 
		tail->sequence = static_cast<Node::Priopity>(10); 
		tail->result = e;
	}
	else if ((str[0] == 's') && (str[1] == 'i') && (str[2] == 'n')) { 
		tail->statement = static_cast<Node::Type>(6); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 'c') && (str[1] == 'o') && (str[2] == 's')) { 
		tail->statement = static_cast<Node::Type>(7); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 't') && (str[1] == 'g')) { 
		tail->statement = static_cast<Node::Type>(8); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 'c') && (str[1] == 't') && (str[2] == 'g')) { 
		tail->statement = static_cast<Node::Type>(9); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 'l') && (str[1] == 'n')) { 
		tail->statement = static_cast<Node::Type>(10); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 'l') && (str[1] == 'g')) { 
		tail->statement = static_cast<Node::Type>(11); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 's') && (str[1] == 'q') && (str[2] == 'r') && (str[3] == 't')) { 
		tail->statement = static_cast<Node::Type>(12); 
		tail->sequence = static_cast<Node::Priopity>(4); 
	}
	else if ((str[0] == 'c') && (str[1] == 'u') && (str[2] == 'b') && (str[3] == 'e') && (str[4] == 'r')) { 
	tail->statement = static_cast<Node::Type>(13); 
	tail->sequence = static_cast<Node::Priopity>(4);
	}
	else
	{ 
		bool dot = false, number = false, incorrect = false, minus = (str[0] =='-');
		if (minus) {
			str.erase(0, 1);
		}
		for (int i = 0; i < (int)str.length(); i++) {
			number = ((str[i] == '0') || (str[i] == '1') || (str[i] == '2') || (str[i] == '3') || (str[i] == '4') || (str[i] == '5') || (str[i] == '6') ||
				(str[i] == '7') || (str[i] == '8') || (str[i] == '9'));
			if (!dot) dot = str[i] == '.';
			if ((!number) && (!dot)) { 
				incorrect = true;
				tail->statement = static_cast<Node::Type>(0);
				break;
			}
		}
		if (number && dot) {
			tail->statement = static_cast<Node::Type>(15);
			tail->sequence = static_cast<Node::Priopity>(10);
			tail->result = atof(tail->data.c_str());
		}
		else if (number && !dot) {
			tail->statement = static_cast<Node::Type>(14);
			tail->sequence = static_cast<Node::Priopity>(10);
			tail->result = (double)(stoi(tail->data));
		}
		if (minus) tail->result = - tail->result;
	}
}

void calculation::print_to_console()
{
	cout << "Size: " << size << endl;
	if (head != nullptr) {
		Node* temp = head;
		while (temp->next) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		if (temp) cout << temp->data << endl;
		cout << endl;
	}
	else cout << "nothing to print" << endl;
}

void calculation::clear()
{
	if (head) {
		while (head->next) {
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void calculation::infixToPrefix() {
	calculation* top = new calculation;
	Node* transform = tail;
	calculation* result = new calculation;
	while (transform->prev)
	{
		switch (transform->sequence)
		{
		case calculation::Node::Priopity::operands:
			result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
			break;
		case calculation::Node::Priopity::brackets:
			if (transform->data == ")") {
				top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
			}
			else {
				while (top->tail->data != ")")
				{
					result->push_front(top->tail->data, top->tail->result, top->tail->sequence, top->tail->statement);
					top->pop_back();
				}
				top->pop_back();
			}
			break;
		case calculation::Node::Priopity::plus:
			if ((!top->isEmpty()) && ((int)top->tail->sequence >= (int)calculation::Node::Priopity::plus)) {
				while ((int)top->tail->sequence >= (int)calculation::Node::Priopity::plus) {
					result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
					top->pop_back();
					if (top->isEmpty()) break;
				}
			}
			else top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
			break;
		case calculation::Node::Priopity::multiply:
			if ((!top->isEmpty()) && ((int)top->tail->sequence >= (int)calculation::Node::Priopity::multiply)) {
				while ((int)top->tail->sequence >= (int)calculation::Node::Priopity::multiply) {
					result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
					top->pop_back();
					if (top->isEmpty()) break;
				}
			}
			else top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
			break;
		case calculation::Node::Priopity::raise:
			if ((!top->isEmpty()) && ((int)top->tail->sequence >= (int)calculation::Node::Priopity::raise)) {
				while ((int)top->tail->sequence >= (int)calculation::Node::Priopity::raise) {
					result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
					top->pop_back();
					if (top->isEmpty()) break;
				}
			}
			else top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
			break;
		case calculation::Node::Priopity::func:
			if ((!top->isEmpty()) && ((int)top->tail->sequence == (int)calculation::Node::Priopity::func)) {
				while ((int)top->tail->sequence == (int)calculation::Node::Priopity::func) {
					result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
					top->pop_back();
					if (top->isEmpty()) break;
				}
			}
			else top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
			break;
		}
		transform = transform->prev;
	}
	switch (transform->sequence)
	{
	case calculation::Node::Priopity::operands: {
		result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
		break;
	}
	case calculation::Node::Priopity::brackets: {
		if (transform->data == ")") {
			top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
		}
		else {
			while (top->tail->data != ")")
			{
				result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
				top->pop_back();
			}
		}
		break;
	}
	case calculation::Node::Priopity::func: {
		if ((!top->isEmpty()) && ((int)top->tail->sequence == (int)calculation::Node::Priopity::func)) {
			while ((int)top->tail->sequence == (int)calculation::Node::Priopity::func) {
				result->push_front(transform->data, transform->result, transform->sequence, transform->statement);
				top->pop_back();
				if (top->isEmpty()) break;
			}
		}
		else top->push_back(transform->data, transform->result, transform->sequence, transform->statement);
		break;
	}
	}
		if (!top->isEmpty()) {
			do {
				result->push_front(top->tail->data, 0, top->tail->sequence, top->tail->statement);
				top->pop_back();
			} while (!top->isEmpty());
		}
		head = result->head;
		tail = result->tail;
}

double calculation::count(){
	Node* temp = tail;
	Stack* top = new Stack;

	while (temp->prev) {
		if (temp->sequence == calculation::Node::Priopity::operands)
		{
			top->push_back(temp->result);
		}
		else if ((int)temp->sequence == 4) {
			if (!top->isEmpty()) {
				double operand1 = top->return_last();
				top->pop_back();
				switch ((int)temp->statement)
				{
				case 6: {
					top->push_back(sin(operand1));
					break;
				}
				case 7: {
					top->push_back(cos(operand1));
					break;
				}
				case 8: {
					top->push_back(tan(operand1));
					break;
				}
				case 9: {
					top->push_back(1 / tan(operand1));
					break;
				}
				case 10: {
					top->push_back(log(operand1));
					break;
				}
				case 11: {
					top->push_back(log10(top->return_last()));
					break;
				}
				case 12: {
					top->push_back(sqrt(operand1));
					break;
				}
				case 13: {
					top->push_back(cbrt(operand1));
					break;
				}
				}
			}
			else {
				cout << "Error";
				return 0.00;
			}
		}
		else {
			double operand1, operand2;
			if (!top->isEmpty()) {
				operand1 = top->return_last();
				top->pop_back();
			}
			else {
				cout << "Error";
				return 0.0;
			}
			if (!top->isEmpty()) {
				operand2 = top->return_last();
				top->pop_back();
			}
			else {
				cout << "Error";
				return 0.0;
			}
			switch ((int)temp->statement)
			{
			case 1: {
				top->push_back((operand2 + operand1));
				break;
			}
			case 2: {
				top->push_back((operand1 - operand2));
				break;
			}
			case 3: {
				top->push_back((operand1 * operand2));
				break;
			}
			case 4: {
				top->push_back((operand1 / operand2));
				break;
			}
			}
		}
		temp = temp->prev;
	}

	if ((int)temp->sequence == 4) {
		if (!top->isEmpty()) {
			double operand1 = top->return_last();
			top->pop_back();
			switch ((int)temp->statement)
			{
			case 6: {
				top->push_back(sin(operand1));
				break;
			}
			case 7: {
				top->push_back(cos(operand1));
				break;
			}
			case 8: {
				top->push_back(tan(operand1));
				break;
			}
			case 9: {
				top->push_back(1 / tan(operand1));
				break;
			}
			case 10: {
				top->push_back(log(operand1));
				break;
			}
			case 11: { 
				top->push_back(log10(operand1));
				break;
			}
			case 12: {
				top->push_back(sqrt(operand1));
				break;
			}
			case 13: { 
				top->push_back(cbrt(operand1));
				break;
			}
			}
		}
		else {
			cout << "Error";
			return 0.00;
		}
	}
	else {
		double operand1, operand2;
		if (!top->isEmpty()) {
			operand1 = top->return_last();
			top->pop_back();
		}
		else {
			cout << "Error";
			return 0.0;
		}
		if (!top->isEmpty()) {
			operand2 = top->return_last();
			top->pop_back();
		}
		else {
			cout << "Error";
			return 0.0;
		}
		switch ((int)temp->statement)
		{
		case 1: {
			top->push_back((operand2 + operand1));
			break;
		}
		case 2: {
			top->push_back((operand1 - operand2));
			break;
		}
		case 3: {
			top->push_back((operand1 * operand2));
			break;
		}
		case 4: {
			top->push_back((operand1 / operand2));
			break;
		}
		case 5: {
			top->push_back(pow(operand1, operand2));
			break;
		}
		}
	}

	return top->return_last();
}

string calculation::return_data()
{
	return tail->data;
}
