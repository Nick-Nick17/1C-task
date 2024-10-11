#include "../lib/bor.h"

#include <cassert>

namespace tests {
    
struct Request {
    std::string help;
    std::string answer;
};

void makeTest(
    Bor& bor,
    std::vector<std::pair<std::string, int>> to_write,
    std::vector<Request> requests
) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < to_write[i].second; ++j) {
            bor.writeWord(to_write[i].first);
        }
    }

    for (const auto& request : requests) {
        assert(bor.help(request.help) == request.answer);
    }
            
}


void testingSolution() {

    {
        Bor bor;
            
        std::vector<std::pair<std::string, int>> to_write = {
            {"ten", 10},
            {"tenet", 5},
            {"tene", 3}, 
            {"tengen", 2},
            {"total", 1}
        };


        std::vector<Request> requests = {
            {"t", "ten"}, {"tene", "tenet"}
        };

        makeTest(bor, to_write, requests);
        std::cout << "All tests passed!";
    }
}

} // namespace tests

int main() {
    tests::testingSolution();
    return 0;
}