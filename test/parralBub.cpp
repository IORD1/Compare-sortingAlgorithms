#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void bubble_sort(std::vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::lock_guard<std::mutex> lock(mtx);
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void parallel_bubble_sort(std::vector<int>& arr, int num_threads) {
    std::vector<std::thread> threads;
    int chunk_size = arr.size() / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i < num_threads - 1) ? (start + chunk_size) : arr.size();
        threads.emplace_back(bubble_sort, std::ref(arr), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 1, 2, 7, 4, 6};
    int num_threads = 4;

    parallel_bubble_sort(arr, num_threads);

    std::cout << "Sorted array:";
    for (int num : arr) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
