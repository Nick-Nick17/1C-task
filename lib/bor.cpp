#include "bor.h"

std::string Bor::findMostPopular() {
    if (data[pointer].max_in_subtree_idx == -1) {
        return "";
    }
    auto node = pointer;
    std::string res_to_add;
    while (data[node].entry < data[node].max_in_subtree) {
        node = data[node].to[data[node].max_in_subtree_idx];
        res_to_add += data[node].symbol;
    }
    return res_to_add;
}

std::string Bor::addWord(const std::string& str) {
    help_ += str;
    try {
        pointer = goDownOnWord(str, false, pointer);
    } catch (const std::string& error) {
        return error;
    }

    auto res = findMostPopular();
    if (res == "" && data[pointer].entry == 0) {
        return "Oh no, impossible to find word with this preffics: " + help_;
    }
    return help_ + res;
}

uint32_t Bor::goDownOnWord(const std::string& str, bool adding, int32_t start = 0) {
    int32_t prev_node = start;
    for (size_t i = 0; i < str.size(); ++i) {
        auto now_node = data[prev_node].to[symbolInInt(str[i])];
        
        if (now_node == -1) {
            if (!adding) {
                throw std::string("No this word available");
            }
            data[prev_node].to[symbolInInt(str[i])] = data.size();
            now_node = data.size();
            data.emplace_back(str[i], prev_node);
        }
        prev_node = now_node;
    }

    return prev_node;
}

std::string Bor::help(const std::string& str) {
    clean();
    help_ = str;
    
    try {
        pointer = goDownOnWord(help_, false);
    } catch (const std::string& error) {
        clean();
        return error;
    }

    auto res = findMostPopular();
    return help_ + res;
}

void Bor::writeWord(const std::string& str) {
    uint32_t node = goDownOnWord(str, true);
    data[node].entry += 1;

    uint32_t new_max_entry = std::max(data[node].entry,
                                        data[node].max_in_subtree);
    auto parent = data[node].parent;
    
    while (parent != -1 && data[parent].max_in_subtree < new_max_entry) {
        data[parent].max_in_subtree_idx = symbolInInt(data[node].symbol);
        data[parent].max_in_subtree = new_max_entry;
        
        node = parent;
        parent = data[parent].parent;
    }
}