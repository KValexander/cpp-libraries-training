/* Include libraries */
#include <wx/wx.h>
#include <wx/menu.h>

/* Constants */
#define WIDTH 350
#define HEIGHT 250

/* Class Frame extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Menubar */
	void MenuBar();
	wxMenuBar 	*menubar;
	wxMenu 		*menu_file;
	wxMenu 		*menu_edit;
	wxMenu 		*menu_help;

	/* Textarea */
	wxTextCtrl 	*textctrl;

};