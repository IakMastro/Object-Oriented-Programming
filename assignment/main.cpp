#include <ncurses.h>
#include <clocale>
#include "lib/game.hpp"

int main(int argc, char** argv) {
  // Αρχικοποίηση του ελληνικού locale
  setlocale(LC_ALL, "");

  // Αρχικοποίηση του ncurses
  initscr();
  // start_color(); // Αρχικοποίηση χρωμάτων
  noecho(); // Απενεργοποίηση εμφάνισης συμβολοσειράς
  cbreak(); // Απενεργοποίηση line buffering
  curs_set(0); // Απενεργοποίηση κίνησης κατά την εισαγωγή χαρακτήρα
  intrflush(stdscr, FALSE); // Απενεργοποίηση κίνησης κατά την εισαγωγή πλήκτρου
  keypad(stdscr, TRUE); // Ενεργοποίηση πλήκτρων που είναι συνδεδεμένα στο πληκτρολόγιο

  // init_pair(1, COLOR_WHITE, COLOR_BLACK); // Αρχικοποίηση χρωμάτων για το χρώμα του χάρτη και του στόχου
  // init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Αρχικοποίηση χρωμάτων για τον Μπάμπη
  // init_pair(3, COLOR_GREEN, COLOR_BLACK); // Αρχικοποίηση χρωμάτων για τον Λουκά

  // Αρχικοποίηση παιχνιδιού
  // Δέχεται ως όρισμα το path του αρχείου που περίεχει τις οδηγίες
  // για την δημιουργία του χάρτη
  Game game(argv[1]);
  clear(); // Καθαρισμός οθόνης
  game.initGame(); // Αρχικοποίηση μεταβλητών παιχνιδιού
  refresh();
  game.run(); // Εκτέλεση παιχνιδιού

  return 0;
}
