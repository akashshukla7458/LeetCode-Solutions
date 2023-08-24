class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> ans;
        int i = 0;

        while (i < words.size()) {
            std::vector<std::string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            ans.push_back(createLine(currentLine, i, words, maxWidth));
        }

        return ans;
    }

private:
    std::vector<std::string> getWords(int i, std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> currentLine;
        int currLength = 0;

        while (i < words.size() && currLength + words[i].length() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].length() + 1;
            i++;
        }

        return currentLine;
    }

    std::string createLine(std::vector<std::string>& line, int i, std::vector<std::string>& words, int maxWidth) {
        int baseLength = -1;
        for (const std::string& word : line) {
            baseLength += word.length() + 1;
        }

        int extraSpaces = maxWidth - baseLength;

        if (line.size() == 1 || i == words.size()) {
            std::string result = line[0];
            for (int j = 1; j < line.size(); j++) {
                result += " " + line[j];
            }
            result += std::string(extraSpaces, ' ');
            return result;
        }

        int wordCount = line.size() - 1;
        int spacesPerWord = extraSpaces / wordCount;
        int needsExtraSpace = extraSpaces % wordCount;

        for (int j = 0; j < needsExtraSpace; j++) {
            line[j] += " ";
        }

        for (int j = 0; j < wordCount; j++) {
            line[j] += std::string(spacesPerWord, ' ');
        }

        std::string result = line[0];
        for (int j = 1; j < line.size(); j++) {
            result += " " + line[j];
        }

        return result;
    }
};
