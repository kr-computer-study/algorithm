#include <iostream>
#include <string>
using namespace std;

struct champ
{
	string name;
	int level;
	int attack;
	int ability;
};
void champ_add(champ* champcmd)
{
	cout << "챔피언의 이름을 입력하세요 : ";
	cin >> champcmd->name;
	cout << "챔피언의 공격력을 입력하세요 : ";
	cin >> champcmd->attack;
	cout << "챔피언의 주문력을 입력하세요 : ";
	cin >> champcmd->ability;
	cout << "챔피언 이름 : " << champcmd->name << endl;
	cout << "챔피언 공격력 : " << champcmd->attack << endl;
	cout << "챔피언 주문력 : " << champcmd->ability << endl;	
}
void champ_attackadd(champ* champcmd)
{
	cout << "1.롱소드 구매 (공격력 +10)" << endl;
	cout << "2.B.F대검 구매 (공격력 +40)" << endl;
	cout << "3.곡괭이 구매 (공격력 +25)" << endl;
	int attackitem;
	cin >> attackitem;
	if (attackitem == 1)
		champcmd->attack += 10;
	if (attackitem == 2)
		champcmd->attack += 40;
	if (attackitem == 3)
		champcmd->attack += 30;
	cout << "구매가 완료되었습니다!! 현재 공격력 : " << champcmd->attack << endl;;
}
void champ_abilityadd(champ* champcmd)
{
	cout << "1.증폭의 고서 구매 (주문력 +10)" << endl;
	cout << "2.방출의 마법봉 구매 (주문력 +25)" << endl;
	cout << "3.쓸데없이 큰 지팡이 구매 (주문력 +40)" << endl;
	int abilityitem;
	cin >> abilityitem;
	if (abilityitem == 1)
		champcmd->ability += 10;
	if (abilityitem == 2)
		champcmd->ability += 25;
	if (abilityitem == 3)
		champcmd->ability += 40;
	cout << "구매가 완료되었습니다!! 현재 주문력 : " << champcmd->ability << endl;;
}
void champ_list(champ* champcmd)
{
	cout << champcmd->name << "의 공격력 : " << champcmd->attack << endl;
	cout << champcmd->name << "의 주문력 : " << champcmd->ability << endl;
	cout << champcmd->name << "의 종합 공격력 : " << champcmd->attack+ champcmd->ability << endl;
}
int main()
{
	champ* champlist[5];
	 int champnum = 0;
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
		{
			cout << "감사합니다" << endl;
			break;
		}
		switch (cmd)
		{
		case 1:
			champlist[champnum] = new champ;
			cout << champnum << "번째 챔피언" << endl;
			champ_add(champlist[champnum]);
			champnum++;
			break;
		case 2:
			cout << "몇번째 챔피언 의 공격력을 올리시겠습니까?" << endl;
			int n;
			cin >> n;
			champ_attackadd(champlist[n]);
			break;
		case 3:
			cout << "몇번째 챔피언 의 주문력을 올리시겠습니까?" << endl;
			int m;
			cin >> m;
			champ_abilityadd(champlist[m]);
				break;
		case 4:
			cout << "몇번째 챔피언 의 정보를 보시겠습니까?" << endl;
			int l;
			cin >> l;
			champ_list(champlist[l]);
			break;
		default:
			break;
		}
	}
	delete champlist[0];
	delete champlist[1];
	delete champlist[2];
	delete champlist[3];
	delete champlist[4];
}