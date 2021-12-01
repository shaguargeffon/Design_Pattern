#include <iostream>
#include <string>

using namespace std;


/*桥接模式通常用于当一个类出现多维变化的时候
 * 根据SRP原则，引起一个类的变化的原因应当只有一个
 * 但有些时候，在设计一个比较大的类时，最开始会将所有的属性添加到类的设计中
 * 这样一来引起类的变化就不止一个了，而是出现多维的组合
 * 举个例子，圣诞节糖果，有圆的，有方的，还有六边形的，但同时有的糖是红色的，有的是蓝色的
 * 有的糖是巧克力味道的，有的糖是奶油味道的等等，总之，引起糖果对象的变化是多维的且相互没有关联
 * 这样就不方便将所有的属性添加到一个类当中，而是将属性归类拿出来，利用桥接来建立这些
 * 属性之间的联系。
 *  
 * */

//类声明
class Form;
class Color;
class Taste;


//建立一个糖果类
class Bonbons
{
protected:  //之所以要用protected,是因为这些指针是要给糖果的子类用的
    Form* form;
    Color* color;
    Taste* taste;

public:
    virtual void check_Bonbons(void) = 0; //这里定义的接口是要给客户端用的，这里只是打印一些糖果信息供客户查看
    virtual ~Bonbons()
    {
        
    }
    
};


//建立其中一个形状属性, 抽象类
class Form
{
protected:    
    string form_name;
    
public:
    virtual string get_form(void) = 0;
    virtual int get_size() = 0;
    virtual ~Form()
    {
        
    }
};


//建立其中一个颜色属性, 抽象类
class Color
{
protected:    
    string color_name;
    
public:
    virtual string get_color(void) = 0;    
    virtual ~Color()
    {
        
    }
    
};


//建立其中一个味道属性, 抽象类
class Taste
{
protected:    
    string taste_name;
    
public:
    virtual string get_taste(void) = 0;    
    virtual ~Taste()
    {
        
    }
    
};


//从这里开始将实现具体类
//首先实现两个形状的具体类
//第一个是圆
class Circle: public Form
{
public:
    Circle(string form, int rad): radius(rad) 
    {
        this->form_name = form;
    }

    virtual string get_form()
    {
        return this->form_name;
    }
    
    virtual int get_size()
    {
        return int(radius*radius*3.14);
    }
    
    
private:
    int radius;    
};


//第二个是方
class Squre: public Form
{
public:
    Squre(string form, int width): width(width) 
    {
        this->form_name = form;
    }

    virtual string get_form()
    {
        return this->form_name;
    }
    
    virtual int get_size()
    {
        return width*width;
    }
    
    
private:
    int width;    
};




//然后开始写Color的具体类
//实现一个红色
class Red: public Color
{
public:
    Red(string color_name)
    {
        this->color_name = color_name;
    }


    virtual string get_color()
    {
        return color_name;
    }    
    
    
};

//实现一个蓝色
class Blue: public Color
{
public:
    Blue(string color_name)
    {
        this->color_name = color_name;
    }


    virtual string get_color()
    {
        return color_name;
    }    
    
    
};



//最后实现味道的具体类
//巧克力味道
class Chocolate: public Taste
{
public:
    Chocolate(string taste_name)
    {
        this->taste_name = taste_name;
    }


    virtual string get_taste()
    {
        return taste_name;
    }   
    
};


//牛奶味道
class Milk: public Taste
{
public:
    Milk(string taste_name)
    {
        this->taste_name = taste_name;
    }


    virtual string get_taste()
    {
        return taste_name;
    }   
    
};


//实现一个Bonbons的具体类
class BI: public Bonbons
{

public:

    BI(Form* form, Color* color, Taste* taste)
    {
        this->form = form;
        this->color = color;
        this->taste = taste;
    }

    virtual void check_Bonbons()
    {
        cout<<"The form of the Bonbons is: "<<form->get_form()<<endl;
        cout<<"The size of the Bonbons is: "<<form->get_size()<<endl;
        cout<<"The color of the Bonbons is: "<<color->get_color()<<endl;
        cout<<"The taste of the Bonbons is: "<<taste->get_taste()<<endl;
    }
   
};


//客户端框架
void check(Bonbons *p)
{
    p->check_Bonbons();
}


int main()
{
    //这里其实就是做糖果的过程了，添加大小，味道和颜色
    Chocolate bonbons_taste("chocolate");
    Blue bonbons_color("Blue");
    Circle bonbos_form("circle", 100);
    
    Bonbons* b = new BI(&bonbos_form, &bonbons_color, &bonbons_taste);
      
    //客户端程序
    check(b);

    //测试程序，在这里回收指针
    delete b;
    
	return 0;
}
