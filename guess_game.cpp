/*	Guess game by Night3098 	*/

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int MAX_WRONG = 10;
  int i = 0;
  int y = 0;

  vector<string> words;

  words.push_back("computer");
  words.push_back("earth");
  words.push_back("book");
  words.push_back("editor");
  words.push_back("manager");
  words.push_back("browser");
  words.push_back("internet");
  words.push_back("smartphone");
  words.push_back("video");
  words.push_back("photo");
  words.push_back("vector");
  words.push_back("title");

  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(words.begin(), words.end());

  string WORD = words[1];
  // cout << WORD << endl;

  string soFar(WORD.size(), '_');
  // cout << soFar;

  int wrong = 0;
  string used = "";
  cout << "Welcome. Guess the word. You have 10 attempts." << endl;
  cout << "Hint: first letter: " << WORD[0] << endl;

  while ((wrong < MAX_WRONG) && (soFar != WORD)) {
    cout << "You can allow " << (MAX_WRONG - wrong) << " errors." << endl;
    cout << "You used the following letters: " << used << endl;

    char guess;
    cout << "Enter the letter: " << soFar << endl;
    cin >> guess;

    while ((used.find(guess) != string::npos) && (used.find(guess) > 5)) {
      cout << "This letter has already been used. [o]: " << guess << endl;
      cout << "Letter: " << soFar << endl;
      cin >> guess;
    }
    used += guess;

    if (WORD.find(guess) != string::npos) {
      cout << "Greate" << endl;
      for (int i = 0; i < WORD.length(); i++) {
        if (WORD[i] == guess) {
          soFar[i] = guess;
        }
      }
    } else {
      cout << "Soryy, [" << guess << "] - this letter isn't in this word...."
           << endl;
      wrong++;
    }
    // system("clear");   // If you want to clear the screen after entering a
    // letter, uncomment this line. If using windows - write cls, if mac or
    // linux - clear
  }

  if (wrong == MAX_WRONG) {
    cout << "You lose)))))" << endl;
  } else {
    cout << "You win" << endl;
  }
  cout << "Answer: " << WORD << endl;
  return 0;
}
