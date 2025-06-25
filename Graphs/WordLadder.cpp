class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            int n = word.size();
            for(int i = 0 ; i < n ; i++){
                char org = word[i];
                for(int j = 'a' ; j <= 'z' ; j++){
                    word[i] = j;
                    if(st.find(word)!= st.end()){
                        q.push({word, steps + 1});
                        st.erase(word);
                        if(word == endWord) return steps + 1;
                    }
                }
                word[i] = org;
            }
        }
        return 0;

    }
};
