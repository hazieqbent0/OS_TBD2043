#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    int count;
    std::cout << "Enter number of files: ";
    std::cin >> count;

    std::vector<std::string> fname(count);
    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter file " << (i + 1) << " name: ";
        std::cin >> fname[i];
    }

    
    sf::RenderWindow window(sf::VideoMode(800, 600), "File Directory Visualization");
    window.setFramerateLimit(60);

    
    sf::RectangleShape root(sf::Vector2f(150, 50));
    root.setFillColor(sf::Color(200, 100, 200));
    root.setPosition(325, 80);

    
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"); 
    

    
    sf::Text rootText("ROOT DIRECTORY", font, 16);
    rootText.setFillColor(sf::Color::Black);
    rootText.setPosition(340, 95);

    
    float mid = 800.0f / (count + 1);
    float x = mid;
    float y = 300;

    
    std::vector<sf::CircleShape> circles(count);
    std::vector<sf::Text> labels(count);
    std::vector<sf::VertexArray> lines(count, sf::VertexArray(sf::Lines, 2));

    for (int i = 0; i < count; i++, x += mid)
    {
        
        circles[i].setRadius(30);
        circles[i].setFillColor(sf::Color(100, 150, 255));
        circles[i].setOrigin(30, 30);
        circles[i].setPosition(x, y);

        
        labels[i].setFont(font);
        labels[i].setString(fname[i]);
        labels[i].setCharacterSize(14);
        labels[i].setFillColor(sf::Color::Black);
        labels[i].setPosition(x - 20, y - 10);

        
        lines[i][0].position = sf::Vector2f(400, 130);
        lines[i][0].color = sf::Color::Black;
        lines[i][1].position = sf::Vector2f(x, y - 30);
        lines[i][1].color = sf::Color::Black;
    }

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(100, 200, 100));  

        window.draw(root);
        window.draw(rootText);

        for (int i = 0; i < count; i++)
        {
            window.draw(lines[i]);
            window.draw(circles[i]);
            window.draw(labels[i]);
        }

        window.display();
    }

    return 0;
}