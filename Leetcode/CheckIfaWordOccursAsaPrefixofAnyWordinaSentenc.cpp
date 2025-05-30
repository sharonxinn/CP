class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;

        // Basic methods for Stringstream are:

        // clear()- To clear the stream.
        // str()- To get and set string object whose content is present in the stream. 
        // operator <<- Add a string to the stringstream object. 
        // operator >>- Read something from the stringstream object.
        for (int i =1; ss >> word ; i++) {
            if (word.find(searchWord) == 0) {
                return i;
            }
        }

        return -1;
    }
};