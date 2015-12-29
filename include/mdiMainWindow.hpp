#ifndef mdiMainWindow_hpp
#define mdiMainWindow_hpp

#include <axLib/axLib.h>

#include "mdiGridWindow.hpp"
#include "mdiInspectorMenu.hpp"
#include "mdiStatusBar.hpp"
#include "mdiWidgetMenu.hpp"

#include "CodeEditor.h"

namespace mdi {
class MainWindow : public ax::Window::Backbone {
public:
	MainWindow(const ax::Rect& rect);

private:
	std::shared_ptr<StatusBar> _statusBar;
	std::shared_ptr<WidgetMenu> _widgetMenu;
	std::shared_ptr<GridWindow> _gridWindow;
	std::shared_ptr<TextEditor> _codeEditor;
	std::shared_ptr<InspectorMenu> _inspectorMenu;
	std::vector<ax::Window::Ptr> _selected_windows;

	typedef std::pair<std::string, ax::Point> ObjMsg;

	axEVENT_ACCESSOR(ax::Event::SimpleMsg<ObjMsg>, OnCreateDraggingWidget);
	axEVENT_ACCESSOR(ax::Event::SimpleMsg<ax::Point>, OnDraggingWidget);
	axEVENT_ACCESSOR(ax::Event::SimpleMsg<ax::Point>, OnReleaseObjWidget);
	
	void OnCreateDraggingWidget(const ax::Event::SimpleMsg<ObjMsg>& msg);
	void OnDraggingWidget(const ax::Event::SimpleMsg<ax::Point>& msg);
	void OnReleaseObjWidget(const ax::Event::SimpleMsg<ax::Point>& msg);

	void OnResize(const ax::Size& size);

	void OnPaint(ax::GC gc);
};
}

#endif /* mdiMainWindow_hpp */