#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// Q1: Fractional Knapsack (Greedy)
//////////////////////////////////////////////////////////////
struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

//////////////////////////////////////////////////////////////
// Q2: Quick Sort (Uneven Divide & Conquer)
//////////////////////////////////////////////////////////////
int partitionQS(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionQS(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//////////////////////////////////////////////////////////////
// Q3: Merge Sort (Equal Divide & Conquer)
//////////////////////////////////////////////////////////////
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//////////////////////////////////////////////////////////////
// MAIN FUNCTION
//////////////////////////////////////////////////////////////
int main() {

    ////////////////////// Q1 //////////////////////
    cout << "Q1: Fractional Knapsack\n";
    Item items[] = {{30,5}, {40,10}, {45,15}, {77,22}, {80,20}};
    int W = 50;
    int n1 = sizeof(items)/sizeof(items[0]);

    double maxValue = fractionalKnapsack(W, items, n1);
    cout << "Maximum value that can be obtained = " << maxValue << "\n\n";


    ////////////////////// Q2 //////////////////////
    cout << "Q2: Quick Sort (Uneven Partition)\n";
    int arr1[] = {8,2,5,9,1,4,3,79,90,77};
    int n2 = sizeof(arr1)/sizeof(arr1[0]);

    quickSort(arr1, 0, n2 - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n2; i++)
        cout << arr1[i] << " ";
    cout << "\n\n";


    ////////////////////// Q3 //////////////////////
    cout << "Q3: Merge Sort (Equal Partition)\n";
    int arr2[] = {8,2,5,9,1,4,3,79,90,77};
    int n3 = sizeof(arr2)/sizeof(arr2[0]);

    mergeSort(arr2, 0, n3 - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n3; i++)
        cout << arr2[i] << " ";
    cout << "\n";

    return 0;
}
