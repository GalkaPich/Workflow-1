#include <cstdio>

unsigned int GCD(unsigned int a, unsigned int b) {
	do {
		if (a>b) {
			int t = a;
			a = b;
			b = t;
		}
		b = b%a;
	} while (b);
	return a;
}

int main() {
	unsigned int a = 60, b = 13;
	printf("Greatest common divisor for %d and %d is %d\n", a, b, GCD(a, b));
	return 0;
}
