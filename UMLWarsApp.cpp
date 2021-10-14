/**
 * @file UMLWarsApp.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include <MainFrame.h>
#include "UMLWarsApp.h"

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

/**
 * Initialize the UMLWars App
 * @return Boolean whether the App Initialized Successfully
 */
bool UMLWarsApp::OnInit()
{
#ifdef WIN32
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
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
