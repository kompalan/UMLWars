/**
 * @file MainFrame.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include "MainFrame.h"
#include "WarsView.h"

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
}

/**
 * Exit the Application
 * @param event Command Event Object
 */
void MainFrame::OnExit(wxCommandEvent& event)
{

}

/**
 * About Menu of the Application
 * @param event Command Event Object
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{

}

/**
 * Handler for when the Application is Closed
 * @param event Close Event Object
 */
void MainFrame::OnClose(wxCloseEvent& event)
{

}




