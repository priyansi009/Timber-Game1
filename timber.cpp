#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    VideoMode vm({1920, 1080});
    //RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
    RenderWindow window(vm, "Timber!!!");
    //View view(sf::FloatRect(0,0,1920,1080));
    View view({960.f, 540.f}, {1920.f, 1080.f});
    window.setView(view);

Texture textureBackground;
    if(!textureBackground.loadFromFile("graphics/background.png"))    {
        return -1; }
    Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition({0.f, 0.f});

Texture textureTree;
    if(!textureTree.loadFromFile("graphics/tree.png")) {
        return -1; }
    Sprite spriteTree(textureTree);
    spriteTree.setPosition({750.f, 0.f});


Texture textureBee;
    if(!textureBee.loadFromFile("graphics/bee.png"))  {
        return -1; }
    Sprite spriteBee(textureBee);
    spriteBee.setPosition({100.f, 600.f});
  
    spriteBee.setOrigin({
        textureBee.getSize().x / 2.f,
        textureBee.getSize().y / 2.f
    });  // Set origin for flipping

    // Bee movement variables
    float beeSpeed = 300.f;
    bool beeMovingRight = true;
    
    Clock clock;      // Clock for smooth movement


Texture textureCloud;
    if(!textureCloud.loadFromFile("graphics/cloud.png"))  {
        return -1; }
    Sprite spriteCloud1(textureCloud), spriteCloud2(textureCloud), spriteCloud3(textureCloud);
    spriteCloud1.setPosition({110.f, 100.f});
    spriteCloud2.setPosition({1110.f, 150.f});
    spriteCloud3.setPosition({1510.f, 210.f});

Texture textureBranch;
    if(!textureBranch.loadFromFile("graphics/branch.png")){
        return -1;  }
    Sprite spriteBranch(textureBranch);
    spriteBranch.setPosition({1000.f, 400.f});

Texture texturePlayer;
    if(!texturePlayer.loadFromFile("graphics/player.png"))  { 
         return -1; }
    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition({1100.f, 700.f});


    while(window.isOpen())
    {
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
            window.close();
        }


          // -------- BEE MOVEMENT --------
        float dt = clock.restart().asSeconds();
        Vector2f position = spriteBee.getPosition();
        if(beeMovingRight){
            position.x += beeSpeed * dt;
            spriteBee.setScale({-1.f,1.f});   // face right
            if(position.x > 1800){
                beeMovingRight = false;
                }
            }else{
            position.x -= beeSpeed * dt;
            spriteBee.setScale({1.f,1.f});  // face left

            if(position.x < 100){
                beeMovingRight = true;
            }
        }
        spriteBee.setPosition(position);
        //-----------------------------------

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteBranch);
        window.draw(spritePlayer);
        window.display();
    }

    return 0;
}