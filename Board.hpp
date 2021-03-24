#include <string>
#include "Direction.hpp"
#include <unordered_map>
#include <iostream>
using namespace std;
#define SIZE 7
namespace ariel {
	class Board {
		unordered_map<string, char> chars;
		pair<int,int>startPoint;
		pair<int,int>endPoint;
		public:
			Board() {
				startPoint=make_pair(-1,-1);
				endPoint=make_pair(-1,-1);
			}
			~Board() {}
			void post(int row, int column, Direction direction, std::string message);
			std::string read(int row, int column, Direction direction, int length);
			void show();
	};
}
