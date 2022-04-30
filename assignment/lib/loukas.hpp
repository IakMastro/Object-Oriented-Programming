#ifndef LOUKAS_HPP
#define LOUKAS_HPP

#include "player.hpp"

class Loukas : public Player {
private:
  int goal_poss[2];

public:
  Loukas();
  void generateLocations(int max_row, int max_col);
  bool move();
  void getGoalLocations(int goal_poss[2]);
};

#endif