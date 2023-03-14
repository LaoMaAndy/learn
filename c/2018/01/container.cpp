/*
function: container
*/
#include "0head.cpp"

void container(void)
{
	// container type:
	vector<int> vi;
	deque<int> di;
	list<int> li;
	forward_list<int> fi;
	array<int, 10> a10i = {1, 2, 3, 4, 5};

	// constructor 
	vector<int> vi1;
	vector<int> vi2(vi);
	vector<int> vi3(vi.begin(), vi.end());
	vector<int> vi4(10);
	vector<int> vi5(10, 2);
	vector<int> vi6 = {10, 2};
	
	// iterator
	vector<int>::iterator vit;
	vector<int>::const_iterator vict;
	vector<int>::reverse_iterator virt;
	vector<int>::const_reverse_iterator vicrt;
	vi.begin();
	vi.end();
	vi.cbegin();
	vi.cend();
	vi.rbegin();
	vi.rend();
	vi.crbegin();
	vi.crend();	

	// type alias
	vector<int>::size_type vist;
	vector<int>::difference_type vidt;
	vector<int>::value_type vivt;
	vector<int>::reference vir = vi[0];
	vector<int>::const_reference vicr = vi[1];

	// assignment & swap
	vi = {1, 2, 3, 4, 5};
	vi1 = vi;
	vi2.swap(vi1);
	swap(vi3, vi2);
	list<string> ls;
	vector<const char *> vc;
	ls.assign(vc.cbegin(), vc.cend());

	// size
	vi.size();
	vi.max_size();
	vi.empty();
	
	// relationship
	vi == vi1;
	vi != vi1;
	vi > vi1;
	vi < vi1;
	vi >= vi1;
	vi <= vi1;
	//insert, erase, emplace, clear	

	for (auto c : a10i)
		cout << '\t' << c << endl;
}
int main(void)
{
	container();
	return 0;
}
