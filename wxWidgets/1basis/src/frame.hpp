/* Include libraries */
#include <wx/wx.h>

/* Cosntants */
#define WIDTH 250
#define HEIGHT 250

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Quit */
	void OnQuit(wxCommandEvent &event);

};