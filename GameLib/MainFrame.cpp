/**
 * @file MainFrame.cpp
 * @author Anurag Kompalli
 */
#include "pch.h"
#include "MainFrame.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UMLWars", wxDefaultPosition, wxSize(1250, 1000));
}