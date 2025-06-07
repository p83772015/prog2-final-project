// Copyright (C) 2025 by Jericho S.
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

const char reset_color[] = "\033[0m";
const char bold_font[] = "\033[1m";


int
main ()
{
  char text[82];
  int text_length;

  // Ask user for text
  cout
    << "Enter a message in english (no spaces, 81 characters max):"
    << "\n\n";
  cout << bold_font << "TEXT:" << reset_color << ' ';
  cin.getline(text, 82);

  // Compute length of text
  text_length = strlen(text);

  // Compute square's column and row length
  int row = floor(sqrt(text_length));
  int col = ceil(sqrt(text_length));

  // Construct the grid
  char grid[row][col];

  // Place each character of text in the grid
  int text_i = 0;
  for (int r = 0; r < row; ++r) {
    for (int c = 0; c < col; ++c) {
      grid[r][c] = (text_i < text_length) ?
	text[text_i++] :
	' ';
    }
  }

  // Print the grid
  cout << bold_font << "SECRET: " << reset_color;
  for (int c = 0; c < col; ++c) {
    for (int r = 0; r < row; ++r) {
      cout << grid[r][c];
    }
    cout << ' ';
  }
  cout << '\n';

  return 0;
}
