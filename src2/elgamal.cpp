#include "utility.h"

int main()
{
    int q;
    cout << "Enter q: ";
    cin >> q;
    int alpha = primitiveRoot(q);

    int xa = randomNBetween(1, q);
    int xb = randomNBetween(1, q);
    int ya = BpowPmodN(alpha, xa, q);
    int yb = BpowPmodN(alpha, xb, q);

    int M;
    cout << "Enter plain text, M: ";
    cin >> M;

    int k = randomNBetween(1, q);
    int K = BpowPmodN(yb, k, q);
    int c1 = BpowPmodN(alpha, k, q);
    int c2 = (K * M) % q;

    printf("Cipher Text: (%d, %d)\n", c1, c2);

    int KB = BpowPmodN(c1, xb, q);
    int MB = (c2 * findMI(KB, q)) % q;

    printf("Plain Text: %d\n", MB);
}