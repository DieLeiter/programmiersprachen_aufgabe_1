#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES

#include <catch.hpp>
#include <cmath>

int gcd(int a, int b) { 
    int max; //maximum possible divider
    
    // if a or b is negative, make positive
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= 1;
    }
    
    // select greater number as maximum
    if (a > b) {
        max = a;
    }
    else {
        max = b;
    }
    
    // if a parameter is 0, maximum divider is gcd
    if (a == 0 || b == 0) {
        return max;
    }
    else {
        for (int i = max; i >= 1; i--) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
    }
}

int checksum(int a) {
    int quersumme = 0;

    while (a > 0) {
        quersumme += a % 10;
        a /= 10;
    }

    return quersumme;
}

int sum_multiples(int a) {
    int sum = 0;

    for (int i = 1; i <= a; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
    return sum;
}

float fract(float a) {
    if (a < 0) {
        a *= -1;
    }

    return a - (int)a;
}

float cylinder_volume(float r, float h) {
    if (r > 0 && h > 0) {
        float volume = M_PI * pow(r, 2.0f) * h;
        return volume;
    }

    return 0.0f;
}

float cylinder_surface(float r, float h) {
    if (r > 0 && h > 0) {
        float surface = 2 * M_PI * r * (r + h);
        return surface;
    }

    return 0;
}

long factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    }
    else {
        return 1;
    }
}

bool is_prime(int a) {
    for (int i = 2; i < a; i++) {
        if ((a % i) == 0) {
            return false;
            break;
        }
    }
    return true;
}

TEST_CASE("describe_checksum", "[checksum]") {
    REQUIRE(checksum(121618) == 19);
    REQUIRE(checksum(123) == 6);
    REQUIRE(checksum(0) == 0);
}

TEST_CASE("describe_gcd", "[gcd]") { 
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
    REQUIRE(gcd(0, 7) == 7);
    REQUIRE(gcd(-2, 8) == 2);
}

TEST_CASE("describe_sum_multiple", "[sum_multiple]") {
    REQUIRE(sum_multiples(1000) == 234168);
    REQUIRE(sum_multiples(10) == 33);
}

TEST_CASE("describe_fract", "[fract]") {
    REQUIRE(fract(1.233f) == Approx(0.233f));
    REQUIRE(fract(0.000f) == Approx(0.000f));
    REQUIRE(fract(5.0f) == Approx(0.000f));
    REQUIRE(fract(-6.475f) == Approx(0.475f));
}

TEST_CASE("describe_cylinder_volume", "[cylinder_volume]") {
    REQUIRE(cylinder_volume(2.0f, 4.0f) == Approx(50.265f));
    REQUIRE(cylinder_volume(0.0f, 10.0f) == Approx(0.0f));
    REQUIRE(cylinder_volume(12.3f, -3.14f) == Approx(0.0f));
}

TEST_CASE("describe_cylinder_surface", "[cylinder_surface]") {
    REQUIRE(cylinder_surface(2.0f, 4.0f) == Approx(75.398f));
    REQUIRE(cylinder_surface(6.13f, 0.0f) == Approx(0.0f));
    REQUIRE(cylinder_surface(-13.4f, 0.7f) == Approx(0.0f));
}

TEST_CASE("describe_factorial", "[factorial]") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(11) == 39916800);
}

TEST_CASE("describe_is_prime", "[is_prime]") {
    REQUIRE(is_prime(13) == true);
    REQUIRE(is_prime(9) == false);
}


int main(int argc, char* argv[])
{
  sum_multiples(1000);
  return Catch::Session().run(argc, argv);
}
