/**
 * @file UMLWarsApp.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include <MainFrame.h>
#include "UMLWarsApp.h"

/**
 * Initialize the UMLWars App
 * @return Boolean whether the App Initialized Successfully
 */
bool UMLWarsApp::OnInit()
{
    if (!wxApp::OnInit())
    {
        return false;
    }

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);


    return true;
}
