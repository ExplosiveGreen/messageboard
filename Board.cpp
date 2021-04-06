#include "Board.hpp"
using ariel::Direction;
#include <stdexcept>

namespace ariel {
       void Board::post(u_int row, u_int column, Direction direction, string message) {
              //changing the range of the board if needed
              //setting rhe new start point of the board if the start point of the message not in the board 
              if(row<Board::startPoint.first||Board::startPoint.first==-1){Board::startPoint.first=row;}
              if(column<Board::startPoint.second||Board::startPoint.second==-1){Board::startPoint.second=column;}
              //geting the end point of the message
		pair<u_int,u_int>endPoint;
              if(direction==Direction::Horizontal){
                     endPoint.first=row;
                     endPoint.second=column+message.size();
              }
              else if(direction==Direction::Vertical){
                     endPoint.first=row+message.size();
                     endPoint.second=column;
              }
              //setting rhe new end point of the board if the end point of the message not in the board 
              if(endPoint.first>Board::endPoint.first||Board::endPoint.first==-1){Board::endPoint.first=endPoint.first;}
              if(endPoint.second>Board::endPoint.second||Board::endPoint.second==-1){Board::endPoint.second=endPoint.second;}
              string point;
              for(u_int i=0;i<message.size();i++){
                     //geting the index in the board too put the current char of the message
                     if(direction==Direction::Horizontal){
                            point=""+to_string(row)+","+to_string((column+i));
                     }
                     else if(direction==Direction::Vertical){
                            point=""+to_string((row+i))+","+to_string(column);
                     }
                     //puting in the current message char in the board
                     Board::chars[point]=message.at(i);
              }
       }
       string Board::read(u_int row, u_int column, Direction direction, u_int length) {
              string point;
              string output;
              pair<u_int,u_int>currentPoint;
              unordered_map<string, char>:: iterator itr;
              for(u_int i=0;i<length;i++){
                     //geting the index in the board that we current reading
                     if(direction==Direction::Horizontal){
                            currentPoint.first=row;
                            currentPoint.second=column+i;
                     }
                     else if(direction==Direction::Vertical){
                            currentPoint.first=row+i;
                            currentPoint.second=column;
                     }
                     point=""+to_string(currentPoint.first)+","+to_string(currentPoint.second);
                     //checking if there something in this current index if not add '_' if yes add the value
                     itr=Board::chars.find(point);
                     if (itr == Board::chars.end()){output+='_';}
                     else{output+=itr->second;}
              }
              return output;
       }
       void Board::show() {
              string point;
              unordered_map<string, char>:: iterator itr;
              char ch=0;
              for(u_int i=Board::startPoint.first;i<=Board::endPoint.first&&i>=0;i++){
                     for(u_int j=Board::startPoint.second;j<=Board::endPoint.second&&j>=0;j++){
                            point=""+to_string(i)+","+to_string(j);
                            itr=Board::chars.find(point);
                            if (itr == Board::chars.end()){ch='_';}
                            else{ch=itr->second;}
                            cout<<ch;
                     }
              cout<<endl;
              }
       }
}
