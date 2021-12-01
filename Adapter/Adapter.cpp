#include <iostream>
#include <string>

using namespace std;


/* 假设我们有一辆宝马的二手车，已经报废，但是零件还可以用
 * 现在有一辆奥迪车，正好需要几个零件，可以从宝马车上弄下来安上
 * 但是不能直接安装，需要进行转换和适配过程
 * 安装完成后组装奥迪车，任务完成
 * 缺失的零件暂时认为是灯，窗，轮胎
 * */


//首先可以先对这些零部件进行定义
//然后对这些零部件的接口进行抽象，注意，通常我们可以对每一个adaption构造一个类，有可能我们需要对好几个feature进行adapt
//定义具体的接口，到底客户需要一个什么样的接口来获得怎样的数据，需要搞清楚


class Tire
{
public:
    explicit Tire(string logo): logo(logo)
    {
        
    }
       
    string get_tire_logo(void) const
    {
        return logo;
    }
        
    void set_tire_logo(string logo)
    {
        this->logo = logo;
    }
    
    void print_logo() const
    {
        cout<<"The logo of tire is: "<<logo<<endl;
    }
    
private:
    string logo;
};


class Light
{
public:
    explicit Light(string logo): logo(logo)
    {
        
    }
    
    string get_light_logo(void) const
    {
        return logo;
    }
        
    void set_light_logo(string logo)
    {
        this->logo = logo;
    }
    
    void print_logo() const
    {
        cout<<"The logo of light is: "<<logo<<endl;
    }
    
private:
    string logo;
};




class Window
{
public:
    explicit Window(string logo): logo(logo)
    {
        
    }

    string get_window_logo(void) const
    {
        return logo;
    }
        
    void set_window_logo(string logo)
    {
        this->logo = logo;
    }
    
    void print_logo() const
    {
        cout<<"The logo of window is: "<<logo<<endl;
    }
    
private:
    string logo;
};




class TireInterface
{
public:
    virtual Tire* change_tire_logo() = 0;
    
    virtual ~TireInterface()
    {}
   
};


class LightInterface
{
public:
    virtual Light* change_light_logo() = 0;  
    virtual ~LightInterface()
    {}
};


class WindowInterface
{
public:
    virtual Window* change_window_logo() = 0;
    virtual ~WindowInterface()
    {}    
};



class AdaptTireInterface: public TireInterface
{
public:

    explicit AdaptTireInterface(Tire *p): t(p)
    {
        
    }

    virtual Tire* change_tire_logo()
    {
        t->set_tire_logo("Audi");
        return t;
    }
    
    ~AdaptTireInterface()
    {
        delete t;
    }

private:
    Tire *t;

};


class AdaptLightInterface: public LightInterface
{
public:

    explicit AdaptLightInterface(Light *p): l(p)
    {
        
    }


    virtual Light* change_light_logo()
    {
        l->set_light_logo("Audi");
        return l;
    }

    ~AdaptLightInterface()
    {
        delete l;
    }
 
   
private:
   Light *l;
   
};


class AdaptWindowInterface: public WindowInterface
{
public:

    explicit AdaptWindowInterface(Window *p): w(p)
    {
        
    }

    virtual Window* change_window_logo()
    {
        w->set_window_logo("Audi");
        return w;
    }
    
    ~AdaptWindowInterface()
    {
        delete w;
    }
    
private:
    Window *w;
   
};




int main(int argc, char **argv)
{
    //客户端应用程序
    Tire* bmw_tire_p = new Tire("BMW");
    Light* bmw_light_p = new Light("BMW");
    Window* bmw_window_p = new Window("BMW");
    
    //扔进去一个宝马轮胎，调用重写函数后出来的就应该是一个打着奥迪logo的轮胎
    AdaptTireInterface ti = AdaptTireInterface(bmw_tire_p);
    ti.change_tire_logo()->print_logo();
    
    
    //扔进去一个宝马灯，调用重写函数后出来的就应该是一个打着奥迪logo的灯
    AdaptLightInterface li = AdaptLightInterface(bmw_light_p);
    li.change_light_logo()->print_logo();

    //扔进去一个宝马窗户，调用重写函数后出来的就应该是一个打着奥迪logo的窗户
    AdaptWindowInterface wi = AdaptWindowInterface(bmw_window_p);
    wi.change_window_logo()->print_logo();
    
    //拿到三个指针后可以组装奥迪汽车或进行更进一步的算法, 此程序到这里就结束了
    //在三个析构函数中分别对三个指针进行delete
    
    
    
    
	return 0;
}
