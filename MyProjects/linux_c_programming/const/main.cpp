#include <iostream>

using namespace std;

class Number
{
    private:
        int* data;
        int size;
    public:
        ~Number();
        void set_size(int size);
        bool is_empty() const;
        void set_all_value(int num);
        void set_value(int id, int num);
        void show_value(int id) const;
        void show_all_value() const;
        int get_value(int id) const;
        void make_clear();
};

Number::~Number()
{
    if (!is_empty())
    {
        delete[] data;
    }
    // delet[] data;
}

void Number::set_size(int size)
{
    this -> size = size;
    data = new int[size];
}

bool Number::is_empty() const
{
    return size == 0;
}

void Number::set_all_value(int num)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = num;
    }
}

void Number::set_value(int id, int num)
{
    data[id-1] = num;
}

void Number::show_value(int id) const
{
    cout << data[id-1] << endl;
} 

void Number::show_all_value() const
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int Number::get_value(int id) const
{
    return data[id-1];
}

void Number::make_clear()
{
    size = 0;
    delete[] data;
}

int main()
{
    Number number;
    number.set_size(10);
    number.set_all_value(12);
    number.set_value(2, 10);
    number.set_value(5, 8);
    number.show_value(5);
    number.show_all_value();
    cout << number.get_value(5) << endl;
    number.make_clear();
    if (number.is_empty())
    {
        cout << "is empty!" << endl;
    }
    else
    {
        cout << "is not empty!" << endl;
    }
    return 0;
}

// end 
// iCoding

