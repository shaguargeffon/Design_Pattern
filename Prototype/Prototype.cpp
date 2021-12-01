#include <iostream>

using namespace std;


class House
{
public:    
    virtual House* clone() const = 0;
    virtual ~House()
    {
    }
    
    virtual void print() const = 0;
   
};


class Big_House: public House
{
public:    
    
    explicit Big_House(const string window, const string door)
    {
        big_window = window;
        big_door = door;
    }
    
    virtual House* clone() const
    {
        return new Big_House(*this);
    }
    
    virtual void print() const
    {
        cout<<big_window<<endl;
        cout<<big_door<<endl;
    }
    

private:
    string big_window;
    string big_door;
    
};



class Small_House: public House
{
public:    
    
    explicit Small_House(const string window, const string door)
    {
        small_window = window;
        small_door = door;
    }
    
    virtual House* clone() const
    {
        return new Small_House(*this);
    }

    virtual void print() const
    {
        cout<<small_window<<endl;
        cout<<small_door<<endl;
    }

private:
    string small_window;
    string small_door; 
    
    
};


void app_platform(House* h)
{
    h->print();
        
}



int main(int argc, char **argv)
{

    Big_House bh = Big_House("big_window", "big_door");
    
    House* p = bh.clone();
    
    app_platform(p);
   
    delete p;
   
    
    Small_House sh = Small_House("small_window", "small_door");
    
    House* p_s = sh.clone();
    
    app_platform(p_s);
   
    delete p_s;
   
   
	return 0;
}
