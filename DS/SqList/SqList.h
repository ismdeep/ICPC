/*
 * Project Name : SqList
 *
 * File    Name : main.cpp
 *
 * Author       : ismdeep
 *
 * Date & Time  : 2012 - 11 - 8 14:00
 *
 * Email        : honi.linux@gmail.com
 *
 * */


#include "Head.h"

template <typename ElemType>
class SqList
{
	private:
		ElemType* iData;
		int       iSize;
		int       iLength;
	public:
		SqList ();
		SqList (int iSize);
		SqList (int iSize, int iLength);
		~SqList ();
		bool is_empty ();
		bool is_full ();
		// set value
		void expand_size ();
		bool change_length (int iLength);
		bool set_elem_data_value (int iIndex, ElemType elem_value);
		// get value
		int get_size ();
		int get_length ();
		bool get_elem_data_value (int iIndex, ElemType& elem_data);
};


