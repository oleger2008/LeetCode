ostream &operator<<(ostream &os, const vector<int> &nums) {
    os << '{';
    bool isFirst = true;
    for (const auto n : nums) {
        if (isFirst) {
            os << n;
            isFirst = false;
            continue;
        }
        os << ", "s << n ;
    }
    os << '}';
    return os;
} 

class Solution {
public:
    int minSubArrayLen(const int target, vector<int>& nums) {
        // tests();
        return twoPointersSolution(target, nums);
    }
    

    
private:
    // complexity is O(n^2) - passed
    int myNaiveSolution(const int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int subArrSize = std::numeric_limits<int>::max();
        const int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums.at(j);
                if (sum >= target) {
                    subArrSize = std::min(subArrSize, (j - i + 1));
                    break;
                }
            }
        }
        return (subArrSize == std::numeric_limits<int>::max()) ? 0 : subArrSize;
    }
    
    // complexity is O(n^2) - time limit + useless cashing sums
    int prefixSumsSolution(const int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int subArrSize = std::numeric_limits<int>::max();
        const int size = nums.size();
        vector<int> prefixSums(size, 0);
        prefixSums.front() = nums.front();
        for (int i = 1; i < size; ++i) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                if ((prefixSums.at(j) - prefixSums.at(i) + nums.at(i)) >= target) {
                    subArrSize = std::min(subArrSize, (j - i + 1));
                    break;
                }
            }
        }
        return (subArrSize == std::numeric_limits<int>::max()) ? 0 : subArrSize;
    }
    
    // O(n * log(n)): фишка в том, что префикс суммы образуют неубыв.посл-ть
    int lowerBoundSolution(const int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int subArrSize = std::numeric_limits<int>::max();
        const int size = nums.size();
        vector<int> prefixSums(size + 1, 0);
        for (int i = 1; i <= size; ++i) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= size; ++i) {
            const int toFind = target + prefixSums[i - 1];
            const auto bound = lower_bound(prefixSums.cbegin(), prefixSums.cend(), toFind);
            if (prefixSums.cend() != bound) {
                subArrSize = std::min(subArrSize, static_cast<int>(
                        bound - (prefixSums.begin() + i - 1)));
            }
        }
        return (subArrSize == std::numeric_limits<int>::max()) ? 0 : subArrSize;
    }
    
    // тут как бы мысля про то, что если мы двигаемся по массиву, суммириуем, и
    // когда удовлетворили таргету, то почему бы не попробовать не теряя уже текущую
    // сумму попробовать подвинуть левую границу откуда мы начинали суммировать, как бы
    // проверяя, что до сих пор удовлетворяем таргету и при этом, еще проверяя, можно ли
    // сделать это за меньшее количество элементов.
    int twoPointersSolution(const int target, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int subArrSize = std::numeric_limits<int>::max();
        const int size = nums.size();
        int left = 0;
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            while (sum >= target) {
                subArrSize = std::min(subArrSize, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (subArrSize == std::numeric_limits<int>::max()) ? 0 : subArrSize;
    }
    
    void tests() {
        tryTest(7, {2, 3, 1, 2, 4, 3}, 2);
        tryTest(11, {1, 1, 1}, 0);
        tryTest(4, {1, 4, 4}, 1);
        tryTest(11, {1, 2, 3, 4, 5}, 3);
        tryTest(6, {10, 2, 3}, 1);
    }
    
    void tryTest(const int target, const vector<int>& nums, const int expected) {
        vector<int> v(nums);
        const int solution = prefixSumsSolution(target, v);
        const bool result = (solution == expected);
        if (!result) {
            cerr << "target = "s << target << "; nums = " << nums << ';' << endl;
            cerr << "solution = "s << solution << "; expected = "s << expected << endl;
        }
        assert(result);
    }
};