/* Include headers */
#include "frame.hpp"

/* Constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, -1);

	/* Grid sizer */
	wxGridSizer *grid = new wxGridSizer(3, 2, -1, -1);

	/* Add elements to grid sizer */
	grid->Add(new wxButton(panel, wxID_CANCEL), 0, wxTOP | wxLEFT, 9);
	grid->Add(new wxButton(panel, wxID_DELETE), 0, wxTOP, 9);
	grid->Add(new wxButton(panel, wxID_SAVE), 0, wxLEFT, 9);
	grid->Add(new wxButton(panel, wxID_EXIT));
	grid->Add(new wxButton(panel, wxID_STOP), 0,wxLEFT, 9);
	grid->Add(new wxButton(panel, wxID_NEW));

	/* Set sizer */
	panel->SetSizer(grid);

	/* Connect */
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnQuit));

	/* Frame align */
	Centre();

}

/* Quit */
void Frame::OnQuit(wxCommandEvent &WXUNUSED(event))
{

	/* Close frame */
	Close(true);

}