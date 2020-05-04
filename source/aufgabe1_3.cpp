#include <iostream>

int main() {

	int number = 0;
	bool numberFound = false;

	while (!numberFound) {
		number += 20;

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
	}

	std::cout << number << " ist die kleinste Zahl die durch alle Zahlen von 1 bis 20 teilbar ist!";

	return 0;
}