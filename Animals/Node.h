#pragma once
#include <string>
class Node
{
public:
	Node() {};
	virtual ~Node() {};
	virtual void ask() = 0;
};
class Question : public Node {
public:
	Question(std::string text_, Node* y, Node* n)
		: text(text_), yes(y), no(n) {};
	virtual ~Question() {
		delete yes;
		delete no;
	}
	virtual void ask();
	const std::string text;
	Node* yes;
	Node* no;
};

class Answer : public Node {
public:
	Answer(std::string text_) : text(text_) {};
	virtual ~Answer() {};
	virtual void ask();
	const std::string text;
};

