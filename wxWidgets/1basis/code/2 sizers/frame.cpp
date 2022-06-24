/* Include headers */
#include "frame.hpp"

/* Constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Menubar */
	MenuBar();

	/* Box sizer */
	// BoxSizer();

	/* Grid sizer */
	// GridSizer();

	/* Flex grid sizer */
	FlexGridSizer();

	/* Frame align */
	Centre();

}

/* Menubar */
void Frame::MenuBar()
{

	/* Menubar */
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *menu_file = new wxMenu;
	wxMenu *menu_edit = new wxMenu;
	wxMenu *menu_help = new wxMenu;

	/* Append menus to menubar */ 
	menubar->Append(menu_file, wxT("&File"));
	menubar->Append(menu_edit, wxT("&Edit"));
	menubar->Append(menu_help, wxT("&Help"));

	/* Set menu bar */
	SetMenuBar(menubar);

}

/* Box sizer */
void Frame::BoxSizer()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Boxsizer */
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	/* Horizontal */
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *st1 = new wxStaticText(panel, wxID_ANY, wxT("Class Name"));
	wxTextCtrl *tc1 = new wxTextCtrl(panel, wxID_ANY);
	hbox1->Add(st1, 0, wxRIGHT, 8);
	hbox1->Add(tc1, 0, wxRIGHT, 8);
	
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *st2 = new wxStaticText(panel, wxID_ANY, wxT("Matching Classes"));
	hbox2->Add(st2, 0);

	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
	wxTextCtrl *tc2 = new wxTextCtrl(panel, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(WIDTH, 200), wxTE_MULTILINE);
	hbox3->Add(tc2, 1, wxEXPAND);

	wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);
	wxCheckBox *cb1 = new wxCheckBox(panel, wxID_ANY, wxT("Case Sensetive"));
	wxCheckBox *cb2 = new wxCheckBox(panel, wxID_ANY, wxT("Nested Classes"));
	wxCheckBox *cb3 = new wxCheckBox(panel, wxID_ANY, wxT("Non-Project Classes"));
	hbox4->Add(cb1);
	hbox4->Add(cb2, 0, wxLeft, 10);
	hbox4->Add(cb3, 0, wxLeft, 10);

	wxBoxSizer *hbox5 = new wxBoxSizer(wxHORIZONTAL);
	wxButton *btn1 = new wxButton(panel, wxID_ANY, wxT("Ok"));
	wxButton *btn2 = new wxButton(panel, wxID_ANY, wxT("Close"));
	hbox5->Add(btn1, 0);
	hbox5->Add(btn2, 0, wxLEFT | wxBOTTOM, 5);

	/* Vertical */
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(-1, 10);
	
	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
	vbox->Add(-1, 10);
	
	vbox->Add(hbox3, 0, wxLEFT | wxRIGHT, 10);
	vbox->Add(-1, 25);

	vbox->Add(hbox4, 0, wxLEFT, 10);
	vbox->Add(-1, 25);

	vbox->Add(hbox5, 0, wxALIGN_RIGHT | wxRIGHT, 10);

	/* Set sizer */
	panel->SetSizer(vbox);

}

/* Grid sizer */
void Frame::GridSizer()
{

	/* Sizer */
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	
	/* Textarea */
	wxTextCtrl *display = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_RIGHT);

	/* Grid sizer */
	wxGridSizer *gs = new wxGridSizer(4, 4, 3, 3);

	/* Add elements to grid sizer */
	gs->Add(new wxButton(this, -1, wxT("Cls")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("Bck")), 0, wxEXPAND);
	gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("Close")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("7")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("8")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("9")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("/")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("4")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("5")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("6")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("*")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("1")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("2")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("3")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("-")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("0")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT(".")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("=")), 0, wxEXPAND);
	gs->Add(new wxButton(this, -1, wxT("+")), 0, wxEXPAND);

	/* Add elements to sizer */
	sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
	sizer->Add(gs, 1, wxEXPAND);

	/* Set sizer */
	SetSizer(sizer);

	/* Set min size */
	SetMinSize(wxSize(WIDTH, HEIGHT));

}

/* Flex grid sizer */
void Frame::FlexGridSizer()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Horizontal box sizer */
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	/* Flex grid sizer */
	wxFlexGridSizer *fgs = new wxFlexGridSizer(3, 2, 9, 25);

	/* Texts */
	wxStaticText *text_title = new wxStaticText(panel,- 1, wxT("Title"));
	wxStaticText *text_author = new wxStaticText(panel,- 1, wxT("Author"));
	wxStaticText *text_review = new wxStaticText(panel,- 1, wxT("Review"));

	/* Text inputs */
	wxTextCtrl *tc1 = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1), wxSize(WIDTH, -1));
	wxTextCtrl *tc2 = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1), wxSize(WIDTH, -1));
	wxTextCtrl *tc3 = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1), wxSize(WIDTH, -1), wxTE_MULTILINE);

	/* Add elements to flex grid sizer */
	fgs->Add(text_title);
	fgs->Add(tc1, 1, wxEXPAND);

	fgs->Add(text_author);
	fgs->Add(tc2, 1, wxEXPAND);
	
	fgs->Add(text_review, 1, wxEXPAND);
	fgs->Add(tc3, 1, wxEXPAND);

	fgs->AddGrowableRow(2, 1);
	fgs->AddGrowableRow(1, 1);

	/* Add elements to horizontal sizer */
	hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);

	/* Set sizer */
	panel->SetSizer(hbox);

}