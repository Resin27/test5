#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

static const int NUM_OF_INPUTS = 12;
//static const int BUFFER_SIZE = 32;

enum DeviceType
{
    KEYBOARD,
    MOUSE,
    JOYSTICK_BUTTON,
    JOYSTICK_AXIS
};

enum InputType
{
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_INTERACT,
    INPUT_JUMP,
    INPUT_GUARD,
    INPUT_ATTACK,
    INPUT_SPECIAL,
    INPUT_DASH,
    INPUT_START,
    INPUT_SELECT
};

struct Input
{
    DeviceType device;

    union
    {
        sf::Keyboard::Key key;
        sf::Mouse::Button mouseButton;
        unsigned int joystickButton;
        struct
        {
            sf::Joystick::Axis axis;
            float direction;
        };
    };

    bool isPressed;

    sf::Time birth;
    sf::Time life;
};

///Class
class InputManager
{
protected:

    unsigned int joystick;
    unsigned int numButtons;

    Input inputRegister[NUM_OF_INPUTS];
    bool keyPressed[NUM_OF_INPUTS];
    bool keyRelease[NUM_OF_INPUTS];

    /*sf::Keyboard::Key inputBinding[NUM_OF_INPUTS];
    ///-------------------------------------------------------
    ///Let's rethink these arrays.
    ///There should clearly be a currentStateBuffer (inputRegister)
    ///Then have press and release edge-triggered arrays.
    ///-------------------------------------------------------
    bool inputRegister[NUM_OF_INPUTS];
    bool keyPressed[NUM_OF_INPUTS];
    bool keyReleased[NUM_OF_INPUTS];*/

public:

    InputManager();

    void configureBindings(sf::RenderWindow *window);

    void update();
    /*bool isInput(InputType inputType){return inputRegister[inputType].isPressed;}
    bool isKeyPressed(InputType inputType){return keyPressed[inputType];}
    bool isKeyReleased(InputType inputType){return keyReleased[inputType];}*/

    //bool isInput(InputType inputType){return inputRegister[inputType].isPressed;}

    Input* getRegister(){return inputRegister;}

    std::string inputToString(InputType inputType);
    std::string deviceToString(DeviceType deviceType);

};

#endif
