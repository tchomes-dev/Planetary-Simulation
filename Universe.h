#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <math.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>


using namespace std;
using namespace sf;


class Universe {
public:
    class CelestialBody : public Drawable {
    public:
        double t;


        //getters
        string getFileName() { return fileName; }
        double getMass() { return mass; }
        double getXPos() { return xPos; }
        double getYPos() { return yPos; }
        double getXVel() { return xVel; }
        double getYVel() { return yVel; }


        //setters
        void setXPos(double xPos) { this->xPos = xPos; }
        void setYPos(double yPos) { this->yPos = yPos; }
        void setXVel(double xVel) { this->xVel = xVel; }
        void setYVel(double yVel) { this->yVel = yVel; }


        //other
        void loadImage();
        void updatePosition(float x, float y, float radius);
        friend istream& operator>>(istream& input,
            CelestialBody& obj);
        friend ostream& operator<<(std::ostream& os,
            CelestialBody& cb);
        virtual void draw(RenderTarget& target, RenderStates
            states) const;


    private:
        double xPos = 0, yPos = 0, xVel = 0, yVel = 0, mass = 0;
        string fileName;
        Sprite planet;
        Texture planet_texture;
    };
    Universe(string file);
    void readFile(istream& in);
    int getNumPlanets() { return this->numPlanets; }
    double getRadius() { return this->radius; }
    vector<shared_ptr<CelestialBody>> getUniverse();
    void step(double t, Window& window);
private:
    int numPlanets;
    double radius;
    vector<shared_ptr<CelestialBody>> system;
};
