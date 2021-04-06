#include <string>
#include "Direction.hpp"
#include <unordered_map>
#include <iostream>
using namespace std;
namespace ariel {
	class Board {
		unordered_map<string, char> chars;
		pair<u_int,u_int>startPoint;
		pair<u_int,u_int>endPoint;
		public:
			Board() {
				startPoint=make_pair(-1,-1);
				endPoint=make_pair(-1,-1);
			}
			~Board() {}
			void post(u_int row, u_int column, Direction direction, std::string message);
			std::string read(u_int row, u_int column, Direction direction, u_int length);
			void show();
	};
}
