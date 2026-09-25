#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
private:
    // Parses a comma-separated list of terms (Union)
    set<string> parseExpr(const string& s, int& pos) {
        set<string> res;
        
        // Read the first term
        set<string> term = parseTerm(s, pos);
        res.insert(term.begin(), term.end());
        
        // If there are more terms separated by commas, parse and union them
        while (pos < s.length() && s[pos] == ',') {
            pos++; // Skip the comma
            set<string> nextTerm = parseTerm(s, pos);
            res.insert(nextTerm.begin(), nextTerm.end());
        }
        
        return res;
    }
    
    // Parses sequentially concatenated factors
    set<string> parseTerm(const string& s, int& pos) {
        set<string> res = {""}; // Start with an empty string for concatenation
        
        // Keep parsing factors as long as we don't hit a union ',' or a closing bracket '}'
        while (pos < s.length() && s[pos] != ',' && s[pos] != '}') {
            set<string> factor = parseFactor(s, pos);
            set<string> nextRes;
            
            // Cartesian product (concatenation) of current results and the new factor
            for (const string& a : res) {
                for (const string& b : factor) {
                    nextRes.insert(a + b);
                }
            }
            res = move(nextRes);
        }
        
        return res;
    }
    
    // Parses a single block: either a {...} expression or a sequence of letters
    set<string> parseFactor(const string& s, int& pos) {
        if (s[pos] == '{') {
            pos++; // Skip '{'
            set<string> res = parseExpr(s, pos);
            pos++; // Skip '}'
            return res;
        } else {
            string t = "";
            // Read consecutive lowercase letters as a single string
            while (pos < s.length() && isalpha(s[pos])) {
                t += s[pos++];
            }
            return {t};
        }
    }
    
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> res = parseExpr(expression, pos);
        // The set automatically ensures strings are unique and in lexicographical order
        return vector<string>(res.begin(), res.end());
    }
};