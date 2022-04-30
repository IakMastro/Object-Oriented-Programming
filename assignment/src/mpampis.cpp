#include <ncurses.h>
#include <random>
#include <iostream>
#include <time.h>
#include "../lib/mpampis.hpp"

Mpampis::Mpampis() : Player('M') {
}

void Mpampis::generateLocations(int max_row, int max_col) {
  time_t n_time;
  srand((unsigned) time(&n_time));

  for (;;) {
    int row = rand() % max_row;
    int col = rand() % max_col;

    if (mvinch(row, col) == '.' && mvinch(row, col) != '*') {
      current_poss[0] = row;
      current_poss[1] = col;
      mvaddch(row, col, this->symbol);
      break;
    }
  }
}

// Μέθοδος κίνησης του Μπάμπη που κληρονομεί από τον Player
// Επιστρέφει true εάν βρει τον στόχο, διαφορετικά επιστρέφει false
bool Mpampis::move() {
  // Διάβασμα από το πληκτρολόγιο
  int ch = getch();

  // Επιλογή κίνησης
  switch (ch) {
    case KEY_UP: // Πάνω βελάκι
      if (mvinch(current_poss[0] - 1, current_poss[1]) == '.') {
        mvaddch(current_poss[0], current_poss[1], '.');
        current_poss[0]--;
        mvaddch(current_poss[0], current_poss[1], this->symbol);
      } else if (mvinch(current_poss[0] - 1, current_poss[1]) == 'G') {
        return true;
      }
      break;
    case KEY_DOWN: // Κάτω βελάκι
      if (mvinch(current_poss[0] + 1, current_poss[1]) == '.') {
        mvaddch(current_poss[0], current_poss[1], '.');
        current_poss[0]++;
        mvaddch(current_poss[0], current_poss[1], this->symbol);
      } else if (mvinch(current_poss[0] + 1, current_poss[1]) == 'G') {
        return true;
      }
      break;
    case KEY_LEFT: // Αριστερό βελάκι
      if (mvinch(current_poss[0], current_poss[1] - 1) == '.') {
        mvaddch(current_poss[0], current_poss[1], '.');
        current_poss[1]--;
        mvaddch(current_poss[0], current_poss[1], this->symbol);
      } else if (mvinch(current_poss[0], current_poss[1] - 1) == 'G') {
        return true;
      }
      break;
    case KEY_RIGHT: // Δεξί βελάκι
      if (mvinch(current_poss[0], current_poss[1] + 1) == '.') {
        mvaddch(current_poss[0], current_poss[1], '.');
        current_poss[1]++;
        mvaddch(current_poss[0], current_poss[1], this->symbol);
      } else if (mvinch(current_poss[0], current_poss[1] + 1) == 'G') {
        return true;
      }
      break;
    case 27: // Έξοδος με το escape
      endwin(); // Καταστροφή ncurses
      exit(0); // Έξοδος παιχνιδιού
    default:
      return move(); // Διαφορετικά, τρέχει πάλι την μέθοδο αναδρομικά
  }

  refresh();
  return false;
}
