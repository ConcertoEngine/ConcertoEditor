//
// Created by arthur on 05/04/2023.
//

#include "Concerto/Editor/EditorApplication.hpp"

const juce::String Concerto::EditorApplication::getApplicationName()
{
	return "ConcertoEditor";
}

const juce::String Concerto::EditorApplication::getApplicationVersion()
{
	return "0.0.1";
}

bool Concerto::EditorApplication::moreThanOneInstanceAllowed()
{
	return false;
}

void Concerto::EditorApplication::initialise(const juce::String& commandLine)
{
	_mainWindow = std::make_unique<EditorAppWindow>(getApplicationName());
}

void Concerto::EditorApplication::shutdown()
{
	_mainWindow = nullptr;
}

Concerto::EditorApplication::EditorAppWindow::EditorAppWindow(const juce::String& name) : juce::DocumentWindow(name, juce::Desktop::getInstance().getDefaultLookAndFeel()
	.findColour(ResizableWindow::backgroundColourId), DocumentWindow::allButtons)
{
	setUsingNativeTitleBar(true);
	setResizable(true, false);
	//setContentOwned(new MainComponent(), false);
	setVisible(true);
}

void Concerto::EditorApplication::EditorAppWindow::closeButtonPressed() const
{
	JUCEApplication::getInstance()->systemRequestedQuit();
}
