#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
vector는 C스타일의 배열의 향상된 버전이다.!
기존 배열의 단점인 크기가 고정된다는 점을 해결할 수 있는
방법이며 가변 배열을 통해 접근 할 수 있다.
*/
vector<int> vec1 = { 1,2,3,4,5,6,7,8,9,10 };
vector<int> vec2(10);
vector<int> vec3(10, 5);
//벡터를 선언하는 방법 3가지!

void view(vector<int> vectorcmd)
{
	for (int i = 0; i < vectorcmd.size(); i++)
		cout << vectorcmd[i] << " ";
	cout << endl;
}
void vectorshow()
{
	cout << "vec1의 벡터 : ";
	view(vec1);
	cout << "vec2의 벡터 : ";
	view(vec2);
	cout << "vec2의 벡터 : ";
	view(vec3);
	cout << "===========================" << endl;
}

int main()
{
	vectorshow();

	cout << "pop_back 연산 후" << endl;
	vec1.pop_back();
	vec2.pop_back();
	vec3.pop_back();
	vectorshow();
	//벡터의 맨 뒤 원소를 제거합니다
	cout << "vec1.erase(vec1.begin()) 연산 후" << endl;
	vec1.erase(vec1.begin());
	vec2.erase(vec2.begin());
	vec3.erase(vec3.begin());
	vectorshow();
	//특정 위치의 원소를 제거합니다.
	cout << "vec1.erase(vec1.begin()+1,vec1.begin()+3); 연산 후" << endl;
	vec1.erase(vec1.begin()+1,vec1.begin()+3);
	vec2.erase(vec2.begin() + 1, vec2.begin() + 3);
	vec3.erase(vec3.begin() + 1, vec3.begin() + 3);
	vectorshow();
	//1번째 원소부터 3번째 원소의 앞까지 제거합니다.
	cout << "	vec1.push_back(10); 연산 후" << endl;
	vec1.push_back(10);
	vec2.push_back(10);
	vec3.push_back(10);
	vectorshow();
	//벡터의 맨 뒤에 값을 추가합니다.
	cout << "vec1.insert(vec1.begin(), 8); 연산 후" << endl;
	vec1.insert(vec1.begin(), 8);
	vec2.insert(vec2.begin(), 8);
	vec3.insert(vec3.begin(), 8);
	vectorshow();
	//벡터의 맨 앞에 8을 추가합니다.
	cout << "vec1.insert(find(vec1.begin(),vec1.end(),10),9); 연산 후" << endl;
	vec1.insert(find(vec1.begin(),vec1.end(),10),9);
	vec2.insert(find(vec2.begin(), vec2.end(), 10), 9);
	vec3.insert(find(vec3.begin(), vec3.end(), 10), 9);
	vectorshow();
	//find를 통해 검색 범위를 시작부터 끝까지 정해주고, 10을 찾은
	//위치에 9을 삽입해줍니다.
}
