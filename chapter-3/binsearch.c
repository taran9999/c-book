#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {

}

//find x in v[0] to v[n - 1] using binary search
int binsearch(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(x < v[mid]) {
            high = mid - 1;
        } else if(x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//slight modification of binsearch which reduces the number of tests inside the loop
int binsearch2(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid]) {
        if(x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if(x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}