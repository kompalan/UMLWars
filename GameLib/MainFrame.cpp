/**
 * @file MainFrame.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include "MainFrame.h"
#include "WarsView.h"
#include "ids.h"

using namespace std;
/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UMLWars", wxDefaultPosition, wxSize(1250, 1000));

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mGameView = new WarsView();
    mGameView->Initialize(this);

    sizer->Add(mGameView, 1, wxEXPAND | wxALL);
    SetSizer(sizer);

    Layout();


    auto menuBar = new wxMenuBar( );

    SetMenuBar( menuBar );

    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    mGameView->AddMenus(this, menuBar);
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit the program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Application about box menu handler
 */
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Welcome to UML Wars!",
            L"About the game",
            wxOK,
            this);
}

/**
 * Handler for when the Application is Closed
 * @param event Close Event Object
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}

