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

        for (int i = 2; i <= max; i++) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
    }
    return 1;
}

TEST_CASE("describe_gcd", "[gcd]") { 
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
    REQUIRE(gcd(0, 7) == 1);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
