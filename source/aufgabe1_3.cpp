#include <iostream>

int main() {

	int number = 20;
	bool numberFound = false;

	while (!numberFound) {
		for (int i = 1; i <= 20; i++) {
			if (i != 20 && number % i == 0) {
				continue;
			}
			if (i == 20 && number % i == 0) {
				numberFound = true;
				break;
			}
			else {
				break;
			}
		}

		number += 20;
	}

	std::cout << number << " ist die kleinste Zahl die durch alle Zahlen von 1 bis 20 teilbar ist!";

	return 0;
}