/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>//
#include <string_view>

using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
	CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
	CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
	CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)\n( : )/\n( : )"));
	CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\n( : )"));
	
	
	
	/* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
	CHECK_THROWS(snowman(15632));
	CHECK_THROWS(snowman(111111%2111565));
	CHECK_THROWS(snowman(11111111.0));
}

TEST_CASE("input short or long") {
    CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(123));
	CHECK_THROWS(snowman(2123));
	CHECK_THROWS(snowman(112121411));
}

TEST_CASE("no range (0,5,6,7,8,9") { 
    CHECK_THROWS(snowman(11114410));
	CHECK_THROWS(snowman(11154411));
	CHECK_THROWS(snowman(11114466));
	CHECK_THROWS(snowman(19914411));
	CHECK_THROWS(snowman(11114711));
}

TEST_CASE("+ - * /") { 
	CHECK_THROWS(snowman(33333333-22222222));
	CHECK_THROWS(snowman(11111111*22222222));
	CHECK_THROWS(snowman(22222222^11111111));
	CHECK_THROWS(snowman(33333333/22222222));
}






