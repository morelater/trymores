#include <iostream>
#include <map>
using namespace std;

//对你的爱，囫囵了整个青春。
//shared_ptr  强智能指针     能引起引用计数的变化
//weak_ptr    弱智能指针    不会引起引用计数的变化
//弱只能指针想使用的话必须转换成强智能指针  Pc->_pb.lock()->b;   lock()函数，转换成强智能指针   
template<typename T>
class smartPtr
{
private:
	T *_ptr;
	static map<T*, int> _num; //指针--引用计数
public:
	smartPtr(T *p)
	{
		_ptr = p;
		if (_num.find(p) != _num.end())
		{
			_num[p]++;
		}
		else
		{
			_num.insert(make_pair(p, 1));
		}
		cout << _ptr << ':' << _num[_ptr] << endl;
	}

	smatrPtr(const smartPtr& src)
	{
		_ptr = src._ptr;
		_num[src._ptr]++;
	}
	~smartPtr()
	{
		cout << "~smartPtr()" << endl;
		if (--_num[_ptr] == 0)
		{
			delete _ptr;
		}
		cout << _ptr << ':' << _num[_ptr] << endl;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	template<typename T>
	map<T*, int> smartPtr<T>::_num = map<T*, int>();
};

int main()
{

	return 0;
}