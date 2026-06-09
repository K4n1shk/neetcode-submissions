class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(!words.count(endWord)){
            return 0;
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        words.erase(beginWord);

        while(!q.empty()){
            auto [word,steps] = q.front();
            q.pop();
            
            if(word == endWord){
                return steps;
            }

            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    if(words.contains(temp)){
                        q.push({temp,steps+1});
                        words.erase(temp);
                    }
                }
            }

        }
        return 0;

    }
};
