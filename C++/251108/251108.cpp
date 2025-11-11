
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

void CreateTextFile();
int ReadTextFile();
int UgynokMain();
int Feladat2Main();
int KeziMain();

int main()
{
    KeziMain();
}

void CreateTextFile()
{
    ofstream uj("gyak.txt");
    uj << "Ez egy uj allomany\nmost csinaltam\n";
    uj.put('A'); //Egy karaktert tesz be
    uj.close();
}

int ReadTextFile()
{
    char szoveg[80];
    char bet;
    ifstream be("gyak.txt");
    if (be.fail()) { cout << "Hiba!"; system("pause"); exit(1); }

    while (!be.eof())
    {
        be.get(bet); //Karakterenkénti beolvasás. Az utolsó karakter meg lesz duplázva
        cout << bet;

        //be >> szoveg; //szóközig olvas
        //cout << szoveg << " ";
        
        //be.getline(szoveg, 80); //soronként olvas
        //cout << szoveg << endl;
    }
    be.close();
    return 0;
}
    

