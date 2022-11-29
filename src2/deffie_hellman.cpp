#include "utility.h"

int main()
{
    int q;
    cout << "Enter q:";
    cin >> q;
    int alpha = primitiveRoot(q);

    int xa = randomNBetween(1, q);
    int xb = randomNBetween(1, q);
    int ya = BpowPmodN(alpha, xa, q);
    int yb = BpowPmodN(alpha, xb, q);

    int sa = BpowPmodN(yb, xa, q);
    int ba = BpowPmodN(ya, xb, q);

    cout << "A has secret:" << sa << endl
         << "B has secret:" << ba << endl;
}