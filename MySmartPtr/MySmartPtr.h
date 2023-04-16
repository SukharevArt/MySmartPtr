#pragma once
#include<stdio.h>

template<class T>
class ptr_counter {
private:
	T* data;
	int count;
public:
	ptr_counter(T* _data){
		data = _data;
		count = 1;
	}
	~ptr_counter() { 
		delete data;
	}
	T* getData() const { 
		return data; 
	}
	int getCount() const { 
		return count; 
	}
	void incCount() { 
		count++; 
	}
	void decCount() { 
		count--; 
	}
};

template<class T>
class my_smart_ptr {
private:
	ptr_counter<T>* value;
	bool is_checked;
public:
	my_smart_ptr(T* _ptr = nullptr) {
		if (_ptr != nullptr)
			value = new ptr_counter<T>(_ptr);
		else
			value = nullptr;
		is_checked = false;
	}
	my_smart_ptr(const my_smart_ptr& _ptr) {
		value = _ptr.value;
		if (value != nullptr)
			value->incCount();
		is_checked = false;
	}
	~my_smart_ptr() {
		if (value != nullptr) {
			value->decCount();
			if (value->getCount() == 0)
				delete value;
		}
	}
	my_smart_ptr& operator=(const my_smart_ptr& _ptr) {
		if (value != nullptr) {
			delete value;
		}
		value = _ptr.value;
		if (value != nullptr)
			value->incCount();
		is_checked = false;
		return *this;
	}
	T& operator* () const {
		if (!is_checked) {
			fprintf(stderr, "Warning: pointer is used without checking on null\n");
		}
		return *(value->getData());
	}
	T& operator-> () const {
		if (!is_checked) {
			fprintf(stderr, "Warning: pointer is used without checking on null\n");
		}
		return *(value->getData());
	}
	T& operator[] (int o) const {
		if (!is_checked) {
			fprintf(stderr, "Warning: pointer is used without checking on null\n");
		}
		if (o < 0)
			throw "out_of_range";
		return *(value->getData()+o);
	}
	operator bool() {
		is_checked = true;
		return value != nullptr;
	}
	int getCount() const { 
		return value->getCount(); 
	}

};
