#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin>>N;
  vector<long>zeroone;
  zeroone.push_back(0);
  zeroone.push_back(1);
  zeroone.push_back(2);
  for(int i=3;i<=N;i++)
  zeroone.push_back((zeroone[i-1]+zeroone[i-2])%15746);

  cout<<zeroone[N]<<endl;
}
