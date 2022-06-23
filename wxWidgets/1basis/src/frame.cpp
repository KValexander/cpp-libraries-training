/* Include headers */
#include "frame.hpp"

/* Constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Menubar */
	MenuBar();

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* BoxSizer */
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

	/* Buttons */
	wxButton *btn_ok = new wxButton(panel, -1, wxT("Ok")); 
	wxButton *btn_cancel = new wxButton(panel, -1, wxT("Cancel"));

	/* Add elements to boxsizer */
	hbox1->Add(new wxPanel(panel, -1));
	vbox->Add(hbox1, 1, wxEXPAND);

	hbox2->Add(btn_ok);
	hbox2->Add(btn_cancel);

	/* Sizer align:
		wxALIGN_LEFT
		wxALIGN_RIGHT
		wxALIGN_TOP
		wxALIGN_BOTTOM
		wxALIGN_CENTER_VERTICAL
		wxALIGN_CENTER_HORIZONTAL
		wxALIGN_CENTER
	*/
	vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

	/* Set sizer */
	panel->SetSizer(vbox);

	/* Textarea */
	// textctrl = new wxTextCtrl(panel, -1, wxT(""), wxDefaultPosition, wxSize(250, 150), wxTE_MULTILINE);

	/* Frame align */
	Centre();

}

/* Menubar */
void Frame::MenuBar()
{

	/* Menubar */
	menubar = new wxMenuBar;
	menu_file = new wxMenu;
	menu_edit = new wxMenu;
	menu_help = new wxMenu;

	/* Append menus to menubar */ 
	menubar->Append(menu_file, wxT("&File"));
	menubar->Append(menu_edit, wxT("&Edit"));
	menubar->Append(menu_help, wxT("&Help"));

	/* Set menu bar */
	SetMenuBar(menubar);

}