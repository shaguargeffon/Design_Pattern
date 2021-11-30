#include <iostream>

using namespace std;

class House
{
    private:
        int size;

    protected:
        House(int size): size(size)
        {

        }
    
        House(House& house)
        {
            
        }
   
    public:
        // This implementation is only valid for single thread.
        static House* get_House_Instance(int size)
        {
            if(pt == nullptr)
            {
                pt = new House(size);
            }
            
            return pt;
        }
        
        //This implementation is valid for multi-thread, but there is still a reorder issue.
        static House* get_House_Instance_multithread(int size)
        {
            if(pt == nullptr)
            {
                //Critical section entry
                if(pt == nullptr)
                {
                    pt = new House(size);
                }
            }
            //Critical section left
            return pt;
        }
        
        
        
        static House* pt;
        
        int get_size() const
        {
            return size;
        }
    
};

House* House::pt = nullptr;


int main(int argc, char **argv)
{
    House* obj = House::get_House_Instance(100);
    cout<<obj->get_size()<<endl;
    
	return 0;
}
