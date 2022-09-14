#include <wx/wx.h>
#include <wx/toolbar.h>
#include <windows.h>
#include <irrlicht.h>
#include "wxIrrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

BEGIN_EVENT_TABLE(wxIrrlicht, wxControl)
    EVT_TIMER(ID_IRR_TIMER, wxIrrlicht::OnTimer)
    EVT_SIZE(wxIrrlicht::OnSize)
    EVT_PAINT(wxIrrlicht::OnPaint)
    EVT_ERASE_BACKGROUND(wxIrrlicht::OnEraseBackground)
    EVT_MOUSE_EVENTS(wxIrrlicht::OnMouse)
    EVT_KEY_DOWN(wxIrrlicht::OnKey)
    EVT_KEY_UP(wxIrrlicht::OnKey)
END_EVENT_TABLE()

wxIrrlicht::wxIrrlicht(wxWindow* parent, wxWindowID id, bool bs, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
	: wxControl(parent, id, pos, size, style, wxDefaultValidator, name),
	m_pDevice(0),
    m_pDriver(0),
    m_pSceneManager(0),
    m_pGuiEnvironment(0),
    m_pCameraNode(0),
    m_Timer(this, ID_IRR_TIMER),
    m_pFPSText(0),
	m_showFPS(bs) {
	    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
}//ctor

wxIrrlicht::~wxIrrlicht() {
	m_pDevice->drop();
}//dtor

void wxIrrlicht::InitIrr(irr::SIrrlichtCreationParameters* init_params) {
    SIrrlichtCreationParameters params;
    params.DriverType = EDT_OPENGL;

    view_stage_tool_texture = NULL;

    SIrrlichtCreationParameters* actual_params = init_params ? init_params : &params;
    dimension2d<u32> irrSize(GetClientSize().GetX(), GetClientSize().GetY());
    actual_params->WindowSize = irrSize;

#ifdef LINUX
    wxStaticText* pnl = new wxStaticText(this, -1, wxEmptyString);
    pnl->SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    GtkWidget* handle = pnl->GetHandle();
    if (!handle)
        return;
    XID xHandle = GDK_WINDOW_XWINDOW(handle->window);
    Display* mDisp = GDK_WINDOW_XDISPLAY(handle->window);
    stringc dName = (long)mDisp;
    dName += ':';
    dName += (int)xHandle;
    actual_params->WindowId = (long)dName.c_str();
#else
    actual_params->WindowId = (HWND)this->GetHandle();
#endif

    m_pDevice = createDeviceEx(*actual_params);

    if (!m_pDevice) {
        throw "Can't create Irrlicht device!";
	}//if

	m_pDriver = m_pDevice->getVideoDriver();
	m_pSceneManager = m_pDevice->getSceneManager();
	m_pGuiEnvironment = m_pDevice->getGUIEnvironment();

    OnCreateScene();

    m_pDriver->OnResize(irrSize);
}//InitIrr()

void wxIrrlicht::StartRendering(int milliseconds) {
    m_Timer.Start(milliseconds);
}//StartRendering()

void wxIrrlicht::StopRendering(){
    m_Timer.Stop();
}//StopRendering()

void wxIrrlicht::Render() {
    static bool rendering = false;

    if (rendering || !m_pDevice->run()) {
        return;
	}//if

    rendering = true;
    OnPreRender();
    OnRender();
    OnPostRender();
    rendering = false;
}//Render()

void wxIrrlicht::OnCreateScene() {
	if (m_showFPS) {
		m_pFPSText = m_pGuiEnvironment->addStaticText(L"FPS: 0", rect<s32>(1, 1, 50, 10), false);
		m_pFPSText->setOverrideColor(SColor(255,255,255,255));
	}//if
}//OnCreateScene()

void wxIrrlicht::OnRender() {
    m_pDriver->beginScene(true, true, SColor(0,255,255,255));
    m_pSceneManager->drawAll();
    m_pGuiEnvironment->drawAll();
    drawOverlay();
    m_pDriver->endScene();
}//OnRender()

void wxIrrlicht::OnPostRender() {
    if (m_pFPSText && m_showFPS) {
        int fps = m_pDriver->getFPS();

        static int lastFPS = 0;
        if (lastFPS != fps) {
            core::stringw str = L"FPS: ";
            str += fps;

            m_pFPSText->setText(str.c_str());
            lastFPS = fps;
        }//if
    }//if
}//OnPostRender()

void wxIrrlicht::OnPaint(wxPaintEvent& event){
    wxPaintDC paint_dc(this);

    Render();
}//OnPaint()

void wxIrrlicht::OnSize(wxSizeEvent& event) {
    if (!m_pDriver) {
        return;
	}//if

    s32 w;
    s32 h;

    GetClientSize(&w, &h);
    dimension2d<u32> size(w, h);
    m_pDriver->OnResize(size);

    if (m_pCameraNode) {
        m_pCameraNode->setAspectRatio((float)w / (float)h);
	}//if
}//OnSize

void wxIrrlicht::OnTimer(wxTimerEvent& event) {
    Render();
}

void wxIrrlicht::OnMouse(wxMouseEvent& event) {
    irr::SEvent sevt;

    sevt.EventType = irr::EET_MOUSE_INPUT_EVENT;

    if (event.IsButton()) {
        if (event.LeftDown())
        {
            sevt.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN;
            wxMessageBox(_("Mouse Button Pressed"));
        }
        else if (event.LeftUp())
            sevt.MouseInput.Event = irr::EMIE_LMOUSE_LEFT_UP;
        else if (event.MiddleDown())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_PRESSED_DOWN;
        else if (event.MiddleUp())
            sevt.MouseInput.Event = irr::EMIE_MMOUSE_LEFT_UP;
        else if (event.RightDown())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_PRESSED_DOWN;
        else if (event.RightUp())
            sevt.MouseInput.Event = irr::EMIE_RMOUSE_LEFT_UP;
    }//if

    else if (event.GetWheelRotation() != 0) {
        sevt.MouseInput.Wheel = (float)event.GetWheelRotation();
        sevt.MouseInput.Event = irr::EMIE_MOUSE_WHEEL;
    }//else if

    else if (event.Moving() || event.Dragging()) {
		sevt.MouseInput.Event = irr::EMIE_MOUSE_MOVED;
	}//else if

    sevt.MouseInput.X = event.GetX();
    sevt.MouseInput.Y = event.GetY();

    m_pDevice->postEventFromUser(sevt);

    if (!m_Timer.IsRunning()) {
        Render();
	}//if

    event.Skip();
}//OnMouse()

void wxIrrlicht::OnKey(wxKeyEvent& event) {
    irr::SEvent sevt;

    sevt.EventType = irr::EET_KEY_INPUT_EVENT;

    sevt.KeyInput.Key = (irr::EKEY_CODE)event.GetRawKeyCode();
    sevt.KeyInput.PressedDown = event.GetEventType() == wxEVT_KEY_DOWN;

    sevt.KeyInput.Shift = event.ShiftDown();
    sevt.KeyInput.Control = event.CmdDown();
#if wxUSE_UNICODE
    sevt.KeyInput.Char = event.GetUnicodeKey();
#else
    sevt.KeyInput.Char = event.GetKeyCode();
#endif

    m_pDevice->postEventFromUser(sevt);

    if (!m_Timer.IsRunning()) {
        Render();
	}//if

    event.Skip();
}//OnKey()



//OOS3D stuff
#define MAIN_TOOL_TOGGLE_VIEW 1
#define MAIN_TOOL_TOGGLE_SINGLE_SELECT 2
#define MAIN_TOOL_TOGGLE_BOX_SELECT 3
#define MAIN_TOOL_TOGGLE_ACTOR_MOVE 4
#define MAIN_TOOL_TOGGLE_ACTOR_ROTATE 5
#define MAIN_TOOL_TOGGLE_ACTOR_SCALE 6

int wxIrrlicht::getMainToolToggleState()
{
    if(m_view_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_VIEW;

    if(m_select_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_SINGLE_SELECT;

    if(m_boxSelect_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_BOX_SELECT;

    if(m_move_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_ACTOR_MOVE;

    if(m_rotate_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_ACTOR_ROTATE;

    if(m_scale_tool->IsToggled())
        return MAIN_TOOL_TOGGLE_ACTOR_SCALE;

    return 0;
}

void wxIrrlicht::drawOverlay()
{
    if(getMainToolToggleState()==MAIN_TOOL_TOGGLE_VIEW && view_stage_tool_texture != NULL)
        m_pDriver->draw2DImage(view_stage_tool_texture, position2d<s32>(100, 100));
}
