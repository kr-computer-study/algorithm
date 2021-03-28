#include <iostream>
#include <string>

using namespace std;

class Champion
{
private:
    int level;
    float attack;
    float ability;
    float defense;
    float magicdefense;
    int money;
    int wincount;
    bool type;
public:
    string name;
    Champion();
    Champion(string);
    ~Champion();
    void View();
    void Buyitem();
    void Buyattack(int);
    void Buyability(int);
    void Buydefense(int);
    void Buymagicdefense(int);
    void upline();
    void downline();
    void Fight(Champion);
};

Champion::Champion()
{
}
Champion::Champion(string welcome)
{
    int t;
    upline();
    cout << welcome << "챔피언의 이름을 입력하세요 : ";
    cin >> name;
    cout << "챔피언의 타입을 지정하세요" << endl;
    cout << "1.마법 공격 타입\n2.물리 공격 타입" << endl;
    cin >> t;
    if (t == 1)
    {
        type = true;
        cout << name << " 는 마법 공격 타입입니다!" << endl;
        level = 1;
        attack = 50;
        ability = 100;
        defense = 30;
        magicdefense = 30;
        money = 10000;
        wincount = 0;
        downline();
    }
    else
    {
        type = false;
        cout << name << " 는 물리 공격 타입입니다!" << endl;
        level = 1;
        attack = 100;
        ability = 50;
        defense = 30;
        magicdefense = 30;
        money = 10000;
        wincount = 0;
    }
    downline();
}
Champion::~Champion()
{
}
void Champion::View()
{
    upline();
    cout << name << " 챔피언의 정보" << endl;
    cout << "레벨 : " << level << endl;
    cout << "공격력 : " << attack << endl;
    cout << "주문력 : " << ability << endl;
    cout << "방어력 : " << defense << "%" << endl;
    cout << "마법 방어력 : " << magicdefense << "%" << endl;
    cout << "돈 : " << money << "원" << endl;
    cout << "승부에서 승리한 횟수 : " << wincount << endl;
    if (type)
        cout << "공격 타입 : " << "마법 공격 타입" << endl;
    else
        cout << "공격 타입 : " << "물리 공격 타입" << endl;
    downline();
}
void Champion::Buyitem() {
    upline();
    cout << name << "의 아이템 구매창" << endl;
    cout << "1.공격력 아이템 구매" << endl;
    cout << "2.주문력 아이템 구매" << endl;
    cout << "3.방어력 아이템 구매" << endl;
    cout << "4.마법 저항력 아이템 구매" << endl;
    cout << "5.아이템 구매 취소" << endl;
    downline();
    int cmd;
    cout << "몇번 아이템을 구매하시겠습니까? : ";
    cin >> cmd;
    if (cmd == 1)
    {
        upline();
        cout << "1.롱소드 (공격력 +10 , 가격 500원)" << endl;
        cout << "2.도란의 검 (공격력 +20 , 가격 1000원)" << endl;
        cout << "3.곡괭이 (공격력 +40 , 가격 2000원)" << endl;
        cout << "4.B.F대검 (공격력 +80 , 가격 4000원)" << endl;
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까? : " << endl;
        cin >> cmd;
        Buyattack(cmd);
    }
    if (cmd == 2)
    {
        upline();
        cout << "1.증폭의 고서 (주문력 +10 , 가격 500원)" << endl;
        cout << "2.도란의 반지 (주문력 +20 , 가격 1000원)" << endl;
        cout << "3.방출의 마법봉 (주문력 +40 , 가격 2000원)" << endl;
        cout << "4.쓸데없이 큰 지팡이 (주문력 +80 , 가격 4000원)" << endl;
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까? : " << endl;
        cin >> cmd;
        Buyability(cmd);
    }
    if (cmd == 3)
    {
        upline();
        cout << "1.천 갑옷 (방어력 +5% , 가격 500원)" << endl;
        cout << "2.쇠사슬 조끼 (방어력 +8% , 가격 1000원)" << endl;
        cout << "3.덤불 조끼 (방어력 +12% , 가격 2000원)" << endl;
        cout << "4.가시 갑옷 (방어력 +15% , 가격 4000원)" << endl;
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까? : " << endl;
        cin >> cmd;
        Buyability(cmd);
    }
    if (cmd == 4)
    {
        upline();
        cout << "1.마법 무효화의 망토 (마법저항력 +5% , 가격 500원)" << endl;
        cout << "2.음전자 망토 (마법저항력 +8% , 가격 1000원)" << endl;
        cout << "3.정령의 형상 (마법저항력 +12% , 가격 2000원)" << endl;
        cout << "4.용의 발톱 (마법저항력 +15% , 가격 4000원)" << endl;
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까? : " << endl;
        cin >> cmd;
        Buymagicdefense(cmd);
    }
    if (cmd == 5)
    {
        upline();

        downline();
    }
}
void Champion::Buyattack(int n) {
    if (n == 1)
    {
        upline();
        if (money < 500)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "롱소드 (공격력 +10 , 가격 500원) 아이템을 구매하였습니다." << endl;
            attack += 10;
            cout << "현재 공격력 : " << attack << endl;
        }
        downline();
    }
    if (n == 2)
    {
        upline();
        if (money < 1000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "도란의 검 (공격력 +20 , 가격 1000원) 아이템을 구매하였습니다." << endl;
            attack += 20;
            cout << "현재 공격력 : " << attack << endl;
        }
        downline();
    }
    if (n == 3)
    {
        upline();
        if (money < 2000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "곡괭이 (공격력 +40 , 가격 2000원) 아이템을 구매하였습니다." << endl;
            attack += 40;
            cout << "현재 공격력 : " << attack << endl;
        }
        downline();
    }
    if (n == 4)
    {
        upline();
        if (money < 4000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "B.F대검 (공격력 +80 , 가격 4000원) 아이템을 구매하였습니다." << endl;
            attack += 80;
            cout << "현재 공격력 : " << attack << endl;
        }
        downline();
    }

}
void Champion::Buyability(int n) {
    if (n == 1)
    {
        upline();
        if (money < 500)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "증폭의 고서 (주문력 +10 , 가격 500원) 아이템을 구매하였습니다." << endl;
            ability += 10;
            cout << "현재 주문력 : " << ability << endl;
        }
        downline();
    }
    if (n == 2)
    {
        upline();
        if (money < 1000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "도란의 반지 (주문력 +20 , 가격 1000원) 아이템을 구매하였습니다." << endl;
            ability += 20;
            cout << "현재 주문력 : " << ability << endl;
        }
        downline();
    }
    if (n == 3)
    {
        upline();
        if (money < 2000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "방출의 마법봉 (주문력 +40 , 가격 2000원) 아이템을 구매하였습니다." << endl;
            ability += 40;
            cout << "현재 주문력 : " << ability << endl;
        }
        downline();
    }
    if (n == 4)
    {
        upline();
        if (money < 4000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "쓸데없이 큰 지팡이 (주문력 +80 , 가격 4000원) 아이템을 구매하였습니다." << endl;
            ability += 80;
            cout << "현재 주문력 : " << ability << endl;
        }
        downline();
    }
}
void Champion::Buydefense(int n) {
    if (n == 1)
    {
        upline();
        if (money < 500)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "천 갑옷 (방어력 +5% , 가격 500원) 아이템을 구매하였습니다." << endl;
            defense += 5;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 2)
    {
        upline();
        if (money < 1000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else
        {
            cout << "쇠사슬 조끼 (방어력 +8% , 가격 1000원) 아이템을 구매하였습니다." << endl;
            defense += 8;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 3)
    {
        upline();
        if (money < 2000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "덤불 조끼 (방어력 +12% , 가격 2000원) 아이템을 구매하였습니다." << endl;
            defense += 12;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 4)
    {
        upline();
        if (money < 4000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "가시 갑옷 (방어력 +15% , 가격 4000원) 아이템을 구매하였습니다." << endl;
            defense += 15;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }

}
void Champion::Buymagicdefense(int n) {
    if (n == 1)
    {
        upline();
        if (money < 500)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "마법 무효화의 망토 (마법저항력 +5% , 가격 500원) 아이템을 구매하였습니다." << endl;
            magicdefense += 5;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 2)
    {
        upline();
        if (money < 500)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "음전자 망토 (마법저항력 +8% , 가격 1000원) 아이템을 구매하였습니다." << endl;
            magicdefense += 8;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 3)
    {
        upline();
        if (money < 2000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "정령의 형상 (마법저항력 +12% , 가격 2000원) 아이템을 구매하였습니다." << endl;
            magicdefense += 12;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }
    if (n == 4)
    {
        upline();
        if (money < 4000)
            cout << "돈이 없네요!! ㅠㅠ..." << endl;
        else {
            cout << "용의 발톱 (마법저항력 +15% , 가격 4000원) 아이템을 구매하였습니다." << endl;
            magicdefense += 15;
            cout << "현재 방어력 : " << defense << endl;
        }
        downline();
    }

}
void Champion::Fight(Champion compare)
{
    float a, b;
    if (type == true && compare.type == true) {
        a = ability / 100 * (100 - compare.magicdefense);//a의 전투력
        b= compare.ability / 100 * (100 -magicdefense);
    }
    if (type == true && compare.type == false) {
        a = ability / 100 * (100 - compare.magicdefense);//a의 전투력
        b = compare.attack / 100 * (100 - defense);
    }
    if (type == false && compare.type == true) {
        a = attack / 100 * (100 - compare.defense);//a의 전투력
        b = compare.ability / 100 * (100 - magicdefense);
    }
    if (type == false && compare.type == false) {
        a = attack / 100 * (100 - compare.defense);//a의 전투력
        b = compare.attack / 100 * (100 - defense);
    }
    upline();
    cout << name << "이 " << compare.name << "과 결투합니다." << endl;
    if (a > b) {
        cout << name << "이 이겼습니다!" << endl;
        cout << name << "의 전투력 : " << a << endl;
        cout << compare.name << "의 전투력 : " << b << endl;
        wincount++;
        cout << "현재 승점 : " << wincount << endl;
    }
    else if (a == b) {
        cout << "비겼습니다." << endl;
    }
    else {
        cout << compare.name << "이 이겼습니다!" << endl;
        cout << name << "의 전투력 : " << a << endl;
        cout << compare.name << "의 전투력 : " << b << endl;
        compare.wincount++;
        cout << "현재 승점 : " << compare.wincount << endl;
    }

    downline();
}
void Champion::upline()
{
    cout << "\n=====================================================" << endl;
}
void Champion::downline()
{
    cout << "======================================" << endl;
}
void infor()
{
    cout << "\n=====================================================" << endl;
    cout << "항목을 선택해주세요" << endl;
    cout << "1.챔피언 생성하기" << endl;
    cout << "2.챔피언 리스트 보기" << endl;
    cout << "3.챔피언 정보 보기" << endl;
    cout << "4.아이템 구매하기" << endl;
    cout << "5.결투하기" << endl;
    cout << "6.게임 종료하기" << endl;
    cout << "======================================" << endl;
    cout << "몇번을 선택하시겠습니까? : ";

}

int main()
{
    Champion* ch = new Champion[10];
    int championnumber = 0;
    while (true)
    {
        infor();
        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            ch[championnumber] = Champion("안녕하세요! ");
            championnumber++;
            break;
        case 2:
            cout << "\n======================================" << endl;
            for (int i = 0; i < 10; i++)
                cout << i << "번째 챔피언 : " << ch[i].name << endl;
            cout << "======================================" << endl;
            break;
        case 3:
            int a;
            cout << "\n======================================" << endl;
            cout << "몇번째 챔피언의 정보를 보시겠습니까?";
            cin >> a;
            ch[a].View();
            cout << "======================================" << endl;
            break;
        default:
        case 4:
            int b;
            cout << "\n======================================" << endl;
            cout << "몇번째 챔피언의 아이템을 사시겠습니까? : ";
            cin >> b;
            ch[b].Buyitem();
            cout << "======================================" << endl;
            break;
        case 5:
            cout << "\n======================================" << endl;
            cout << "싸울 챔피언의 번호를 골라주세요 : ";
            int chn1;
            cin >> chn1;
            cout << "누구와 싸울지 번호를 골라주세요 : ";
            int chn2;
            cin >> chn2;
            ch[chn1].Fight(ch[chn2]);
            cout << "======================================" << endl;

            break;
        case 6:
            cout << "\n======================================" << endl;
            cout << "감사합니다. 안녕히 계세용~! :D" << endl;
            cout << "======================================" << endl;
            goto exit;
            break;
        }
    }
exit:;
}
