#include <iostream>
#include <string>
using namespace std;


string find_smallest_word(const string& sentence) {
  string smallest_word = sentence;
  size_t smallest_word_length = sentence.length();

  size_t start = 0;
  size_t end = sentence.find(' ');

  while (end != string::npos) {
    string word = sentence.substr(start, end - start);

    if (word.length() < smallest_word_length) {
      smallest_word = word;
      smallest_word_length = word.length();
    }

    start = end + 1;
    end = sentence.find(' ', start);
  }

  string last_word = sentence.substr(start);

  if (last_word.length() < smallest_word_length) {
    smallest_word = last_word;
  }

  return smallest_word;
}

string find_longest_word(const string& sentence) {
  string longest_word = "";
  size_t longest_word_length = 0;

  size_t start = 0;
  size_t end = sentence.find(' ');

  while (end != string::npos) {
    string word = sentence.substr(start, end - start);

    if (word.length() > longest_word_length) {
      longest_word = word;
      longest_word_length = word.length();
    }

    start = end + 1;
    end = sentence.find(' ', start);
  }

  string last_word = sentence.substr(start);

  if (last_word.length() > longest_word_length) {
    longest_word = last_word;
  }

  return longest_word;
}

int main() {
  string sentence = "Gedanken means thoughts in German. The term was popularized by Albert Einstein, who applied gedankenexperiment to his work conceptualizing the theory of relativity.";



  string smallest_word = find_smallest_word(sentence);
  string longest_word = find_longest_word(sentence);

  cout << "Smallest word: " << smallest_word << endl;
  cout << "Longest word: " << longest_word << endl;

  return 0;
}
