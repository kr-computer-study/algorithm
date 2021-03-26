#include <iostream>
#include <string>

using namespace std;

class Champion
{
private:
    string name;
    int level;
    float attack;
    float ability;
    float defense;
    float magicdefense;
    int money;
    int wincount;
    bool type;
public:
    Champion();
    ~Champion();
    void View();
    void Buyitem();
    void Buyattack(int);
    void Buyability(int);
    void Buydefense(int);
    void Buymagicdefense(int);
    void upline();
    void downline();
};

Champion::Champion()
{
    int t;
    upline();
    cout << "챔피언의 이름을 입력하세요 : ";
    cin >> name;
    cout << "챔피언의 타입을 지정하세요" << endl;
    cout << "1.마법 공격 타입\n2.물리 공격 타입" << endl;
    cin >> t;
    if (t == 1)
    {
        type = true;
        cout << name << " 는 마법 공격 타입입니다!";
        level = 1;
        attack = 50;
        ability = 100;
        defense = 30;
        magicdefense = 30;
        money = 10000;
        wincount = 0;
    }
    else
    {
        type = false;
        cout << name << " 는 물리 공격 타입입니다!";;
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
    cout << "\n======================================" << endl;
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
}
void Champion::Buyitem() {
    upline();
    cout << "1.공격력 아이템 구매" << endl;
    cout << "2.주문력 아이템 구매" << endl;
    cout << "3.방어력 아이템 구매" << endl;
    cout << "4.마법 저항력 아이템 구매" << endl;
    downline();
    int cmd;
    cout << "몇번 아이템을 구매하시겠습니까?";
    cin >> cmd;
    if (cmd == 1)
    {
        upline();
        cout << "1.롱소드 (공격력 +10 , 가격 500원)";
        cout << "2.도란의 검 (공격력 +20 , 가격 1000원)";
        cout << "3.곡괭이 (공격력 +40 , 가격 2000원)";
        cout << "4.B.F대검 (공격력 +80 , 가격 4000원)";
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까?";
        cin >> cmd;
        Buyattack(cmd);
    }
    if (cmd == 2)
    {
        upline();
        cout << "1.증폭의 고서 (주문력 +10 , 가격 500원)";
        cout << "2.도란의 반지 (주문력 +20 , 가격 1000원)";
        cout << "3.방출의 마법봉 (주문력 +40 , 가격 2000원)";
        cout << "4.쓸데없이 큰 지팡이 (주문력 +80 , 가격 4000원)";
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까?";
        cin >> cmd;
        Buyability(cmd);
    }
    if (cmd == 3)
    {
        upline();
        cout << "1.천 갑옷 (방어력 +5% , 가격 500원)";
        cout << "2.쇠사슬 조끼 (방어력 +8% , 가격 1000원)";
        cout << "3.덤불 조끼 (방어력 +12% , 가격 2000원)";
        cout << "4.가시 갑옷 (방어력 +15% , 가격 4000원)";
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까?";
        cin >> cmd;
        Buyability(cmd)
    }
    if (cmd == 4)
    {
        upline();
        cout << "1.마법 무효화의 망토 (마법저항력 +5% , 가격 500원)";
        cout << "2.음전자 망토 (마법저항력 +8% , 가격 1000원)";
        cout << "3.정령의 형상 (마법저항력 +12% , 가격 2000원)";
        cout << "4.용의 발톱 (마법저항력 +15% , 가격 4000원)";
        downline();
        int cmd;
        cout << "몇번 아이템을 구매하시겠습니까? : ";
        cin >> cmd;
    }

}
void Champion::Buyattack(int n) {
    if (n == 1)
    {
        upline();
        cout << "롱소드 (공격력 +10 , 가격 500원) 아이템을 구매하였습니다." << endl;
        attack += 10;
        cout << "현재 공격력 : " << attack << endl;
        downline();
    }
    if (n == 2)
    {
        upline();
        cout << "도란의 검 (공격력 +20 , 가격 1000원) 아이템을 구매하였습니다." << endl;
        attack += 20;
        cout << "현재 공격력 : " << attack << endl;
        downline();
    }
    if (n == 3)
    {
        upline();
        cout << "곡괭이 (공격력 +40 , 가격 2000원) 아이템을 구매하였습니다." << endl;
        attack += 40;
        cout << "현재 공격력 : " << attack << endl;
        downline();
    }
    if (n == 4)
    {
        upline();
        cout << "B.F대검 (공격력 +80 , 가격 4000원) 아이템을 구매하였습니다." << endl;
        attack += 80;
        cout << "현재 공격력 : " << attack << endl;
        downline();
    }

}
void Champion::Buyability(int n) {
    if (n == 1)
    {
        upline();
        cout << "증폭의 고서 (주문력 +10 , 가격 500원) 아이템을 구매하였습니다." << endl;
        ability += 10;
        cout << "현재 주문력 : " << ability << endl;
        downline();
    }
    if (n == 2)
    {
        upline();
        cout << "도란의 반지 (주문력 +20 , 가격 1000원) 아이템을 구매하였습니다." << endl;
        ability += 20;
        cout << "현재 주문력 : " << ability << endl;
        downline();
    }
    if (n == 3)
    {
        upline();
        cout << "방출의 마법봉 (주문력 +40 , 가격 2000원) 아이템을 구매하였습니다." << endl;
        ability += 40;
        cout << "현재 주문력 : " << ability << endl;
        downline();
    }
    if (n == 4)
    {
        upline();
        cout << "쓸데없이 큰 지팡이 (주문력 +80 , 가격 4000원) 아이템을 구매하였습니다." << endl;
        ability += 80;
        cout << "현재 주문력 : " << ability << endl;
        downline();
    }
}
void Champion::Buydefense(int n) {
    if (n == 1)
    {
        upline();
        cout << "천 갑옷 (방어력 +5% , 가격 500원) 아이템을 구매하였습니다." << endl;
        defense += 5;
        cout << "현재 방어력 : " << defense << endl;
        downline();
    }
    if (n == 2)
    {
        upline();
        cout << "쇠사슬 조끼 (방어력 +8% , 가격 1000원) 아이템을 구매하였습니다." << endl;
        defense += 8;
        cout << "현재 방어력 : " << defense << endl;
        downline();
    }
    if (n == 3)
    {
        upline();
        cout << "덤불 조끼 (방어력 +12% , 가격 2000원) 아이템을 구매하였습니다." << endl;
        defense += 12;
        cout << "현재 방어력 : " << defense << endl;
        downline();
    }
    if (n == 4)
    {
        upline();
        cout << "가시 갑옷 (방어력 +15% , 가격 4000원) 아이템을 구매하였습니다." << endl;
        defense += 15;
        cout << "현재 방어력 : " << defense << endl;
        downline();
    }

}
void Champion::upline()
{
    cout << "\n======================================" << endl;
}
void Champion::downline()
{
    cout << "======================================" << endl;
}
int main()
{

}
