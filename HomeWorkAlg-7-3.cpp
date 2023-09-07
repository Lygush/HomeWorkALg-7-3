#include <iostream>
#include <fstream>
#include <vector>

bool serch(std::vector<int>& vector, int numb) {
    for (int i{}; i < vector.size(); ++i) {
        if (vector[i] == numb) {
            return true;
        }
    }
    return false;
}

bool dfs(int** matrix, int i, int size, std::vector<int>& result, int& prev) {
    for (int j{}; j < size; ++j) {
        if (matrix[i][j] != 0) {
            if (serch(result, j)) {
                if (prev != j) {
                    return true;
                }
            }
            else {
                result.push_back(j);
                prev = j;
                //if (result.size() == size - 1) {
                //    return false;
               // }
            }
        }
    }
    return false;
}

int main() {
    std::fstream f_in("input.txt");
    int size{};
    if (f_in.is_open()) {
        f_in >> size;
        int** matrix = new int*[size];
        for (int i{}; i < size; ++i) {
            matrix[i] = new int[size];
        }
        for (int i{}; i < size; ++i) {
            for (int j{}; j < size; ++j) {
                f_in >> matrix[i][j];
            }
        }
        std::vector<int> result;
        bool cycle{};
        int prev{};
        for (int i{}; i < size; ++i) {
            for (int j{}; j < size; ++j) {
               if (matrix[i][j] != 0) {
                cycle = dfs(matrix, i, size, result, prev);
               }
            }
        }
        std::cout << ((cycle) ? "Cycle!" : "No cycle!");
        for (int i{}; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    f_in.close();
}