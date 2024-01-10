//
// Created by arthur on 10/01/2024.
//

#include <stdexcept>
#include <Ultralight/platform/Logger.h>
#include <Ultralight/platform/Platform.h>
#include <Concerto/Core/Logger.hpp>

#include "Concerto/Editor/Editor.hpp"

namespace
{
	class Logger : public ultralight::Logger
	{
	public:
		void LogMessage(ultralight::LogLevel logLevel, const ultralight::String& message) override
		{
			auto view = std::string_view(message.utf8().data(), message.utf8().size());
			switch (logLevel)
			{
			case ultralight::LogLevel::Error:
				Concerto::Logger::Error(view);
				break;
			case ultralight::LogLevel::Warning:
				Concerto::Logger::Warning(view);
				break;
			case ultralight::LogLevel::Info:
				Concerto::Logger::Info(view);
				break;
			default:
				break;
			}
		}
	};
}
namespace Concerto
{
	Editor* Editor::_instance = nullptr;



	Editor::Editor()
	{
		if (_instance != nullptr)
		{
			Logger::Error("Editor instance is already initialized.");
			CONCERTO_ASSERT_FALSE;
			throw std::runtime_error("Editor instance is already initialized.");
		}
		_instance = this;
		ultralight::Platform::instance().set_logger(new ::Logger());
		_app = ultralight::App::Create();
	}

	Editor* Editor::Instance()
	{
		if (_instance == nullptr)
		{
			Logger::Error("Editor instance is null, please initialize it before using it.");
			CONCERTO_ASSERT_FALSE;
		}
		return _instance;
	}

	EWindow& Editor::CreateWindow(UInt32 width, UInt32 height, std::string_view title, UInt32 flags, bool fullscreen)
	{
		_windows.emplace_back(_app->main_monitor(), width, height, title, flags, fullscreen);
		return _windows.back();
	}

	void Editor::Run() const
	{
		_app->Run();
	}
}
