/* Include libraries */
#include <wx/fontdlg.h>

/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Message screen */
	// MessageScreen();

	/* Select file screen */
	SelectFileScreen();

	/* Font dialog screen */
	// FontDialogScreen();

	/* Frame align */
	Centre();

}

/* Custom dialog screen constructor */
CustomDialogScreen::CustomDialogScreen(const wxString &title)
: wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Box sizers */
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	/* Static box */
	wxStaticBox *sb = new wxStaticBox(panel, -1, wxT("Colors"), wxPoint(5, 5), wxSize(WIDTH - 10, HEIGHT - 80)); 

	/* Radio buttons */
	wxRadioButton *rb = new wxRadioButton(panel, -1, wxT("256 Colors"), wxPoint(15, 30), wxDefaultSize, wxRB_GROUP);
	
	wxRadioButton *rb1 = new wxRadioButton(panel, -1, wxT("16 Colors"), wxPoint(15, 55));
	wxRadioButton *rb2 = new wxRadioButton(panel, -1, wxT("2 Colors"), wxPoint(15, 80));
	wxRadioButton *rb3 = new wxRadioButton(panel, -1, wxT("Custom"), wxPoint(15, 105));

	/* Input text */
	wxTextCtrl *tc = new wxTextCtrl(panel, -1, wxT(""), wxPoint(95, 105));

	/* Buttons */
	wxButton *btn_ok = new wxButton(this, -1, wxT("Ok"), wxDefaultPosition, wxSize(70, 30));
	wxButton *btn_close = new wxButton(this, -1, wxT("Close"), wxDefaultPosition, wxSize(70, 30));

	/* Add elements to box sizers */
	hbox->Add(btn_ok, 1);
	hbox->Add(btn_close, 1, wxLEFT, 5);

	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	/* Set sizer */
	SetSizer(vbox);

	/* Frame align */
	Centre();

	/* Modal */
	ShowModal(); // show modal
	Destroy(); // destroy modal

}

/* Font dialog screen */
void Frame::FontDialogScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Menu bar */
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *menu_file = new wxMenu;
	menu_file->Append(ID_FONTDIALOG, wxT("&Change font"));
	menubar->Append(menu_file, wxT("&File"));

	/* Set menu bar */
	SetMenuBar(menubar);

	/* Connect */
	Connect(ID_FONTDIALOG, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnFontOpen));

	/* Static text */
	st = new wxStaticText(panel, wxID_ANY, wxT("The Agoge"), wxPoint(20, 20));

}

/* Open font */
void Frame::OnFontOpen(wxCommandEvent &event)
{

	/* Font dialog */
	wxFontDialog *fontDialog = new wxFontDialog(this);

	/* Check modal */
	if(fontDialog->ShowModal() == wxID_OK)
		st->SetFont(fontDialog->GetFontData().GetChosenFont());

}

/* Select file screen */
void Frame::SelectFileScreen()
{

	/* Menu bar */
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *menu_file = new wxMenu;
	menu_file->Append(wxID_OPEN, wxT("&Open"));
	menubar->Append(menu_file, wxT("&File"));

	/* Set menu bar */
	SetMenuBar(menubar);

	/* Connect */
	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnFileOpen));

	/* Input text */
	tc = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1), wxSize(-1,-1), wxTE_MULTILINE);

}

/* Open file */
void Frame::OnFileOpen(wxCommandEvent &event)
{

	/* File dialog */
	wxFileDialog *openFD = new wxFileDialog(this);

	/* Check modal */
	if(openFD->ShowModal() == wxID_OK) {
		wxString fileName = openFD->GetPath();
		tc->LoadFile(fileName);
	}

}

/* Message screen */
void Frame::MessageScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Box sizer */
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	/* Grid sizer */
	wxGridSizer *grid = new wxGridSizer(2, 2, 2, 2);

	/* Add elements to grid sizer */
	/* standard ID:
		wxID_CANCEL,
		wxID_DELETE,
		wxID_SAVE,
		wxID_EXIT,
		wxID_STOP,
		wxID_NEW
	*/
	grid->Add(new wxButton(panel, ID_INFO, wxT("Info")), 1, wxEXPAND);
	grid->Add(new wxButton(panel, ID_ERROR, wxT("Error")), 1, wxEXPAND);
	grid->Add(new wxButton(panel, ID_QUESTION, wxT("Question")), 1, wxEXPAND);
	grid->Add(new wxButton(panel, ID_ALERT, wxT("Alert")), 1, wxEXPAND);

	/* Horizontal box */
	hbox->Add(grid, 0, wxALL, 15);

	/* Set sizer */
	panel->SetSizer(grid);

	/* Connects */
    Connect(ID_INFO, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::InfoMessage));
    Connect(ID_ERROR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::ErrorMessage));
    Connect(ID_QUESTION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::QuestionMessage));
    Connect(ID_ALERT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::AlertMessage));

}

/* Info message */
void Frame::InfoMessage(wxCommandEvent &event)
{
	/* Info message box */
	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Download completed"), wxT("Info"), wxOK);
	dial->ShowModal();
}

/* Error message */
void Frame::ErrorMessage(wxCommandEvent &event)
{
	/* Error message box */
	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Error loading file"), wxT("Error"), wxOK | wxICON_ERROR);
	dial->ShowModal();
}

/* Question message */
void Frame::QuestionMessage(wxCommandEvent &event)
{
	/* Question message box */
	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Are you sure to quit?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	dial->ShowModal();
}

/* Alert message */
void Frame::AlertMessage(wxCommandEvent &event)
{
	/* Alert message box */
	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Unallowed operation"), wxT("Exclamation"), wxOK | wxICON_EXCLAMATION);
	dial->ShowModal();
}