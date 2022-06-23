// Include libraries
#include <wx/stattext.h>

// Include headers
#include "frame.hpp"

// Constructor
Panel::Panel(wxPanel *parent)
: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	// Count
	this->count = 0;

	// Parent panel
	this->m_parent = parent;

	// Buttons
	this->m_plus = new wxButton(this, ID_PLUS, wxT("+"), wxPoint(0, 10));
	this->m_minus = new wxButton(this, ID_MINUS, wxT("-"), wxPoint(0, 100));

	// Assigning an event to a buttons
	Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Panel::OnPlus));
	Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Panel::OnMinus));
}

// Plus count
void Panel::OnPlus(wxCommandEvent &WXUNUSED(event)) {
	// Counter increase
	count++;

	// Get pointer parent frame
	Frame *frame = (Frame *) m_parent->GetParent();
	// Update counter display 
	frame->m_op->m_text->SetLabel(wxString::Format(wxT("%d"), count));
}

// Minus count
void Panel::OnMinus(wxCommandEvent &WXUNUSED(event)) {
	// Counter decrement
	count--;

	// Get pointer parent frame
	Frame *frame = (Frame *) m_parent->GetParent();
	// Update counter display 
	frame->m_op->m_text->SetLabel(wxString::Format(wxT("%d"), count));
}

// OtherPanel constructor
OtherPanel::OtherPanel(wxPanel *parent)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270,150), wxBORDER_SUNKEN)
{	
	// Create text class
	m_text = new wxStaticText(this, -1, wxT("0"), wxPoint(40, 60));
}