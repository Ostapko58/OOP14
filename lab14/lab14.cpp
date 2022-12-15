#include <iostream> // std::cout
#include <algorithm> // std::generate
#include <vector> // std::vector
#include <ctime> // std::time
#include <numeric> // std::accumulate
using namespace std;
int RandomNumber() { return (rand() % 100); }
void print(vector<int> a)
{
	for (int i : a)
		cout << i << " ";
	cout << endl;
}
int main()
{
	srand(unsigned(time(0)));
	int n;
	cout << "input n : "; cin >> n;
	vector<int> v(n);
	generate(v.begin(), v.end(), RandomNumber);
	print(v);
	vector<int> u(v.size());
	auto p = copy_if(v.begin(), v.end(), u.begin(), [](int i) {return i % 2 != 0; });
	u.resize(p - u.begin());
	//print(u);
	auto k = u.size();
	auto s = accumulate(u.begin(), u.end(), 0);
	cout << "AVG = " << s * 1. / k << endl;
	return 0;
}