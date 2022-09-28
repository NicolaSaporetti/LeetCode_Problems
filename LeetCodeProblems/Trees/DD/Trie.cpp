#include <array>

class Trie {
    public:
        array<Trie*> ch(26);
        int visited = 0;
};