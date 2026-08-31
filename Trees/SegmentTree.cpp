#include<iostream>
#include<vector>
using namespace std;

// Segment Tree class for range sum queries and point updates
class segment_tree {
private:
    vector<int> tree;

public:
    // Constructor: initialize segment tree of size 4 * n
    segment_tree(int n) {
        tree.resize(4 * n);
    }

    // Build the segment tree
    void create_segtree(int idx, int start, int end, vector<int>& a) {
        if (start == end) {
            // Leaf node stores the element itself
            tree[idx] = a[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build left and right children
            create_segtree(2 * idx + 1, start, mid, a);
            create_segtree(2 * idx + 2, mid + 1, end, a);
            // Internal node stores the sum of both children
            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }
    }

    // Query sum in the range [ql, qr]
    int rangesum(int ql, int qr, int start, int end, int idx) {
        // No overlap
        if (ql > end || qr < start) return 0;

        // Complete overlap
        if (ql <= start && qr >= end) return tree[idx];

        // Partial overlap
        int mid = (start + end) / 2;
        int left = rangesum(ql, qr, start, mid, 2 * idx + 1);
        int right = rangesum(ql, qr, mid + 1, end, 2 * idx + 2);
        return left + right;
    }

    // Update value at index k to val
    void update(int k, int val, int start, int end, int idx) {
        if (start == end) {
            // Leaf node: directly update
            tree[idx] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (k <= mid) {
            // Update left child
            update(k, val, start, mid, 2 * idx + 1);
        } else {
            // Update right child
            update(k, val, mid + 1, end, 2 * idx + 2);
        }

        // Recalculate current node after update
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
};

int main() {
    int n;
    //cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    //cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Create segment tree object
    segment_tree segtree(n);

    // Build segment tree from array 'a'
    segtree.create_segtree(0, 0, n - 1, a);

    // Example range sum query
    int l, r;
    //cout << "Enter range to query sum (0-based indexing): ";
    cin >> l >> r;
    int sum = segtree.rangesum(l, r, 0, n - 1, 0);
    //cout << "Range sum [" << l << ", " << r << "] = " << sum << endl;
    cout << sum << endl;
    // Example point update
    int idx, new_val;
    //cout << "Enter index and new value to update: ";
    cin >> idx >> new_val;
    segtree.update(idx, new_val, 0, n - 1, 0);

    // Query again after update
    sum = segtree.rangesum(l, r, 0, n - 1, 0);
    //cout << "Range sum after update [" << l << ", " << r << "] = " << sum << endl;
     cout << sum << endl;

    return 0;
}
