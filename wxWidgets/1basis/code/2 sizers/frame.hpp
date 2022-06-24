/* Include libraries */
#include <wx/wx.h>
#include <wx/menu.h>

/* Constants */
#define WIDTH 450
#define HEIGHT 450

/* Class Frame extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Menubar */
	void MenuBar();

	/* Box sizer */
	void BoxSizer();

	/* Grid sizer */
	void GridSizer();

	/* Flex grid sizer */
	void FlexGridSizer();

};