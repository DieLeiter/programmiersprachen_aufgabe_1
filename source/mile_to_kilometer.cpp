#include <iostream>;

double mile_to_kilometer(double miles) {
	if (miles < 0) {
		std::cout << "Bitte geben Sie eine positive Zahl ein!" << std::endl;
		return -1;
	}

	return miles * 1.60934;
}

int main() {
	double miles;
	double kilometers;

	std::cout << "Bitte geben Sie eine Meilenanzahl ein, die in Kilometer umgerechnet werden soll: \n";
	std::cin >> miles;

	kilometers = mile_to_kilometer(miles);

	std::cout << miles << " Meilen entsprechen " << kilometers << " Kilometern." << std::endl;

	return 0;
}
