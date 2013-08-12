#include "Head.h"


template <typename ElemType>
class Stack
{
	private:
		ElemType *data;
		int size;
		int bottom;
		int top;
	public:
		Stack ();
		void push (ElemType elem);
		ElemType pop ();
		bool is_empty ();
		bool is_full ();
		int get_size ();
		void expand_size ();
};


// end 
// iCoding@CodeLab
//

