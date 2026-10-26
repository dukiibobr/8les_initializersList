#include <iostream>
using namespace std;

//class Array
//
//{
//
//	int* arr;
//	int size;
//
//public:
//
//	Array()
//
//	{
//
//		arr = nullptr;
//
//		size = 0;
//
//	}
//
//	explicit Array(int size)
//
//	{
//
//		this->size = size;
//
//		arr = new int[size] {};
//
//	}
//	Array(initializer_list<int>list)
//	{
//		this->size = list.size();
//		arr = new int[size];
//		int i = 0;
//		for (int elem:list)
//		{
//			arr[i] = elem;
//			i++;
//		}
//	}
//	void fill(initializer_list<int>list) {
//		if (arr != nullptr)
//			delete[]arr;
//
//
//		this->size = list.size();
//		arr = new int[size];
//		int i = 0;
//		for (int elem : list)
//		{
//			arr[i] = elem;
//			i++;
//		}
//	}
//	~Array()
//
//	{
//
//		if (arr != nullptr)
//
//			delete[]arr;
//
//	}
//
//	void Print()
//
//	{
//
//		for (int i = 0; i < size; i++)
//
//		{
//
//			cout << arr[i] << " ";
//
//		}
//
//		cout << endl;
//
//	}
//
//
//
//};







//1


//template <typename T_arr>
//class Array
//
//{
//
//	T_arr* arr;
//	int size;
//
//public:
//
//	Array()
//
//	{
//		arr = nullptr;
//		size = 0;
//	}
//
//	explicit Array(int size)
//
//	{
//		this->size = size;
//		arr = new T_arr[size] {};
//	}
//	Array(initializer_list<T_arr>list)
//	{
//		this->size = list.size();
//		arr = new T_arr[size];
//		int i = 0;
//		for (T_arr elem:list)
//		{
//			arr[i] = elem;
//			i++;
//		}
//	}
//
//	void fill(initializer_list<T_arr>list) {
//		if (arr != nullptr)
//			delete[]arr;
//
//		this->size = list.size();
//		arr = new T_arr[size];
//		int i = 0;
//		for (T_arr elem : list)
//		{
//			arr[i] = elem;
//			i++;
//		}
//	}
//	~Array()
//
//	{
//		if (arr != nullptr)
//			delete[]arr;
//	}
//
//	void Print()
//
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//
//	Array& operator=(initializer_list<T_arr>list) {
//		fill(list);
//		return *this;
//	}
//};






 //2

template <typename T_arr>
class Array

{

	T_arr* arr;
	int size;

public:

	Array()

	{
		arr = nullptr;
		size = 0;
	}

	explicit Array(int size)

	{
		this->size = size;
		arr = new T_arr[size]{};
	}
	Array(initializer_list<T_arr>list)
	{
		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr elem : list)
		{
			arr[i] = elem;
			i++;
		}
	}

	void fill(initializer_list<T_arr>list) {
		if (arr != nullptr)
			delete[]arr;

		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr elem : list)
		{
			arr[i] = elem;
			i++;
		}
	}
	~Array()

	{
		if (arr != nullptr)
			delete[]arr;
	}

	void Print()

	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	Array& operator=(initializer_list<T_arr>list) {
		fill(list);
		return *this;
	}




	void findMax();
	void findMin();


	void BubbleSort();

	int BinarySearch(T_arr key);

	void replace(int index, T_arr value);
};
int main()
{
	//2
	Array<float>arr({1.4,2,9,3,4,5,6,7,0,8,19.5,9.8});
	arr.findMax();
	arr.findMin();

	arr.Print();
	arr.BubbleSort();
	arr.Print();

	cout << "index of key: " << arr.BinarySearch(9.8) << endl;
	arr.replace(2, 6.5);
	arr.Print();



	//1
	//Array<int> arr({ 5,2,3,5 });
	//Array<float> arr2({ 8.3,5.7 });
	//arr.Print();
	//arr2.Print();
	//arr = {1,2,3,4,65};
	//arr.Print();





	//int staticArr[5] = { 1,2,3,4,5 };
	//int* dynamArr = new int[5] {5, 4, 3, 2, 1};


	//Array arr(10);
	//arr.Print();

	//Array arr2({ 5, 4, 5, 7, 3, 6 });
	//arr2.Print();

	//arr2.fill({ 3,2,1 });
	//arr2.Print();
	//                                       


	//delete[]dynamArr;
}

template<typename T_arr>
 void Array<T_arr>::findMax() {
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	cout << "biggest numbber is: " << max << endl;
}

template<typename T_arr>
 void Array<T_arr>::findMin() {
	T_arr min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i]<min)
		{
			min = arr[i];
		}
	}
	cout << "smallest numbber is: " << min << endl;
}

template<typename T_arr>
 void Array<T_arr>::BubbleSort()
{
	T_arr temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<typename T_arr>
 int Array<T_arr>::BinarySearch(T_arr key)
{
	int B = 0, E = size - 1;
	while (B<=E)
	{
		int p = (B + E) / 2;
		if (key > arr[p])
		{
			B = p + 1;
		}
		else if (key < arr[p])
		{
			E = p - 1;
		}
		else if (key == arr[p])
			return p;
		if (B > E) return -1;
	}
	return -1;
}

 template<typename T_arr>
  void Array<T_arr>::replace(int index, T_arr value) {
	 if (index >= 0 and index<size)
	 {
		 arr[index] = value;
	 }
	 else
	 {
		 cout << "wrong index" << endl;
	 }
 }
