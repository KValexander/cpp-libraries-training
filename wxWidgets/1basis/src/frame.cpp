// Include headers
#include <frame.hpp>

// Constructor
// Frame initialization
Frame::Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 250))
{
    // // Frame panel, wxWidget class
    // // wxID_ANY - frame ID
    // wxPanel *panel = new wxPanel(this, wxID_ANY);

    // // Panel button
    // // wxID_EXIT - ID
    // // wxT("quite") - title
    // // wxPoint(20, 20) - start position
    // wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));

    // // Assigning an event to a button
    // // wxID_EXIT - button ID
    // // exEVT_COMMAND_BUTTON_CLICKED - event type
    // // wxCommandEventHandler(Frame::OnQuit) - button event handling function
    // Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnQuit));

    // // Focus on button
    // button->SetFocus();

    // Parent panel
    m_parent = new wxPanel(this, wxID_ANY);

    // Box sizer
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    // Panels
    m_p = new Panel(m_parent);
    m_op = new OtherPanel(m_parent);

    // Add panel on box sizer
    hbox->Add(m_p, 1, wxEXPAND | wxALL, 5);
    hbox->Add(m_op, 1, wxEXPAND | wxALL, 5);

    // Set sizer for parent panel
    m_parent->SetSizer(hbox);

    // Frame align, wxWidget function
    this->Centre();
}