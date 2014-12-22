#include <iostream>
#include "Node.h"

int main() {
	Node* n = new Question(
		"It swims?",
		new Answer("whale"),
		new Question(
			"It barks?",
			new Answer("Dog"),
			new Answer("Cat")
		)
	);
	while (n->ask());
	delete n;

	return 0;
}
