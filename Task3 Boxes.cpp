#include <iostream>
#include <vector>

using namespace std;

void bubble_sizes_sort(vector<vector<int>>& x) {
    for (int i = 0; i < x.size() - 1; i++) {
        for (int j = 0; j < x.size() - 1 - i; j++) {
            if (x[j][0] < x[j + 1][0] && x[j][1] < x[j + 1][1]) {
                swap(x[j], x[j + 1]);
            }
        }
    }
}

int count_box_nesting(vector<vector<int>>& x) {
    int count = 0;
    for (int i = 0; i < x.size() - 1; i++) {
        if (x[i][0] > x[i + 1][0] && x[i][1] > x[i + 1][1]) {
            count++;
        }
    }
    return count;
}

int main() {
    //Test1
    vector<vector<int>> x = {{3, 4}, {1, 2}, {5, 6}};
    bubble_sizes_sort(x);
    int count = count_box_nesting(x);
    cout << "Test 1 result: "<< count << endl;
    
    //Test2
    x = {{6, 6}, {6, 6}, {7, 7}};
    bubble_sizes_sort(x);
    count = count_box_nesting(x);
    cout << "Test 2 result: " << count << endl;
    return 0;
    
}
