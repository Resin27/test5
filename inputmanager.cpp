#include "inputmanager.h"

InputManager::InputManager()
{
    /*Parser parser("config.lua");

    inputBinding[INPUT_UP] = parser.getKey("control", "up");
    inputBinding[INPUT_DOWN] = parser.getKey("control", "down");
    inputBinding[INPUT_LEFT] = parser.getKey("control", "left");
    inputBinding[INPUT_RIGHT] = parser.getKey("control", "right");
    inputBinding[INPUT_INTERACT] = parser.getKey("control", "interact");
    inputBinding[INPUT_JUMP] = parser.getKey("control", "jump");
    inputBinding[INPUT_GUARD] = parser.getKey("control", "guard");
    inputBinding[INPUT_ATTACK] = parser.getKey("control", "attack");
    inputBinding[INPUT_SPECIAL] = parser.getKey("control", "special");
    inputBinding[INPUT_DASH] = parser.getKey("control", "dash");
    inputBinding[INPUT_START] = parser.getKey("control", "start");
    inputBinding[INPUT_SELECT] = parser.getKey("control", "select");*/

    //~Parser();

    for(int i = 0; i < NUM_OF_INPUTS; i++)
    {
        inputRegister[i].device = KEYBOARD;
        inputRegister[i].isPressed = false;
    }

    inputRegister[INPUT_UP].key = sf::Keyboard::Key::Up;
    inputRegister[INPUT_DOWN].key = sf::Keyboard::Key::Down;
    inputRegister[INPUT_LEFT].key = sf::Keyboard::Key::Left;
    inputRegister[INPUT_RIGHT].key = sf::Keyboard::Key::Right;
    inputRegister[INPUT_INTERACT].key = sf::Keyboard::Key::Z;
    inputRegister[INPUT_JUMP].key = sf::Keyboard::Key::Space;
    inputRegister[INPUT_GUARD].key = sf::Keyboard::Key::A;
    inputRegister[INPUT_ATTACK].key = sf::Keyboard::Key::S;
    inputRegister[INPUT_SPECIAL].key = sf::Keyboard::Key::D;
    inputRegister[INPUT_DASH].key = sf::Keyboard::Key::F;
    inputRegister[INPUT_START].key = sf::Keyboard::Key::Return;
    inputRegister[INPUT_SELECT].key = sf::Keyboard::Key::BackSpace;

    ///This was to test whether the bindings worked with the mouse, which they do!
    ///inputRegister[INPUT_SELECT].device = MOUSE;
    ///inputRegister[INPUT_SELECT].mouseButton = sf::Mouse::Button::Left;

    sf::Joystick::update();
    for(unsigned int i = 0; i < 8; i++)
    {
        if(sf::Joystick::isConnected(i))
        {
            joystick = i;
            numButtons = sf::Joystick::getButtonCount(i);
            //int numAxes = sf::Joystick::AxisCount;
            //std::cout << "Joystick " << i << " has " << numAxes << " axes." << std::endl;
            std::cout << "Joystick " << i << " has " << numButtons << " buttons." << std::endl;
            std::cout << "Joystick " << i << " has " << (sf::Joystick::hasAxis(i, sf::Joystick::X) ? "an " : "no ") << "xAxis." << std::endl;
            std::cout << "Joystick " << i << " has " << (sf::Joystick::hasAxis(i, sf::Joystick::Y) ? "an " : "no ") << "yAxis." << std::endl;
            std::cout << "Joystick " << i << " has " << (sf::Joystick::hasAxis(i, sf::Joystick::Z) ? "an " : "no ") << "zAxis." << std::endl;
            break;
        }
        //else
            //std::cout << "Joystick " << i << " not connected." << std::endl;
    }
}

void InputManager::configureBindings(sf::RenderWindow *window)
{
    sf::Event event;
    bool validInput;
    for(int i = 0; i < NUM_OF_INPUTS; i++)
    {
        std::cout << "Press the button you wish to bind to: " << inputToString(InputType(i)) << std::endl;
        validInput = false;
        while(window->waitEvent(event) && !validInput)
        {
            if(event.type == sf::Event::KeyPressed)
            {
                inputRegister[i].device = KEYBOARD;
                inputRegister[i].key = event.key.code;
                validInput = true;
            }
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                inputRegister[i].device = MOUSE;
                inputRegister[i].mouseButton = event.mouseButton.button;
                validInput = true;
            }

            else if(event.type == sf::Event::JoystickButtonPressed)
            {
                inputRegister[i].device = JOYSTICK_BUTTON;
                inputRegister[i].joystickButton = event.joystickButton.button;
                validInput = true;
            }
            else if(event.type == sf::Event::JoystickMoved)
            {
                inputRegister[i].device = JOYSTICK_AXIS;
                inputRegister[i].axis = event.joystickMove.axis;
                float direction = sf::Joystick::getAxisPosition(joystick, inputRegister[i].axis);
                if(direction >= 15)
                    inputRegister[i].direction = 1;
                else if(direction <= -15)
                    inputRegister[i].direction = -1;
                else
                    continue;
                validInput = true;
            }
            else
            {
                validInput = false;
            }
        }
    }
}

void InputManager::update()
{
    for(int i = 0; i < NUM_OF_INPUTS; i++)
    {
        bool keyState;
        switch(inputRegister[i].device)
        {
        case(KEYBOARD):
            keyState = sf::Keyboard::isKeyPressed(inputRegister[i].key);
            break;
        case(MOUSE):
            keyState = sf::Mouse::isButtonPressed(inputRegister[i].mouseButton);
            break;
        case(JOYSTICK_BUTTON):
            keyState = sf::Joystick::isButtonPressed(joystick, inputRegister[i].joystickButton);
            break;
        case(JOYSTICK_AXIS):
            keyState = (sf::Joystick::getAxisPosition(joystick, inputRegister[i].axis)*inputRegister[i].direction >= 15);
            break;
        default:
            keyState = false;
        }
        ///Really need to implement a sort of edge-triggering register, so make sure that button presses are only counted once.
        //bool keyState = sf::Keyboard::isKeyPressed(inputBinding[i]);

        inputRegister[i].isPressed = keyState;
    }
    ///This is used to print out the states of the keys.
    /*system("cls");
    for(int i = 0; i < NUM_OF_INPUTS; i++)
        std::cout << "Input " << i << " is " << (inputRegister[i].isPressed ? "" : "not ") << "pressed." << std::endl;
    std::cout << "\n";*/
}

std::string InputManager::inputToString(InputType inputType)
{
    switch(inputType)
    {
    case(INPUT_UP):
        return "Up";
        break;
    case(INPUT_DOWN):
        return "Down";
        break;
    case(INPUT_LEFT):
        return "Left";
        break;
    case(INPUT_RIGHT):
        return "Right";
        break;
    case(INPUT_INTERACT):
        return "Interact";
        break;
    case(INPUT_JUMP):
        return "Jump";
        break;
    case(INPUT_GUARD):
        return "Guard";
        break;
    case(INPUT_ATTACK):
        return "Attack";
        break;
    case(INPUT_SPECIAL):
        return "Special";
        break;
    case(INPUT_DASH):
        return "Dash";
        break;
    case(INPUT_START):
        return "Start";
        break;
    case(INPUT_SELECT):
        return "Select";
        break;
    default:
        return "Invalid input";
    }
}

std::string InputManager::deviceToString(DeviceType deviceType)
{
    switch(deviceType)
    {
    case(KEYBOARD):
        return "Keyboard";
        break;
    case(MOUSE):
        return "Mouse";
        break;
    case(JOYSTICK_BUTTON):
        return "Joystick Button";
        break;
    case(JOYSTICK_AXIS):
        return "Joystick Axis";
        break;
    default:
        return "Invalid Device";
    }
}

