#ifndef WUMPHEAD_HPP
#define WUMPHEAD_HPP

#include <vector>
#include <iostream>

using namespace std;

void setup();
void clear_tmp_file();
void ask_for_custom_number(string objects_chars, vector<int> & list_int_objects);
bool reset_values_ask(bool reset_values);

int start();

#endif  // Gemaakt door Alexander