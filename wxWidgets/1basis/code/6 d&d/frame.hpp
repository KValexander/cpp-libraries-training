/* Include libraries */
#include <wx/wx.h>
#include <wx/dnd.h>
#include <wx/listctrl.h>
#include <wx/dirctrl.h>

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

	/* Events */
	void OnSelect(wxCommandEvent &event);
	void OnDragInit(wxListEvent &event);

	/* Ctrls */
	wxGenericDirCtrl *gdc;
	wxListCtrl *lc1;
	wxListCtrl *lc2;

};

/* Target class extends wxTextDropTarget */
class Target : public wxTextDropTarget
{

/* Public */
public:

	/* Constructor */
	Target(wxListCtrl *owner);

	/* Drop text */
	virtual bool OnDropText(wxCoord x, wxCoord y, const wxString &data);

	/* Ctrl */
	wxListCtrl *owner;

};