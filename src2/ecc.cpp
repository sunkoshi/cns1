#include "utility.h"
using namespace std;

struct Point
{
    int x;
    int y;
};

Point Add(Point P, Point Q, int p, int a)
{
    bool PeQ = (P.x == Q.x && P.y == Q.y);
    int lambda;
    if (PeQ)
    {
        int q = findMI(2 * P.y, p);
        lambda = ((3 * P.x * P.x + a) * q) % p;
    }
    else
    {
        int q = findMI(Q.x - P.x, p);
        lambda = ((Q.y - P.y) * q) % p;
    }
    int lambda_sq = lambda * lambda;
    Point R;
    R.x = (lambda_sq - P.x - Q.x) % p;
    R.y = (lambda * (P.x - R.x) - P.y) % p;
    return R;
}

Point ScalarMultiplication(Point P, int n, int p, int a)
{
    Point R = P;
    for (int i = 0; i < n; i++)
    {
        R = Add(R, P, p, a);
    }
    return R;
}

int main()
{
    int p, a, b;
    cout << "Enter p, a, b: ";
    cin >> p >> a >> b;
    Point G;
    cout << "Enter Gx, Gy: ";
    cin >> G.x;
    cin >> G.y;
    cout << "Enter k: ";
    int k;
    cin >> k;
    cout << "Enter Px, Py: ";
    Point Pm;
    cin >> Pm.x;
    cin >> Pm.y;

    pair<Point, Point> Cm;
    Cm.first = ScalarMultiplication(G, k, p, a);
    Cm.second = Add(Pm, ScalarMultiplication())
}