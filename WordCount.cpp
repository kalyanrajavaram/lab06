// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int i=0;
	for(size_t j=0; j<CAPACITY; j++)
	{
		for(std::pair<std::string, int> pair: table[j])
		{
			i+=pair.second;
		}
	}
	return i;
}

int WordCount::getNumUniqueWords() const {
	size_t i=0;
	for(size_t j=0; j<CAPACITY; j++)
	{
		i+=table[j].size();
		
	}
	return i;
}

int WordCount::getWordCount(std::string word) const {
	size_t idx = hash(word);
		for(std::pair<std::string, int> pair: table[idx] )
		{
			if(pair.first==word)
			{
			return pair.second;
			}
		}
		return 0;
	}

	
int WordCount::incrWordCount(std::string word) {
	size_t idx=hash(word);
	int x=0;
	for(std::pair<std::string, int> pair: table[idx] )
	{
		if(pair.first==word)
		{
		pair.second++;
		x=pair.second;
		}
	}
	table[idx].emplace_back(word,1);
	return x;
}

int WordCount::decrWordCount(std::string word) {
	size_t idx=hash(word);
	int x=0;
	for(std::pair<std::string, int> pair: table[idx] )
	{
		if(pair.first==word)
		{
		pair.second--;
		x=pair.second;
		}
	}
	table[idx].emplace_back(word,1);
	return x;
}

bool WordCount::isWordChar(char c) {
	
	return  std::isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
 std::string validWord;
  for (size_t i = 0; i < word.size(); ++i) {
    if (isWordChar(word[i])) {
      validWord += std::tolower(word[i]);
    } else if ((word[i] == '\'' || word[i] == '-') && i > 0 && i < word.size() - 1 &&
               isWordChar(word[i - 1]) && isWordChar(word[i + 1])) {
      validWord += word[i];
    }
  }
  return validWord;
}
