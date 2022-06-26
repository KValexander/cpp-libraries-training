/* Include libraries */
#include <wx/textdlg.h>

/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Listbox screen */
	// ListBoxScreen();

	/* Notebook screen */
	NotebookScreen();

	/* Scroll window screen */
	// ScrollWindowScreen();

	/* Frame align */
	Centre(); // or Center
}


/* Scroll window screen */
void Frame::ScrollWindowScreen()
{

	/* Image */
	wxImage::AddHandler(new wxJPEGHandler);

	/* Scrolled window */
	wxScrolledWindow *sw = new wxScrolledWindow(this);

	/* Bitmap */
	wxBitmap bmp(wxT("assets/image.jpg"), wxBITMAP_TYPE_JPEG);
	wxStaticBitmap *sb = new wxStaticBitmap(sw, -1, bmp);

	/* Size */
	int width = bmp.GetWidth();
	int height = bmp.GetHeight();

	/* Set scroll */
	sw->SetScrollbars(10, 10, width/10, height/10);
	sw->Scroll(50, 50);

}


/* Notebook screen */
void Frame::NotebookScreen()
{

	/* Notebook */
	wxNotebook *nb = new wxNotebook(this, -1, wxPoint(-1, -1), wxSize(-1, -1), wxNB_BOTTOM);

	/* Menu bar */
	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *menu_file = new wxMenu;
	menu_file->Append(wxID_EXIT, wxT("Quit"), wxT(""));
	menubar->Append(menu_file, wxT("&File"));

	/* Set menu bar */
	SetMenuBar(menubar);

	/* Connect */
	Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnQuit));

	/* Grid */
	Notebook *grid1 = new Notebook(nb);
	Notebook *grid2 = new Notebook(nb);
	Notebook *grid3 = new Notebook(nb);

	/* Add grid to notebook */
	nb->AddPage(grid1, wxT("Sheet1"));
	nb->AddPage(grid2, wxT("Sheet2"));
	nb->AddPage(grid3, wxT("Sheet3"));

	/* Create status bar */
	CreateStatusBar();

}

/* Quit */
void Frame::OnQuit(wxCommandEvent &event)
{
	Close(true);
}

/* Notebook constructor */
Notebook::Notebook(wxNotebook *parent)
: wxGrid(parent, wxID_ANY)
{

	/* Create grid */
	CreateGrid(30, 30);

	/* Config greed */
	SetRowLabelSize(50);
	SetColLabelSize(25);
	SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	/* Set size */
	for(int i = 0; i < 30; i++)
		this->SetRowSize(i, 25);

}


/* Listbox screen */
void Frame::ListBoxScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Box sizer */
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	/* Listbox */
	listbox = new wxListBox(panel, ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
	lb = new Listbox(panel);

	/* Add elements to box sizer */
	hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
	hbox->Add(lb, 2, wxEXPAND | wxRIGHT, 10);

	/* Set sizer */
	panel->SetSizer(hbox);

	/* Connect */
	Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler(Frame::OnDblClick));

}


/* Double click event */
void Frame::OnDblClick(wxCommandEvent &event)
{

	/* String */
	wxString text;
	wxString renamed;

	/* Rename */
	int sel = listbox->GetSelection();
	if(sel != -1) {
		text = listbox->GetString(sel);
		renamed = wxGetTextFromUser(wxT("Rename item"), wxT("Rename dialog"), text);
	}

	/* Check rename */
	if(!renamed.IsEmpty()) {
		listbox->Delete(sel);
		listbox->Insert(renamed, sel);
	}

}


/* Listbox constructor */
Listbox::Listbox(wxPanel *parent)
: wxPanel(parent, wxID_ANY)
{

	/* Box sizer */
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	/* Get listbox from parent */
	Frame *frame = (Frame *) parent->GetParent();
	lb = frame->listbox;

	/* Buttons */
	btn_new = new wxButton(this, wxID_NEW, wxT("New"));
	btn_rename = new wxButton(this, ID_RENAME, wxT("Rename"));
	btn_delete = new wxButton(this, wxID_DELETE, wxT("Delete"));
	btn_clear = new wxButton(this, wxID_CLEAR, wxT("Clear"));

	/* Connects */
	Connect(wxID_NEW, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Listbox::OnNew));
	Connect(ID_RENAME, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Listbox::OnRename));
	Connect(wxID_DELETE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Listbox::OnDelete));
	Connect(wxID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Listbox::OnClear));

	/* Add elements to sizer */
	vbox->Add(-1, 20);
	vbox->Add(btn_new);
	vbox->Add(btn_rename, 0, wxTOP, 5);
	vbox->Add(btn_delete, 0, wxTOP, 5);
	vbox->Add(btn_clear, 0, wxTOP, 5);

	/* Set sizer */
	SetSizer(vbox);

}

/* New */
void Listbox::OnNew(wxCommandEvent &event)
{
	wxString str = wxGetTextFromUser(wxT("Add new item"));
	if(str.Len() > 0) lb->Append(str);
}

/* Clear */
void Listbox::OnClear(wxCommandEvent &event)
{
	lb->Clear();
}

/* Rename */
void Listbox::OnRename(wxCommandEvent &event)
{

	/* String */
	wxString text;
	wxString renamed;

	/* Rename */
	int sel = lb->GetSelection();
	if(sel != -1) {
		text = lb->GetString(sel);
		renamed = wxGetTextFromUser(wxT("Rename item"), wxT("Rename dialog"), text);
	}

	/* Check rename */
	if(!renamed.IsEmpty()) {
		lb->Delete(sel);
		lb->Insert(renamed, sel);
	}

}

/* Delete */
void Listbox::OnDelete(wxCommandEvent &event)
{
	int sel = lb->GetSelection();
	if(sel != -1) lb->Delete(sel);
}