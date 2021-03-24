#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> editor;
list<char> ::iterator cursor;
//값을 넣을 리스트와 반복자 cursor를 선언해준다!
//반복자를 리스트 안을 돌아다니면서 리스트에 접근하게 해준다!
int main(void) {

    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
        editor.push_back(str[i]);
//문자열을 슬라이싱하여 리스트에 넣어준다!
    cursor = editor.end();

    int repeat;
    cin >> repeat;

    char cmd;
    for (int i = 0; i < repeat; i++)
    {
        cin >> cmd;

        if (cmd == 'L') {
            if (cursor != editor.begin())
                cursor--;
        }
        //cursor를 이전 노드로 줄인다.

        if (cmd == 'D') {
            if (cursor != editor.end())
                cursor++;
        }
        //cursor를 다음 노드로 늘린다.

        if (cmd == 'B') {
            if (editor.begin()!=cursor)
            {
                auto it = --cursor;
                cursor++;
                editor.erase(it);
            }
        }
        //새로운 반복자 it을 선언해준다. it의 값은 증감된 cursor값임
        //it위치에 있는 editor의 값을 삭제해준다.


        if (cmd == 'P') {
            char PP;
            cin >> PP;
            editor.insert(cursor, PP);
        }
    }//반복자 cursor가 있는 곳에 원소 삽입

    for (auto it= editor.begin(); it != editor.end(); ++it)
        cout << *it;
        //반복자 it을 시작부터 끝까지 돌린당
}
