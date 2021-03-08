#include <iostream>

using namespace std;

class champion
{
private:
		string name="0";
		int level=0;
		int attack=0;
		int ability=0;
public:

	void champ_attackadd();
	void champ_abilityadd();
	void champ_list();
	champion(string str, int l, int at, int ab);
	champion();
	~champion();
};
void champion::champ_attackadd()
{
	cout << "1.롱소드 구매 (공격력 +10)" << endl;
	cout << "2.B.F대검 구매 (공격력 +40)" << endl;
	cout << "3.곡괭이 구매 (공격력 +25)" << endl;
	int attackitem;
	cin >> attackitem;
	if (attackitem == 1)
		attack += 10;
	if (attackitem == 2)
		attack += 40;
	if (attackitem == 3)
		attack += 25;
	cout << "구매가 완료되었습니다!! 현재 공격력 : " << attack << endl;
}
void champion::champ_abilityadd()
{
	cout << "1.증폭의 고서 구매 (주문력 +10)" << endl;
	cout << "2.방출의 마법봉 구매 (주문력 +25)" << endl;
	cout << "3.쓸데없이 큰 지팡이 구매 (주문력 +40)" << endl;
	int abilityitem;
	cin >> abilityitem;
	if (abilityitem == 1)
		ability += 10;
	if (abilityitem == 2)
		ability += 25;
	if (abilityitem == 3)
		ability += 40;
	cout << "구매가 완료되었습니다!! 현재 주문력 : " << ability << endl;;
}
void champion::champ_list()
{
	cout << name << "의 공격력 : " <<attack << endl;
	cout << name << "의 주문력 : " << ability << endl;
	cout << name << "의 종합 공격력 : " << attack + ability << endl;
}
champion::champion(string str, int l, int at, int ab)
{
	name = str;
	level = l;
	attack = at;
	ability = ab;
	cout << "=====================================================" << endl;
	cout << name << " 의 레벨 : " << level << endl;
	cout << name << " 의 공격력 : " << attack << endl;
	cout << name << " 의 주문력 : " << ability << endl;
	cout << "=====================================================" << endl;
}
champion::champion()
{

}
champion::~champion()
{
	cout << "=====================================================" << endl;
	cout << "[" << name << "] 챔피언이 공허로 돌아갔습니다......" << endl;
	cout << "=====================================================" << endl;

}

int main()
{
	champion champlist[10];
	int champnum = 0;
	string cmda;
	int cmdb, cmdc, cmdd;
	while (true)
	{
		cout << "========================================" << endl;
		cout << "1.챔피언 추가하기" << endl;
		cout << "2.챔피언 공격력 올리기" << endl;
		cout << "3.챔피언 주문력 올리기" << endl;
		cout << "4.챔피언 정보 보기" << endl;
		cout << "5.종료하기" << endl;
		cout << "========================================" << endl;
		int cmd;
		cin >> cmd;
		if (cmd == 5)
			cout << "감사합니다" << endl;
		switch (cmd)
		{
		case 1:
			cout << champnum << "번째 챔피언" << endl;
			cout << "Insert(이름 레벨 공격력 주문력)" << endl;
			cin >> cmda >> cmdb >> cmdc >> cmdd;
			champlist[champnum] = champion(cmda, cmdb, cmdc, cmdd);
			champnum++;
			break;
		case 2:
			cout << "몇번째 챔피언 의 공격력을 올리시겠습니까?" << endl;
			int n;
			cin >> n;
			champlist[n].champ_attackadd();
			break;
		case 3:
			cout << "몇번째 챔피언 의 주문력을 올리시겠습니까?" << endl;
			int m;
			cin >> m;
			champlist[m].champ_abilityadd();
			break;
		case 4:
			cout << "몇번째 챔피언 의 정보를 보시겠습니까?" << endl;
			int l;
			cin >> l;
			champlist[l].champ_list();
			break;
		default:
			break;
		}
	}
}