#pragma once

template <typename T>
class singletonBase
{
protected:
	static T* singleton; //�̱��� �ν��Ͻ� ����
	singletonBase(void) {};
	~singletonBase(void) {};
	
public:
	static T* getSingleton(void); //�ν��Ͻ� ��´�
	void releaseSingleton(void); //�ν��Ͻ� ������ �ش�
	//(���������� �ݵ�� ����..)
};

//�̱��� �ʱ�ȭ
template <typename T>
T* singletonBase<T>::singleton = 0;

//�̱��� �� ��������
template <typename T>
T* singletonBase<T>::getSingleton(void)
{
	if (!singleton) singleton = new T;
	return singleton;
}

//�̱��� �޸� ����
template <typename T>
void singletonBase<T>::releaseSingleton(void)
{
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}