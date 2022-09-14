#ifndef STAGE_VIEW_EVENTS_H_INCLUDED
#define STAGE_VIEW_EVENTS_H_INCLUDED

#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class StageEventReceiver : public IEventReceiver
{
public:
    // We'll create a struct to record info on the mouse state
    struct SMouseState
    {
        core::position2di Position;
        bool LeftButtonDown;
        SMouseState() : LeftButtonDown(false) { }
    } MouseState;

    ICameraSceneNode* camera;

    void setCamera(ICameraSceneNode* cam_node)
    {
        camera = cam_node;
    }

    void processCameraState()
    {
    }

    // This is the one method that we have to implement
    virtual bool OnEvent(const SEvent& event)
    {
        // Remember the mouse state
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
        {
            switch(event.MouseInput.Event)
            {
            case EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LeftButtonDown = true;
                break;

            case EMIE_LMOUSE_LEFT_UP:
                MouseState.LeftButtonDown = false;
                break;

            case EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;

            default:
                // We won't use the wheel
                break;
            }
        }

        // The state of each connected joystick is sent to us
        // once every run() of the Irrlicht device.  Store the
        // state of the first joystick, ignoring other joysticks.
        // This is currently only supported on Windows and Linux.
        if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
            && event.JoystickEvent.Joystick == 0)
        {
            JoystickState = event.JoystickEvent;
        }

        return false;
    }

    const SEvent::SJoystickEvent & GetJoystickState(void) const
    {
        return JoystickState;
    }

    const SMouseState & GetMouseState(void) const
    {
        return MouseState;
    }


    StageEventReceiver()
    {
        camera = NULL;
    }

private:
    SEvent::SJoystickEvent JoystickState;
};

#endif // STAGE_VIEW_EVENTS_H_INCLUDED
