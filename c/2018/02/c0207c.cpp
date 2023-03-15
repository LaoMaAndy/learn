/*
function: container
*/
#include "0head.cpp"

void container(void)
{
	//container type
	vector<int> vi;
	deque<int> di;
	list<int> li;
	forward_list<int> fi;
	array<int, 10> ai10;

	//constructor
	int a[10];
	vector<int> vi1;
	vector<int> vi2(10);
	vector<int> vi3(10, 2);
	vector<int> vi4{10, 2};
	vector<int> vi5(vi1);
	vector<int> vi6(begin(a), end(a));

	//iterator
	vector<int>::iterator vit;
	vector<int>::const_iterator cvit;
	vector<int>::reverse_iterator rvit;
	vector<int>::const_reverse_iterator crvit;
	vit = vi.begin();
	vi.end();
	vi.cbegin();
	vi.cend();
	vi.rbegin();
	vi.rend();
	vi.crbegin();
	vi.crend();

	//type of alias
	vector<int>::size_type vist;
	vector<int>::difference_type vidt;
	vector<int>::value_type vivt;
	vector<int>::reference vir = vi[0];
	vector<int>::const_reference vicr = vi[1];

	// assignment & swap
	vi = {1, 2, 3, 4};
	vi1 = vi;
	vi2.swap(vi);
	swap(vi3, vi2);

	// size
	vi.size();
	vi.max_size();
	vi.empty();

	// relationship
	vi == vi1;
	vi != vi1;
	vi > vi1;
	vi >= vi1;
	vi <= vi1;

}

int main(void)
{
	container();
	return 0;
}
