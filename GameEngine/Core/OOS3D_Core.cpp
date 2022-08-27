#include "OOS3D_Core.h"


OOS3D_Window* OOS3D_WindowOpenEx(std::string game_name, SIrrlichtCreationParameters param)
{
    OOS3D_Window* win = new OOS3D_Window();
    //win->device =  createDeviceEx(param);
    //win->device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16, false, false, false, 0);

    return win;
}
