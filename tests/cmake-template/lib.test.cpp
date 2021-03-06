#include <catch2/catch.hpp>
#include <cmake-template/lib.h>

TEST_CASE("Addition via `add` function", "[add]") {
	REQUIRE(add(0, 0) == 0);

	SECTION("Positive numbers") { REQUIRE(add(1, 1) == 2); }

	SECTION("Negative numbers") { REQUIRE(add(-1, -1) == -2); }
}
