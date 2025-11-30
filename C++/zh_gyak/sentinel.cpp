#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sentinel() {
    // Példa bemenetek (már rendezve)
    vector<string> NEM = { "Anna", "Bela", "Erika", "Jozsef" };
    vector<string> ANG = { "Alan", "Ben", "Eva", "John" };

    int N = NEM.size();
    int M = ANG.size();

    // Sentinel értékek hozzáfûzése
    NEM.push_back("ZZZZ");
    ANG.push_back("ZZZZ");

    vector<string> NYELV;  // kimeneti tömb

    int i = 0, j = 0;

    // Amíg az egyik lista nem fogy el (a sentinel miatt ez biztonságos)
    while (i < N + 1 || j < M + 1) {
        if (NEM[i] < ANG[j]) {
            NYELV.push_back(NEM[i]);
            i++;
        }
        else if (NEM[i] > ANG[j]) {
            NYELV.push_back(ANG[j]);
            j++;
        }
        else {  // egyenlõek
            NYELV.push_back(NEM[i]);
            i++;
            j++;
        }
    }

    // Eredmény kiírása
    for (const auto& s : NYELV) {
        cout << s << endl;
    }

    return 0;
}
