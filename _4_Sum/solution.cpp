#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

using Four = multiset<int64_t>;
using Fours = set<Four>;
using Nums = vector<int64_t>;
using Pair = std::pair<size_t, size_t>;
using SumToPairOfInx = unordered_map<int64_t, vector<Pair>>;

SumToPairOfInx GetSumPairs(const Nums &nums) {
    SumToPairOfInx result;
    const size_t size = nums.size();
    for (size_t i = 0u; i < size; ++i) {
        for (size_t j = i + 1u; j < size; ++j) {
            result[nums.at(i) + nums.at(j)].emplace_back(i, j);
        }
    }
    return result;
}

Fours FourSum(const Nums &nums, const int64_t target) {
    SumToPairOfInx mp(move(GetSumPairs(nums)));

    Fours result;
    const size_t size = nums.size();
    for (size_t i = 0u; i + 1u < size; ++i) {
        for (size_t j = i + 1u; j < size; ++j) {
            const int64_t sum = nums.at(i) + nums.at(j);
            const auto iter = mp.find(target - sum);
            if (mp.end() != iter) {
                const auto &vp = iter->second;
                for (const auto &p : vp) {
                    if ((p.first != i) && (p.second != j) &&
                            (p.first != j) && (p.second != i))
                        result.insert(Four{nums.at(i), nums.at(j),
                            nums.at(p.first), nums.at(p.second)});
                }
            }
        }
    }

    return result;
}

Nums ReadInput(istream &is, const size_t size) {
    Nums result;
    result.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        int64_t n;
        is >> n;
        result.push_back(n);
    }
    return result;
}

Fours Solution(istream &is) {
    size_t n;
    is >> n;

    int64_t s;
    is >> s;

    Nums nums(move(ReadInput(is, n)));
    return FourSum(nums, s);
}

ostream &operator<<(ostream &os, const Fours &ss) {
    os << ss.size() << '\n';
    for (const auto &s : ss) {
        for (const auto i : s) {
            os << i << " ";
        }
        os << '\n';
    }
    return os;
}

int main() {
    cout << Solution(cin) << endl;
    return 0;
}
