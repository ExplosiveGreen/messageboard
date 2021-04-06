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
Board board;

TEST_CASE("test post") {
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(board.post(50,200,Direction::Vertical,"efg"));
    CHECK_NOTHROW(board.post(100,2065,Direction::Horizontal,"hijkl"));
    CHECK_NOTHROW(board.post(101,200,Direction::Horizontal,"mnop"));
    CHECK_NOTHROW(board.post(99,202,Direction::Vertical,"qrst"));
    CHECK_NOTHROW(board.post(14,200,Direction::Horizontal,"uvw"));
    CHECK_NOTHROW(board.post(17,207,Direction::Vertical,"xyz"));
}
TEST_CASE("test read") {
    CHECK(board.read(99,201, Direction::Vertical,3) == string("_bn"));
    CHECK(board.read(99,201, Direction::Vertical,0) == string(""));
    CHECK(board.read(100,200, Direction::Horizontal,6) == string("abrd__"));
    CHECK(board.read(101,199, Direction::Horizontal,6) == string("_mnsp_"));
    CHECK(board.read(13,200, Direction::Vertical,3) == string("_u_"));
    CHECK(board.read(49,200, Direction::Vertical,3) == string("_ef"));
    CHECK(board.read(100,2064, Direction::Horizontal,6) == string("_hijkl"));
}
TEST_CASE("random read") {
    ariel::Board bo;
    unsigned int random_row = rand() % 100;
    unsigned int random_col = rand() % 100;
    unsigned int random_len = rand() % 100;
    std::string str="messageboard";
    std::string ans="";
    CHECK_NOTHROW(bo.post(random_row, random_col, Direction::Horizontal, str));
    if(random_len<=str.size()){
        ans=str.substr(0,random_len);
    }
    else{
        ans=str;
        for(int i=0;i<random_len-str.size();i++){
         ans+='_';   
        }
    }
    CHECK(bo.read(random_row, random_col, Direction::Horizontal, random_len) == string(ans));
    CHECK_NOTHROW(bo.post(random_row, random_col, Direction::Horizontal, str));
    CHECK(bo.read(random_row, random_col, Direction::Horizontal, random_len) == string(ans));
}
TEST_CASE("random post") {
    ariel::Board bo;
    unsigned int random_row = 0;
    unsigned int random_col = 0;
    for(int i=0;i<3;i++){
        random_row = rand() % 100;
        random_col = rand() % 100;
        CHECK_NOTHROW(bo.post(random_row, random_col, Direction::Horizontal, "messageboard"));
    }
}
