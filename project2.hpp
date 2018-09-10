///////////////////////////////////////////////////////////////////////////////
// project2.hpp
//
// Implementations of algorithms for counting vowels, longest "oreo" problem,
// and longest repeated substring problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cctype>
#include <fstream>
#include <random>
#include <string>

bool read_text_file(std::string& result, const std::string& path) {

  std::ifstream f(path);
  if (!f) {
    return false;
  }

  result.clear();

  for (char ch; f.get(ch);) {
    result.push_back(ch);
  }

  return true;
}

std::string random_string(int seed, int size) {

  assert(size >= 0);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist(0x00, 0xFF);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

int vowel_count(const std::string& s) {
  if(s.length() == 0){
    return 0;
  }

  int vowelCount = 0;
  for(auto it = s.begin(); it != s.end(); it++){
      if (*it == 'A' || *it == 'a' ||
          *it == 'E' || *it == 'e' ||
          *it == 'I' || *it == 'i' ||
          *it == 'O' || *it == 'o' ||
          *it == 'U' || *it == 'u')
          vowelCount++;
    }

  return vowelCount;
}

std::string longest_oreo(const std::string& s) {
  assert(s.size() > 0);

  std::string string1 = "z";
	int n = s.length();

	if(n < 2){
	  return s;
	}

	int begin = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		  begin++;
		  for (auto itty = it + 1; itty != s.end(); itty++) {  // 'itty+1' because we want to start searching at the next element
		      if (*itty == *it) {                                // if there is another instance of 'it'...
		          int length = (itty - it) + 1;                    // make a note of the # of chars between them
		          if (length > string1.size()) {
			             string1 = s.substr(begin-1, length);           // remember the string
		          }
		      }
	     }
	 }

   return string1;
}

std::string longest_repeated_substring(const std::string& s) {
  assert(s.size() > 0);

  std::string LR = "";
	std::string temp = "";
	std::string temp2 = "";
	std::size_t found;
	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			temp2 = s[j + 1];
			found = s.find(temp, j);
			if (found != std::string::npos)
			{
				if (temp.length() > LR.length())
				{
					LR = temp;
				}
			}
			temp.append(temp2);
		}
		temp = "";
	}

	return LR;
}
