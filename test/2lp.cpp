#include <iostream>
#include <vector>
#include <ctime>
#include <omp.h>

using namespace std;

void bubble(vector<int>&, int);
void llbubble(vector<int>&, int);
void swap(int &, int &);

void llbubble(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        int first = i % 2;

#pragma omp parallel for shared(a, first)
        for (int j = first; j < n - 1; j += 2) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubble(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        int first = i % 2;
        for (int j = first; j < n - 1; j += 2) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void mergesort(vector<int>& a, int i, int j);
void merge(vector<int>& a, int i1, int j1, int i2, int j2);

void mergesort(vector<int>& a, int i, int j) {
    int mid;
    if (i < j) {
        mid = (i + j) / 2;

#pragma omp parallel sections
        {
#pragma omp section
            {
                mergesort(a, i, mid);
            }

#pragma omp section
            {
                mergesort(a, mid + 1, j);
            }
        }

        merge(a, i, mid, mid + 1, j);
    }
}

void merge(vector<int>& a, int i1, int j1, int i2, int j2) {
    vector<int> temp(j2 - i1 + 1);
    int i = i1, j = i2, k = 0;

    while (i <= j1 && j <= j2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= j1) {
        temp[k++] = a[i++];
    }

    while (j <= j2) {
        temp[k++] = a[j++];
    }

    for (i = i1, j = 0; i <= j2; i++, j++) {
        a[i] = temp[j];
    }
}

int main() {
    int n;
    cout << "\nEnter total number of elements: ";
    cin >> n;

    vector<int> a(n), a2(n), m(n);
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        m[i] = rand() % 100;
        a2[i] = rand() % 100;
    }

    double start1 = omp_get_wtime();
    bubble(a, n);
    double end1 = omp_get_wtime();

    double start = omp_get_wtime();
    llbubble(a2, n);
    double end = omp_get_wtime();

    double start3 = omp_get_wtime();
    mergesort(m, 0, n - 1);
    double end3 = omp_get_wtime();

    cout << "---------------------" << endl;
    cout << "Time taken by simple bubble sort is: " << fixed << (end1 - start1) << " seconds" << endl;
    cout << "---------------------" << endl;
    cout << "Time taken by bubble sort in parallel is: " << fixed << (end - start) << " seconds" << endl;
    cout << "---------------------" << endl;
    cout << "Time taken by merge sort is: " << fixed << (end3 - start3) << " seconds" << endl;

    return 0;
}
