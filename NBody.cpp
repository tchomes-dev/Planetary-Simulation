#include "Universe.h"


int main(int argv, char* argc[]) {
    double steptime, runtime, currTime;
    steptime = 10000;
    currTime = steptime;
    runtime = 200000000;
    Universe milkyway("planets.txt");
    RenderWindow window(VideoMode(800, 800), "Planets");
    window.setFramerateLimit(300);

    Texture texture;
    if (!texture.loadFromFile("space.jpg"))
        return -1;


    Sprite background(texture);


    //Font font;
    //if (!font.loadFromFile("./RobotoCondensed-Light.ttf"))
        //return EXIT_FAILURE;


    for (auto planet : milkyway.getUniverse()) {
        planet.get()->updatePosition(window.getSize().x,
            window.getSize().y, milkyway.getRadius());
    }
    //Text text("Time elapsed: ", font, 15);
    //Text text2("", font, 15);
    while (window.isOpen())
    {
        //text2.setString(to_string(currTime));
        //text.setPosition(300, 0);
        //text2.setPosition(400, 0);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (runtime > 0) {
            milkyway.step(steptime, window);
        }
        if (runtime <= 0) {
            cout << milkyway.getNumPlanets() << endl;
            cout << milkyway.getRadius() << endl;
            for (auto planet : milkyway.getUniverse()) {
                cout << *planet;
            }
            break;
        }
        window.clear();
        window.draw(background);
        //window.draw(text);
        //window.draw(text2);
        for (auto planet : milkyway.getUniverse()) {
            window.draw(*planet);
        }
        window.display();
        runtime -= steptime;
        currTime += steptime;
    }
    return 0;
}
