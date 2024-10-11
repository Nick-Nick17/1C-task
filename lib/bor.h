#include <array>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>

class Bor {
  private:

    const static size_t dictionary_size_ = 32;

    struct Node {
        char symbol;
        int32_t parent = -1;

        uint32_t max_in_subtree = 0;
        int32_t max_in_subtree_idx = -1;
        
        uint32_t entry = 0;

        std::array<int32_t, dictionary_size_> to;

        Node() {
            to.fill(-1);
        }

        Node(char symbol, uint32_t parent) : symbol(symbol), parent(parent) {
            to.fill(-1);
        }
    };

    inline int32_t symbolInInt(char c) {
        return c - 'a';
    }


    std::vector<Node> data;
    uint32_t pointer;
    std::string help_;

  public:

    Bor() : pointer(0) {
        data.emplace_back();
    }

    inline void clean() {
        pointer = 0;
        help_ = "";
    }
    
    std::string findMostPopular();

    std::string addWord(const std::string& str);

    uint32_t goDownOnWord(const std::string& str, bool adding, int32_t start);

    std::string help(const std::string& str);

    void writeWord(const std::string& str);   
};