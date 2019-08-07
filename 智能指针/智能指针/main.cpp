#include <iostream>
#include <map>
using namespace std;

//����İ��������������ഺ��
//shared_ptr  ǿ����ָ��     ���������ü����ı仯
//weak_ptr    ������ָ��    �����������ü����ı仯
//��ֻ��ָ����ʹ�õĻ�����ת����ǿ����ָ��  Pc->_pb.lock()->b;   lock()������ת����ǿ����ָ��   
template<typename T>
class smartPtr
{
private:
	T *_ptr;
	static map<T*, int> _num; //ָ��--���ü���
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