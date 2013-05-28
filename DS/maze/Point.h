
#define UP    0
#define RIGHT 1
#define DOWN  2
#define LEFT  3

#define DIR_COUNT 4

const bool CAN_GO   = true;
const bool CANNT_GO = false;

const bool BLANK = true;
const bool BLOCK = false;

const char ch_block = '#';
const char ch_blank = 'o';

class Point
{
	private:
		int x, y;
		bool value;
		bool used;
		bool dir[DIR_COUNT];
	public:
		Point ();
		void set_point (int x, int y);
		void set_value (char ch_flag);
		int get_x ();
		int get_y ();
};

