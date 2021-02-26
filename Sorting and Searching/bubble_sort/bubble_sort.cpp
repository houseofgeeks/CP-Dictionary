#include <bits/stdc++.h>
using namespace std;
// parameters are the list and the acutal size 
void bubble_sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    // example
    int list[] = {3, 9, 5, -1, 0};

    int size = 5;
    // the bubble_sort will sorting the array
    bubble_sort(list, size);

    // Show each item of list
    for (int i = 0; i < size; i++) {
        cout <<  list[i] << '\n';
    }

    return 0;
}