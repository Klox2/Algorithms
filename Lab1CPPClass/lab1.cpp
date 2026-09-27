#include <fstream>
#include <iostream>

#include "array.h"

Array* array_create_and_read(std::ifstream& inFile) {
    int n;
    if (!(inFile >> n)) {
        return nullptr;
    }

    Array* arr = new Array(n);

    for (int i = 0; i < n; ++i) {
        int x;
        inFile >> x;
        arr->set(i, x);
    }

    return arr;
}

void task1(Array* arr) {
    long long sum = 0;
    for (size_t i = 0; i < arr->size(); ++i) {
        sum += arr->get(i);
    }

    int cnt = 0;
    for (size_t i = 0; i < arr->size(); ++i) {
        if (arr->get(i) > sum) {
            ++cnt;
        }
    }
    std::cout << cnt << "\n";

    bool first = true;
    for (size_t i = 0; i < arr->size(); ++i) {
        if (arr->get(i) > sum) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
    }
}

void task2(Array* arr, int shift) {
    int n = static_cast<int>(arr->size());

    if (shift > 0) {
        if (shift > n) {
            shift = n;
        }
        for (int i = n - 1; i >= shift; --i) {
            arr->set(i, arr->get(i - shift));
        }
        for (int i = 0; i < shift; ++i) {
            arr->set(i, 0);
        }
    } else if (shift < 0) {
        int k = -shift;
        if (k > n) {
            k = n;
        }
        for (int i = 0; i < n - k; ++i) {
            arr->set(i, arr->get(i + k));
        }
        for (int i = n - k; i < n; ++i) {
            arr->set(i, 0);
        }
    }

    for (size_t i = 0; i < arr->size(); ++i) {
        std::cout << arr->get(i) << (i + 1 == arr->size() ? '\n' : ' ');
    }
}

int main(int argc, char** argv) {
    const char* filename = (argc > 1) ? argv[1] : "input.txt";

    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file " << filename << "\n";
        return 1;
    }

    int task;
    while (inFile >> task) {
        Array* arr = array_create_and_read(inFile);

        if (task == 1) {
            task1(arr);
        } else if (task == 2) {
            int shift;
            inFile >> shift;
            task2(arr, shift);
        }

        delete arr;
    }

    return 0;
}