/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("good post") {
    Board board;
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(board.post(50,200,Direction::Horizontal,"efg"));
    CHECK_NOTHROW(board.post(100,2065,Direction::Horizontal,"hijkl"));
    CHECK_NOTHROW(board.post(101,200,Direction::Horizontal,"mnopqrst"));
    CHECK_NOTHROW(board.post(14,200,Direction::Horizontal,"uvwxyz"));
}
TEST_CASE("bad post") {
    Board board;
    CHECK_THROWS(board.post(-100,200,Direction::Horizontal,"abcd"));
    CHECK_THROWS(board.post(50,-200,Direction::Horizontal,"efg"));
    CHECK_THROWS(board.post(-100,-2065,Direction::Horizontal,"hijkl"));
    CHECK_THROWS(board.post(-101,200,Direction::Horizontal,"mnopqrst"));
    CHECK_THROWS(board.post(14,-200,Direction::Horizontal,"uvwxyz"));
}
TEST_CASE("good read") {
    Board board;
    CHECK_NOTHROW(board.read(100,200,Direction::Horizontal,4));
    CHECK_NOTHROW(board.read(50,200,Direction::Horizontal,3));
    board.post(100,200, Direction::Horizontal, "abcd");
    CHECK(board.read(99,201, Direction::Vertical,3) == string("_b_"));
    CHECK(board.read(99,201, Direction::Vertical,0) == string(""));
    board.post(99,202, Direction::Vertical, "xyz");
    CHECK(board.read(100,200, Direction::Horizontal,6) == string("abyd__"));
}
TEST_CASE("bad read") {
    Board board;
    CHECK_THROWS(board.read(-100,200,Direction::Horizontal,4));
    CHECK_THROWS(board.read(50,-200,Direction::Horizontal,3));
    CHECK_THROWS(board.read(100,2065,Direction::Horizontal,-2));
    CHECK_THROWS(board.read(101,200,Direction::Horizontal,-5));
    CHECK_THROWS(board.read(14,200,Direction::Horizontal,-7));
}

