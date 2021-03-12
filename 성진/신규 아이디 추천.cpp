#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string new_id) {

    string kakaoid="";

    for (int i = 0; i < new_id.length(); i++)
        new_id[i] = tolower(new_id[i]);

        cout << new_id << endl;

    for (int i = 0; i < new_id.length(); i++)
        if ((new_id[i] >= 'a') && (new_id[i] <= 'z') || (new_id[i] >= '0') && (new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            kakaoid += new_id[i];

    cout << kakaoid << endl;

    int j;

    for (j = 1; j < kakaoid.length(); j++)
    {
        if (kakaoid[j] == '.' && kakaoid[j - 1] == '.')
        {
            kakaoid.erase(kakaoid.begin() + j);
            j--;
        }
    }

    cout << kakaoid << endl;

    if (kakaoid.length() != 0 && kakaoid[0] == '.')
        kakaoid.erase(kakaoid.begin());
    if (kakaoid.length() != 0 && kakaoid[kakaoid.length() - 1] == '.')
        kakaoid.erase(kakaoid.end()-1);

    cout << kakaoid << endl;

    if (kakaoid.length() == 0)
        kakaoid += "a";

    cout << kakaoid << endl;

    if (kakaoid.length() >= 16)
        kakaoid.erase(kakaoid.begin() + 15, kakaoid.begin() + kakaoid.length());

    cout << kakaoid << endl;

    if (kakaoid[kakaoid.length() - 1] == '.')
        kakaoid.pop_back();

    cout << kakaoid << endl;


    if (kakaoid.length() <= 2) {
        for (int i = kakaoid.length(); i < 3; i++)
            kakaoid+=kakaoid[kakaoid.length() - 1];

        cout << kakaoid << endl;
    }
    return kakaoid;
}

int main()
{
    string answer;
    getline(cin, answer);
   cout<< solution(answer);
}
