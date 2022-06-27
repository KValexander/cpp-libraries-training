/* Include libraries */
#include <wx/wx.h>

/* Cosntants */
#define WIDTH 450
#define HEIGHT 450

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Contexts */
	void OnPaint(wxPaintEvent &event);

};