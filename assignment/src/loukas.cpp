#include <ncurses.h>
#include <random>
#include <time.h>
#include "../lib/loukas.hpp"

Loukas::Loukas() : Player('L') {
}

void Loukas::generateLocations(int max_row, int max_col) {
  time_t n_time;
  srand((unsigned) time(&n_time));

  for (;;) {
    int row = rand() % max_row;
    int col = rand() % max_col;

    if (mvinch(row, col) == '.' && mvinch(row, col) != '*' && mvinch(row, col) != 'M') {
      current_poss[0] = row;
      current_poss[1] = col;
      mvaddch(row, col, this->symbol);
      break;
    }
  }
}

// Μέθοδος κίνησης του Λουκά που κληρονομεί από τον Player
// Επιστρέφει true εάν βρει τον στόχο, διαφορετικά επιστρέφει false
bool Loukas::move() {
  // Εάν βρίσκεται σε διαφορετικό ύψος από τον στόχο, τότε κινείται ανάλογα
  if (current_poss[0] > goal_poss[0]) {
    if (mvinch(current_poss[0] - 1, current_poss[1]) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[0]--;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0] - 1, current_poss[1]) == 'G') {
      return true;
    }
  } else if (current_poss[0] < goal_poss[0]) {
    if (mvinch(current_poss[0] + 1, current_poss[1]) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[0]++;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0] + 1, current_poss[1]) == 'G') {
      return true;
    }
  }

  if (current_poss[1] > goal_poss[1]) {
    if (mvinch(current_poss[0], current_poss[1] - 1) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[1]--;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0], current_poss[1] - 1) == 'G') {
      return true;
    }
  } else if (current_poss[1] < goal_poss[1]) {
    if (mvinch(current_poss[0], current_poss[1] + 1) == '.') {
      mvaddch(current_poss[0], current_poss[1], '.');
      current_poss[1]++;
      mvaddch(current_poss[0], current_poss[1], this->symbol);
      return false;
    } else if (mvinch(current_poss[0], current_poss[1] + 1) == 'G') {
      return true;
    }
  }
}

void Loukas::getGoalLocations(int goal_poss[2]) {
  this->goal_poss[0] = goal_poss[0];
  this->goal_poss[1] = goal_poss[1];
}
