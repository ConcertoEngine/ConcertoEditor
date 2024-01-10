//
// Created by arthur on 10/01/2024.
//

#include <Concerto/Core/Assert.hpp>

#include "Concerto/Editor/EWindow.hpp"


namespace Concerto
{
	EWindow::EWindow(ultralight::Monitor* monitor, UInt32 width, UInt32 height, std::string_view title,	UInt32 flags, bool fullscreen) :
		_window(ultralight::Window::Create(monitor, width, height, fullscreen, flags))
	{
		CONCERTO_ASSERT(_window.get() != nullptr);
		_window->SetTitle(title.data());
	}
}
