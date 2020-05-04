#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b) { 
    if (a != 0 && b != 0) {
        int max = 0;

        if (a < b) {
            max = a;
        }
        else {
            max = b;
        }

        for (int i = max; i >= 2; i--) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
    }
    return 1;
}

int checksum(int a) {
    int quersumme = 0;

    if (a < 0) {
        a *= -1;
    }

    while (a > 0) {
        quersumme += a % 10;
        a /= 10;
    }

    return quersumme;
}

int sum_multiples() {
    int sum = 0;

    for (int i = 3; i <= 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

TEST_CASE("describe_checksum", "[checksum]") {
    REQUIRE(checksum(121618) == 19);
    REQUIRE(checksum(123) == 6);
    REQUIRE(checksum(0) == 0);
    REQUIRE(checksum(-123) == 6);
}

TEST_CASE("describe_gcd", "[gcd]") { 
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
    REQUIRE(gcd(0, 7) == 1);
}

TEST_CASE("describe_sum_multiple", "[sum_multiple]") {
    REQUIRE(sum_multiples() == 10);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
