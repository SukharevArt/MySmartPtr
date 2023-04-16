
#include <iostream>
#include <assert.h>
#include"MySmartPtr.h"


int main()
{
	{
		my_smart_ptr<int> ptr = new int;
		if (ptr) {
			(*ptr) = 4;
			assert(*ptr == 4);
		}
	}

	/*{
		my_smart_ptr<int> ptr = new int;
		*ptr = 4;
		std::cout << *ptr << std::endl;
	}*/

	{
		my_smart_ptr<double> ptr = new double[10];
		if (ptr) {
			for (int i = 0; i < 10; i++) {
				ptr[i] = i * 4;
			}
			my_smart_ptr<double> tmp;
			tmp = ptr;
			if (tmp) {
				for (int i = 0; i < 10; i++) {
					assert(tmp[i] == i * 4);
				}
			}
		}
	}

	{
		my_smart_ptr<double> tmp;
		{
			my_smart_ptr<double> ptr = new double[10];
			if (ptr) {
				for (int i = 0; i < 10; i++) {
					ptr[i] = i * 4;
				}
				tmp = ptr;
			}
		}
		if (tmp){
			for (int i = 0; i < 10; i++) {
				assert(tmp[i] == i * 4);
			}
		}
	}
	{
		my_smart_ptr<double> tmp;
		{
			my_smart_ptr<double> ptr = new double[10];
			if (ptr) {
				for (int i = 0; i < 10; i++) {
					ptr[i] = i * 4;
				}
				std::cout << "Test count:\n";
				std::cout << ptr.getCount() << "\n";
				tmp = ptr;
				std::cout << ptr.getCount() << "\n";
			}
		}
		if (tmp) {
			std::cout << tmp.getCount() << "\n";
			for (int i = 0; i < 10; i++) {
				assert(tmp[i] == i * 4);
			}
		}
	}

	return 0;
}

