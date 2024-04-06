//
// Created by arthur on 05/04/2023.
//


#ifndef CONCERTO_EDITOR_EDITORAPPLICATION_HPP
#define CONCERTO_EDITOR_EDITORAPPLICATION_HPP

#include <memory>
#include <juce_gui_basics/juce_gui_basics.h>

namespace Concerto
{
    class EditorApplication : public juce::JUCEApplication
    {
    public:
        const juce::String getApplicationName() override;
        const juce::String getApplicationVersion() override;
        bool moreThanOneInstanceAllowed() override;
        void initialise(const juce::String& commandLine) override;
        void shutdown() override;

        class EditorAppWindow final : public juce::DocumentWindow
        {
        public:
            EditorAppWindow() = default;
            EditorAppWindow(EditorAppWindow&&) = delete;
            EditorAppWindow(const EditorAppWindow&) = delete;

            EditorAppWindow& operator=(EditorAppWindow&&) = delete;
            EditorAppWindow& operator=(const EditorAppWindow&&) = delete;

            EditorAppWindow(const juce::String& name);
            void closeButtonPressed() const;
        private:
            std::unique_ptr<juce::Component> _taskBarIcon;
        };
    private:
        std::unique_ptr<EditorAppWindow> _mainWindow;
    };
}

#endif // CONCERTO_EDITOR_EDITORAPPLICATION_HPP