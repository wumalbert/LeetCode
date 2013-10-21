class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (words.empty()) return words;
        vector<string> ret;
        for (vector<string>::iterator current = words.begin(); current != words.end(); ) {
            vector<string>::iterator last = current;
            int line_length = current->length(), number_words = 1;
            for (++current; current != words.end() && line_length+current->length()+1 <= L; ++current, ++number_words)
                line_length += current->length() + 1;
            if (current != words.end()) {
                if (number_words == 1) {
                    ret.push_back(*last + string(L-line_length, ' '));
                } else {
                    int t = (L-line_length)/(number_words-1) + 1;
                    string blank_left(t + 1, ' '), blank_right(t, ' ');
                    t = (L-line_length)%(number_words-1);
                    string line(*last);
                    for (++last; last != current && t > 0; ++last, --t)
                        line.append(blank_left).append(*last);
                    for (; last != current; ++last)
                        line.append(blank_right).append(*last);
                    ret.push_back(line);
                }
            } else {
                string line(*last);
                for (++last; last != current; ++last)
                    line.append(" ").append(*last);
                line.append(L-line_length, ' ');
                ret.push_back(line);
            }
        }
        return ret;
    }
};