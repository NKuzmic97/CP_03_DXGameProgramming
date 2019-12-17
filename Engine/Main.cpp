#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>

bool vector_contains_word(const std::vector<std::string>& vec, const std::string& word) {
	for(const auto& w : vec) {
		if(w == word) {
			return true;
		}
	}

	return false;
}

std::vector<int> fill_buckets(const std::string& word) {
	std::vector<int> buckets(26, 0);
	
	for(char c : word) {
		buckets[c - 'a']++;
	}

	return buckets;
}

int score_match(const std::string& word1, const std::string& word2) {
	const auto buckets1 = fill_buckets(word1);
	const auto buckets2 = fill_buckets(word2);

	int score = 0;
	
	for(int i=0;i<26;i++) {
		score += std::min(buckets1[i], buckets2[i]);
	}

	for(int i=0;i<5;i++) {
		if(word1[i] == word2[i]) {
			score++;
		}	
	}

	return score;
}

int main() {
	std::vector<std::string> five_words;

	{
	std::ifstream five_word_file("words.txt");
	for(std::string line;std::getline(five_word_file,line);) {
		if(line.empty()) {
			continue;;
		}

		five_words.push_back(line);
	}
	}

	std::mt19937 rng(std::random_device{}());
	const std::uniform_int_distribution<int> dist(0, five_words.size() - 1);

	const std::string target = five_words[dist(rng)];

	while(true){

		std::cout << "Guess a five letter word: ";
		std::string guess;
		std::getline(std::cin, guess);

		for(auto& c : guess) {
			c = std::tolower(c);
		}

		if(guess.size() != 5) {
			std::cout << "That is not a five letter word" << std::endl;
			continue;
		}

		if(!vector_contains_word(five_words,guess)){
			std::cout << "That is not a legit word" << std::endl;
			continue;
		}

		const int score = score_match(guess, target);
			if(score == 10) {
				std::cout << "You have won!" << std::endl;
				break;
			}
			else {
				std::cout << "Incorrect. You gained " << score << " points for your guess." << std::endl;
				continue;
			}

		
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}