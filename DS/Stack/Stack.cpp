#include "Stack.h"

///////////////////////////////////////////////////////////
// Stack
template <typename ElemType>
Stack<ElemType>::Stack ()
{
	this->size   = DEFAULT_STACK_SIZE;
	this->data   = new ElemType[this->size+1];
	this->bottom = 0;
	this->top    = 0;
}

///////////////////////////////////////////////////////////
// push 
template <typename ElemType>
void Stack<ElemType>::push (ElemType elem)
{
	if (is_full())
	{
		expand_size ();
	}
	this->top++;
	this->data[this->top] = elem;
}
///////////////////////////////////////////////////////////
// pop
template <typename ElemType>
ElemType Stack<ElemType>::pop ()
{
	ElemType elem_top;
	elem_top = this->data[this->top];
	this->top--;
	return elem_top;
}
///////////////////////////////////////////////////////////
// is empty
template <typename ElemType>
bool Stack<ElemType>::is_empty ()
{
	return (this->bottom >= this->top);
}

///////////////////////////////////////////////////////////
// is full
template <typename ElemType>
bool Stack<ElemType>::is_full ()
{
	return (this->size <= this->top);
}

///////////////////////////////////////////////////////////
// get size of Stack
template <typename ElemType>
int Stack<ElemType>::get_size ()
{
	return (this->top - this->bottom);
}

///////////////////////////////////////////////////////////
// expand_size
template <typename ElemType> 
void Stack<ElemType>::expand_size ()
{
	ElemType* elem_data_tmp;
	elem_data_tmp = new ElemType[this->size+1];
	for (int i = this->bottom + 1; i <= this->top; i++)
	{
		elem_data_tmp[i] = this->data[i];
	}
	delete[] this->data;
	this->size += DEFAULT_STACK_SIZE;
	this->data = new ElemType[this->size+1];
	for (int i = this->bottom + 1; i <= this->top; i++)
	{
		this->data[i] = elem_data_tmp[i];
	}
}

// end 
// iCoding@CodeLab
//

