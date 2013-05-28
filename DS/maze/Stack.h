class Stack
{
	private:
		Point* data;
		int size;
		int bottom;
		int top;
	public:
		Stack ();
		void push (Point elem);
		Point pop ();
		bool is_empty ();
		bool is_full ();
};


