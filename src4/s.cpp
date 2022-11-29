#include "myutils.h"
#include "crypto.h"

using namespace std;

int main()
{
    int nsfd;
    int sfd = CreateServer(8080);
    if ((nsfd = accept(sfd, NULL, NULL)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    cout << "Client connected... " << endl;

    int q;
    cout << "Enter q:";
    cin >> q;
    int alpha = primitiveRoot(q);

    // generating keys
    int xa = randomNBetween(1, q);
    int ya = BpowPmodN(alpha, xa, q);

    // exchanging public key
    WriteFD(nsfd, IntToString(ya));
    int yb = StringToInt(ReadFD(nsfd));

    int k = BpowPmodN(yb, xa, q);

    cout << "Shared Key:" << k << endl;

    close(nsfd);
    close(sfd);
    return 0;
}
