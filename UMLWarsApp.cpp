/**
 * @file UMLWarsApp.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
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

    return true;
}
