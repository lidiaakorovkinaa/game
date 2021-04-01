#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
class Game {
public:
    int shirt;
    int trousers;
    int shoes;

    std::string shirtVariant = "..\\img\\firstShirt.png";
    std::string trousersVariant ="..\\img\\firstTrousers.png";
    std::string shoesVariant = "..\\img\\firstShoes.png";

    void  shirtChange(){
        int a = 1;
        int b = 2;
        shirt = rand() % (b - a + 1) + a;
        switch (shirt){
            case 1:
                shirtVariant = "..\\img\\firstShirt.png";
                break;
            case 2:
                shirtVariant = "..\\img\\secondShirt.png";
                break;
        }
    }

    void  trousersChange(){
        int a = 1;
        int b = 2;
        trousers = rand() % (b - a + 1) + a;
        switch (trousers){
            case 1:
                trousersVariant = "..\\img\\firstTrousers.png";
                break;
            case 2:
                trousersVariant = "..\\img\\secondTrousers.png";
                break;
        }
    }

    void shoesChange(){
        int a = 1;
        int b = 2;
        shoes = rand() % (b - a + 1) + a;
        switch (shoes){
            case 1:
                shoesVariant = "..\\img\\firstShoes.png";
                break;
            case 2:
                shoesVariant = "..\\img\\secondShoes.png";
                break;
        }
    }

    void check(){
        std::cout <<"shirt:"<< shirt <<  "\n";
        std::cout <<"trousers:"<< trousers <<  "\n";
        std::cout <<"shoes:"<< shoes <<  "\n";
        }


    void start() {
        sf::RenderWindow window(sf::VideoMode(500, 600), "My game!");


        sf::Texture textureForMan;
        sf::Texture textureForShirt;
        sf::Texture textureForTrousers;
        sf::Texture textureForShoes;


        textureForMan.loadFromFile("..\\img\\nude.png");
        textureForShirt.loadFromFile(shirtVariant);
        textureForTrousers.loadFromFile(trousersVariant);
        textureForShoes.loadFromFile(shoesVariant );

        sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
        rectangle.setPosition(200.f, 10.f);



        sf::RectangleShape man(sf::Vector2f(136.f, 293.f));
        man.setPosition(200.f, 100.f);
        man.setTexture(&textureForMan);

        sf::RectangleShape shirt(sf::Vector2f(137.f, 183.f));
        shirt.setPosition(200.f, 186.f);
        shirt.setTexture(&textureForShirt);

        sf::RectangleShape trousers(sf::Vector2f(93.f, 178.f));
        trousers.setPosition(225.f, 350.f);
        trousers.setTexture(&textureForTrousers);

        sf::RectangleShape shoes(sf::Vector2f(94.f, 29.f));
        shoes.setPosition(226.f, 527.f);
        shoes.setTexture(&textureForShoes);






        while (window.isOpen())
        {
            sf::Event event{};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

                    shirtChange();
                    trousersChange();
                    shoesChange();
                    check();
                    textureForShirt.loadFromFile(shirtVariant);
                    textureForTrousers.loadFromFile(trousersVariant);
                    textureForShoes.loadFromFile(shoesVariant);
                }

            }
            window.clear(sf::Color(100,0,230));
            window.draw(trousers);
            window.draw(man);
            window.draw(shirt);
            window.draw(shoes);
            window.display();
        }
    }
};

int main() {
    Game obj;
    obj.start();
    return 0;
}