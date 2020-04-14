// TestWxWidgets.cpp : Define el punto de entrada de la aplicación.
//

#include "stdafx.h"
#include "Main.h"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}
MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World", { 0,0 }, { 1280, 1000 })
{
    //ShowFullScreen(true); // Show the window maximized but, without any close, minimize or maximize button.
    Maximize(true); // Show the window maximized
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    m_pmgr = new wxAuiManager(this);

    //wxPanel* pPanel = new wxPanel(this, wxID_ANY, { 0,0 }, GetSize() / 2);
    // Here is the TextBox
    wxTextCtrl* text = new wxTextCtrl(this, wxID_ANY, wxEmptyString, { 0, 0 }, {400, 400}, wxTE_MULTILINE | wxTE_RICH | wxTE_RICH2 | wxTE_AUTO_URL | wxHSCROLL);
    m_pmgr->AddPane(text);
    m_pmgr->Update();
    // Just for color format
    /*text->SetDefaultStyle(wxTextAttr(*wxRED));
    text->AppendText("Red text\n");
    text->SetDefaultStyle(wxTextAttr(wxNullColour, *wxLIGHT_GREY));
    text->AppendText("Red on grey text\n");
    text->SetDefaultStyle(wxTextAttr(*wxBLUE));
    text->AppendText("Blue on grey text\n");*/
    

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

MainFrame::~MainFrame()
{

    m_pmgr->UnInit();
    delete m_pmgr;

}
void MainFrame::OnExit(wxCommandEvent& event)
{
    
    Close(true);
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}