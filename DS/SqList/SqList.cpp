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

#include "SqList.h"

///////////////////////////////////////////////////////////
template <typename ElemType>
SqList<ElemType>::SqList ()
{
	this->iSize   = _SQLIST_DEFAULT_SIZE_;
	this->iData   = new ElemType [this->iSize];
	this->iLength = 0;
}

///////////////////////////////////////////////////////////
template <typename ElemType>
SqList<ElemType>::SqList (int iSize)
{
	this->iSize   = iSize;
	this->iData   = new ElemType [this->iSize];
	this->iLength = 0;
}

///////////////////////////////////////////////////////////
template <typename ElemType>
SqList<ElemType>::SqList (int iSize, int iLength)
{
	this->iSize   = iSize;
	this->iData   = new ElemType [this->iSize];
	this->iLength = iLength;
}

///////////////////////////////////////////////////////////
template <typename ElemType>
SqList<ElemType>::~SqList ()
{
	delete[] this->iData;
}


///////////////////////////////////////////////////////////
template <typename ElemType>
bool SqList<ElemType>::is_empty ()
{
	return 0 == this->iLength;
}

///////////////////////////////////////////////////////////
template <typename ElemType>
bool SqList<ElemType>::is_full ()
{
	return this->iSize <= this->iLength;
}


///////////////////////////////////////////////////////////
template <typename ElemType>
void SqList<ElemType>::expand_size ()
{
	// create a tmp_iData array for save iData temporary
	ElemType* tmp_iData;
	tmp_iData = new ElemType [this->iLength];
	// copy iData to tmp_iData
	for (int i = 0; i < this->iLength; i++)
	{
		tmp_iData[i] = this->iData[i];
	}
	// delete iData mem
	delete[] this->iData;
	// expand iSize by _SQLIST_DEFAULT_SIZE_
	this->iSize += _SQLIST_DEFAULT_SIZE_;
	this->iData = new ElemType [this->iSize];
	// copy tmp_iData to iData
	for (int i = 0; i < this->iLength; i++)
	{
		this->iData[i] = tmp_iData[i];
	}
}

///////////////////////////////////////////////////////////
template <typename ElemType>
bool SqList<ElemType>::change_length (int iLength)
{
	// if iLength is illegal , just exit ();
	// and return false;
	if (iLength < 0)
	{
		return false;
	}
	else
	{
		this->iLength = iLength;
		while (this->is_full ())
		{
			this->expand_size ();
		}
		return true;
	}
}

///////////////////////////////////////////////////////////
template <typename ElemType>
bool SqList<ElemType>::set_elem_data_value (
		int iIndex, 
		ElemType elem_value
)
{
	// judge if iIndex is leagle
	if (iIndex < 0 || iIndex + 1 > iLength)
	{
		return false;
	}
	else
	{
		this->iData[iIndex] = elem_value;
		return true;
	}
}

///////////////////////////////////////////////////////////
template <typename ElemType>
int SqList<ElemType>::get_size ()
{
	return this->iSize;
}
///////////////////////////////////////////////////////////
template <typename ElemType>
int SqList<ElemType>::get_length ()
{
	return this->iLength;
}





///////////////////////////////////////////////////////////
template <typename ElemType>
bool SqList<ElemType>::get_elem_data_value (
		int iIndex, 
		ElemType& elem_data
)
{
	if (iIndex < 0 || iIndex >= this->iLength)
	{
		return false;
	}
	else
	{
		elem_data = this->iData[iIndex];
		return true;
	}
}


