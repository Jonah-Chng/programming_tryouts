// g++ -std=c++11 main.cpp $(pkg-config --libs --cflags sfml-graphics sfml-window)

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>

int main()
{
    const unsigned width = 1024;
    const unsigned height= 768;

    // create the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Some Funky Title");

    // create a texture
    sf::Texture texture;
    texture.create(width, height);

    // Create a pixel buffer to fill with RGBA data
    unsigned char *pixbuff = new unsigned char[width * height * 4];
    // Create uint32_t pointer to above for easy access as RGBA
    uint32_t * intptr = (uint32_t *)pixbuff;

    // The colour we will fill the window with
    unsigned char red  = 0;
    unsigned char blue = 255;

    // run the program as long as the window is open
    int frame = 0;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // Create RGBA value to fill screen with.
        // Increment red and decrement blue on each cycle. Leave green=0, and make opaque
        uint32_t RGBA;
        RGBA = (red++ << 24) | (blue-- << 16) | 255;
        // Stuff data into buffer
        for(int i=0;i<width*height;i++){
           intptr[i] = RGBA;
        }
        // Update screen
        texture.update(pixbuff);
        sf::Sprite sprite(texture);
        window.draw(sprite);

        // end the current frame
        window.display();
        std::cout << "Frame: " << frame << std::endl;
        frame++;
        if(frame==1000)break;
    }

    return 0;
}