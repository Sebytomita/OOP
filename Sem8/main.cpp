#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cctype>

std::string lower(const std::string& str) {
    std::string lower_str;
    lower_str.reserve(str.size());
    for (char c : str) {
        lower_str.push_back(std::tolower(static_cast<unsigned char>(c)));
    }
    return lower_str;
}

std::vector<std::string> split_words(const std::string& str, const std::string& delimiters) {
    std::vector<std::string> words;
    std::string::size_type start = str.find_first_not_of(delimiters, 0);
    std::string::size_type end = str.find_first_of(delimiters, start);

    while (std::string::npos != start || std::string::npos != end) {
        words.push_back(str.substr(start, end - start));
        start = str.find_first_not_of(delimiters, end);
        end = str.find_first_of(delimiters, start);
    }

    return words;
}

int main() {
    std::ifstream infile("input.txt");
    if (!infile) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string phrase = buffer.str();

    std::string delimiters = " ,?!.";
    std::vector<std::string> words = split_words(phrase, delimiters);

    std::map<std::string, int> word_count;
    for (const std::string& word : words) {
        std::string lower_word = lower(word);
        if (!lower_word.empty()) {
            word_count[lower_word]++;
        }
    }

    auto comparator = [](const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) {
        if (left.second != right.second) {
            return left.second < right.second;
        }
        return left.first > right.first;
    };

    using WordCountPair = std::pair<std::string, int>;
    using Comparator = decltype(comparator);
    using PriorityQueue = std::priority_queue<WordCountPair, std::vector<WordCountPair>, Comparator>;

    PriorityQueue pq(word_count.begin(), word_count.end(), comparator);

    while (!pq.empty()) {
        const auto& [word, count] = pq.top();
        std::cout << word << " => " << count << std::endl;
        pq.pop();
    }

    return 0;
}
