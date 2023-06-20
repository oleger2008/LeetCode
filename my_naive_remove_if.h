// l
// 1 2 3 0 0 4 2 0 0 0 0 3 0 7
//       l   r
// 1 2 3 0 0 4 2 0 0 0 0 3 0 7
//       l   r
// 1 2 3 4 0 0 2 0 0 0 0 3 0 7
//         l   r
// 1 2 3 4 0 0 2 0 0 0 0 3 0 7
//         l   r
// 1 2 3 4 2 0 0 0 0 0 0 3 0 7
//           l           r
// 1 2 3 4 2 0 0 0 0 0 0 3 0 7
//           l           r
// 1 2 3 4 2 3 0 0 0 0 0 0 0 7
//             l             r
// 1 2 3 4 2 3 0 0 0 0 0 0 0 7
//             l             r
// 1 2 3 4 2 3 7 0 0 0 0 0 0 0

// corner: empty, no keys, all keys

// in all cases key = 0
// case 1
// 0 1
// result
// 0 1

// case 2
// 0 0
// result
// 0 0

// case 3
// 1 1
// result
// 1 1

// case 4
// 0 0 1 2 0 3
// result
// 0 0 0 1 2 3

void CustomRemoveIf(vector<int> &v, int key) {
    const auto size = v.size();
    size_t left = 0u;
    while (left != size && v[left] != key) {
        ++left;
    }
    if (left == size) {
        return;
    }

    size_t right = left;
    while (right != size && v[right] == key) {
        ++right;
    }
    if (right == size) {
        return;
    }

    while (right != size) {
        std::swap(v[left], v[right]);
        if (v[left] != key) {
            while (left != size && v[left] != key) {
                ++left;
            }
            if (left == size) {
                return;
            }
        }
        if (v[right] == key) {
            while (right != size && v[right] == key) {
                ++right;
            }
            if (right == size) {
                return;
            }
        }
    }
}