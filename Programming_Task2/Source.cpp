#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

const int w = 3;
const int k = 4;
const int x1 = -1;
const int x2 = 1;
const int d = -2;
const int g = 4;

void wczytaj(double X[][k], double x1, double x2)
{
    srand(time(0));
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
            X[i][j] = x1 + (x2 - x1) * rand() / double(RAND_MAX);
    }
}

void precyzja(double X[][k], int P)
{
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
            cout << fixed << setprecision(P) << setw(5) << X[i][j] << '\t';
        cout << endl;
    }
}

int odwraca(double X[][k], char typ, int L)
{
    double temp;
    int licz_w = 0;

    for (int i = 0; i < w; i++)
    {
        if (X[i][0] < 0 && typ == 'a')
        {
            for (int j = 0; j < k / 2; j++)
            {
                temp = X[i][j];
                X[i][j] = X[i][k - 1 - j];
                X[i][k - 1 - j] = temp;
            }
            licz_w++;
        }
        else if (X[i][0] < L && typ == 'b')
        {
            for (int j = 0; j < k / 2; j++)
            {
                temp = X[i][j];
                X[i][j] = X[i][k - 1 - j];
                X[i][k - 1 - j] = temp;
            }
            licz_w++;
        }
    }
    return licz_w;
}

int main()
{
    double A[w][k], B[w][k];
    char zn;
    int L, ufo1, ufo2;

    cout << "Tablica 1." << endl;
    cout << endl;
    wczytaj(A, x1, x2);
    precyzja(A, 1);
    cout << endl;
    ufo1 = odwraca(A, 'a', 0);
    precyzja(A, 1);

    cout << endl;
    cout << "Tablica 2." << endl;
    cout << "Wprowadz liczbe calkowita do odwracania: ";
    cin >> L;
    cout << endl;

    wczytaj(B, d, g);
    precyzja(B, 2);
    cout << endl;
    ufo2 = odwraca(B, 'b', L);
    precyzja(B, 2);

    cout << endl;
    if (ufo1 == ufo2)
    {
        cout << "W obu tablicach odwrocono tyle samo wierszy." << endl;
    }
    else if (ufo1 > ufo2)
    {
        cout << "W tablicy pierwszej odwrocono wiecej wierszy." << endl;
    }
    else
    {
        cout << "W tablicy drugiej odwrocono wiecej wierszy." << endl;
    }
    cout << endl;

    system("PAUSE");
    return 0;
}
