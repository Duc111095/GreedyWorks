#include <stdio.h>

int n;
int d[7];
int p[7];
int r[7];
int worked[6];
int kmax;

void solution() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += r[i];
    } 
    printf("%d", sum);
}

int max_index(int arr[]) {
    int max = 0, k = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            k = i;
        }
    }
    return k;
}

int empty(int arr[]) {
    for (int i = 0; i <= n; i++) {
        if (arr[i] != 0) return 1;
    }
    return 0;
}

void Greedy() {
    while(empty(p) == 1) {
        kmax = max_index(p);
        if (r[d[kmax]] == 0) {
            r[d[kmax]] = p[kmax];
            worked[d[kmax]] = kmax;
        } else {
            for (int j = d[kmax]; j >= 0; j --){
                if (r[j] == 0) {
                    r[j] = p[kmax];
                    worked[j] = kmax;
                    break;
                }
            }
        }
        p[kmax] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        scanf("%d", &p[i]);
    }
    Greedy();
    solution();
    return 0;
}
