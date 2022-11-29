#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int n;
char f[200], g[200], r[200];


char* addition(char f[], char g[], int n) {
    char* res = malloc(n);
    for (int i = 0; i < n; i++) {
        if (f[i] == g[i]) {
            res[i] = '0';
        }
        else {
            res[i] = '1';
        }
    }
    return res;
}

void additionToSameArray(char *f, char *g, int n) {
    for (int i = 0; i < n; i++) {
        if (f[i] == g[i])
            f[i] = '0';
        else
            f[i] = '1';
    }
}


char* subtract(char f[], char g[], int n) {
    char *res = addition(f, g, n);
    return res;
}

void leftshift(char* f) {
    for (int i = 0; i < n - 1; i++) {
        f[i] = f[i + 1];
    }
    f[n - 1] = '0';
}

char* multiplyPolynomials(char f[], char g[], char r[], int n) {
    char* res = malloc(n);
    for (int i = 0; i < n; i++)
        res[i] = '0';
    
    char residue[n], temp[n];
    for (int i = 0; i < n; i++) {
        residue[i] = r[i + 1];
        temp[i] = f[i];
    }



    for (int i = 1; i < n; i++) {
        int flagAdd = 0;
        if (temp[0] == '1') {
            leftshift(temp);
            additionToSameArray(temp, residue, n);
        }
        else
            leftshift(temp);
        if (g[n - i - 1] == '1') {
            additionToSameArray(res, temp, n);
        }
    }

    if (g[n - 1] == '1')
        additionToSameArray(res, f, n);

    return res;
}

int findRange(int n) {
    int val = 1;
    for (int i = 0; i < n; i++)
        val *= 2;
    return val;
}

char* decimalToBinaryArray(int nums, int n) {
    char* res = malloc(n);
    for (int i = 0; i < n; i++)
        res[i] = '0';
    int index = n - 1;
    while (nums) {
        if (nums % 2 == 1)
            res[index--] = '1';
        else
            res[index--] = '0';
        nums /= 2;
    }
    while (index >= 0)
        res[index--] = '0';
    return res;
}

void printArray(char* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

char* findInverse(char g[], char r[], int n) {
    char* inv = malloc(n);
    for (int i = 0; i < n; i++)
        inv[i] = '0';
    int range = findRange(n);
    for (int i = 1; i <= range; i++) {
        char* temp = decimalToBinaryArray(i, n);
        char* tempRes = multiplyPolynomials(g, temp, r, n);

        int j = 0;
        for (j = 0; j < n; j++) {
            if ((j < n - 1) && (tempRes[j] == '0'))
                continue;
            if (j == n -1 && tempRes[j] == '1')
                continue;
            break;
        }
        if (j == n) {
            for (int i = 0; i < n; i++)
                inv[i] = temp[i];
            break;
        }
    }
    return inv;
}

char* division(char f[], char g[], char r[], int n) {
    char* res = malloc(n);
    for (int i = 0; i < n; i++)
        res[i] = 0;

    // finding inverse
    char* inv = findInverse(g, r, n);

    res = multiplyPolynomials(f, inv, r, n);

    return res;
}


int main (int argc, char* argv[]) {

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter f(x) in binary form: ");
    scanf("%s", f);
    printf("Enter g(x) in binary form: ");
    scanf("%s", g);
    printf("Enter the irreducible polynomial of degree %d in binary form: ", n);
    scanf("%s", r);


    printf("Addition result: %s\n", addition(f, g, n));
    printf("Subtraction result: %s\n", subtract(f, g, n));

    printf("Multiplication result: %s\n", multiplyPolynomials(f, g, r, n));
    
    printf("Division result: %s\n", division(f, g, r, n));

    return 0;
}