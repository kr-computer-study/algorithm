#include <string>
#include <algorithm>
#include <iostream>
#include <forward_list>
using namespace std;
/*
배열이나 벡터같은 연속된 자료 구조에서는  데이터 중간에 자료를 추가하거나
삭제하는 작업이 매우 비효율적이다.
연결 리스트를 구성하려면 포인터를 가지고 있어야 하고,
new와 delete를 통해 메모리를 할당하고 해제 할 수 있어야 한다!
forward list는 전체 리스트의 크기를 반환하거나 첫 원소를 제외한
나머지 원소에 직접 접근하는 기능을 제공하지 않는다!
원소의 삽입,삭제,순서 뒤집기,분할을 위한 기능은 제공한다.
*/
forward_list<int> fwd = { 1,2,3,4,5,6,7,8,9 };

int main()
{
	fwd.push_front(0);
	//연결 리스트의 맨 앞에 0을 삽입해줍니다.

	auto it = fwd.begin();
	fwd.insert_after(it, 5);
	//it은 맨 처음 원소를 가리킨다.
	//첫번째 원소 뒤에 5를 삽입한다.

	fwd.pop_front();
	//연결 리스트의 맨 앞을 삭제해줍니다.

	fwd.erase_after(it);
	//연결 리스트의 첫번째 바로 뒤의 원소를 삭제합니다.

	fwd.erase_after(it, fwd.end());
	//연결 리스트의 첫번쨰 원소 뒤부터 마지막 원소까지 삭제합니다.
}
