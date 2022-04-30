#ifndef MPAMPIS_HPP
#define MPAMPIS_HPP

#include "player.hpp"

class Mpampis : public Player {
public:
  Mpampis();
  void generateLocations(int max_row, int max_col);
  bool move();
};

#endif