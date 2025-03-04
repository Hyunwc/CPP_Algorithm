
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}
	void push(const T& value)
	{
		// TODO : 다 찼는지 체크
		if (_size == _container.size())
		{
			// 증설 작업
			int newSize = max(1, _size * 2); // 0 * 2가 되는 것을 방지
			vector<T> newData;
			newData.resize(newSize);

			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }
private:
	vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};


int main()
{
	ArrayQueue<int> q;
	for (int i = 0; i < 100; i++)
		q.push(i);

	while (!q.empty())
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
}


