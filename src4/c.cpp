#include "myutils.h"
#include "crypto.h"

using namespace std;

int main()
{
    int fd = ConnectToServer(8080);

    int q;
    cout << "Enter q:";
    cin >> q;
    int alpha = primitiveRoot(q);

    // generating keys
    int xb = randomNBetween(1, q);
    int yb = BpowPmodN(alpha, xb, q);

    // exchanging public key

    int ya = StringToInt(ReadFD(fd));
    WriteFD(fd, IntToString(yb));

    int k = BpowPmodN(ya, xb, q);

    cout << "Shared Key:" << k << endl;

    close(fd);
    return 0;
}
