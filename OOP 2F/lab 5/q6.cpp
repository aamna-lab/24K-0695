#include <iostream>
using namespace std;

class GraphicsRenderingEngine{
    private:
    string type;
    public:
    GraphicsRenderingEngine(string t) : type(t){}
    string getType(){
        return type;
    }
};
class InputHandler{
    private:
    string type;
    public:
    InputHandler(string t) : type(t){}
    string getType(){
        return type;
    }
};
class PhysicsEngine{
    private:
    string type;
    public:
    PhysicsEngine(string t) : type(t){}
    string getType(){
        return type;
    }
};

class GameEngine{
    private:
    GraphicsRenderingEngine g;
    InputHandler i;
    PhysicsEngine p;
    public:
    GameEngine (string gtype,string itype, string ptype) : g(gtype), i(itype) , p(ptype){}
    void displayDetails() {
        cout << "Engine:" << endl;
        cout << "Graphics Rendering Engine: " << g.getType() << endl;
        cout << "Input Handler: " << i.getType() << endl;
        cout << "Physics Engine: " << p.getType() << endl;
    }

};
int main(){
    GameEngine ge("Example" , "Mouse" , "Physics");
   ge.displayDetails();
  
}
