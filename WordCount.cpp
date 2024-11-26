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
  word = makeValidWord(word);
int key = hash(word);
for (auto& pair : table[key]) {
        if (pair.first == word) {
            pair.second++;
            return pair.second;
        }
    }
    if (word != "") {
        table[key].emplace_back(word, 1);
        return 1;
    }
    else {
        return 0;
    }
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
    int key = hash(word);
    for (auto it = table[key].begin(); it != table[key].end(); it++) {
        if (it->first == word) {
            if (it->second > 1) {
                it->second--;
                return it->second;
            }
		else {
                table[key].erase(it);
                return 0;
            }
        }
    }
    return -1;
}

bool WordCount::isWordChar(char c) {
	
	if( std::isalpha(c)==0){
        return false;
    }
    else{
        return true;
    }
}

std::string WordCount::makeValidWord(std::string word) {
    std::string validWord;

    for (size_t i = 0; i < word.size(); ++i) {
        if (isWordChar(word[i])) {
            // Add alphabetic characters to the valid word in lowercase
            validWord += std::tolower(word[i]);
        } else if ((word[i] == '\'' || word[i] == '-') &&
                   i > 0 && i < word.size() - 1 &&
                   isWordChar(word[i - 1]) && isWordChar(word[i + 1])) {
            // Retain hyphens/apostrophes if surrounded by valid characters
            validWord += word[i];
        }
    }

    return validWord;
}




