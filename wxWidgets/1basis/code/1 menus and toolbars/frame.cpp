// Include headers
#include <frame.hpp>

// Constructor
// Frame initialization
Frame::Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(480, 480))
{
    // // Base
    // // ====================
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
    // // ====================


    // Menubar
    // ====================
    // Menubar and Menu
    menubar     = new wxMenuBar;
    file_menu   = new wxMenu;
    imp_menu    = new wxMenu;

    // Append elements to file menu
    file_menu->Append(wxID_ANY, wxT("&New"));
    file_menu->Append(wxID_ANY, wxT("&Open"));
    file_menu->Append(wxID_ANY, wxT("&Save"));
    file_menu->AppendSeparator();

    // Append elements to imp menu
    imp_menu->Append(wxID_ANY, wxT("Import list"));
    imp_menu->Append(wxID_ANY, wxT("Import bookmarks"));
    imp_menu->Append(wxID_ANY, wxT("Import mail"));

    // Append sub menu for file menu
    file_menu->AppendSubMenu(imp_menu, wxT("&Import"));

    // Create and append menu item
    quit = new wxMenuItem(file_menu, wxID_EXIT, wxT("&Quit\tCtrl+W"));
    file_menu->Append(quit);

    // Append file menu to menubar
    menubar->Append(file_menu, wxT("&File"));

    // Set menu bar
    SetMenuBar(menubar);

    // Assigning an event to a menubar elements
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnQuit));
    // ====================


    // Toolbar
    // ====================
    // Handler PNG image
    wxImage::AddHandler(new wxPNGHandler);
    wxBitmap add(wxT("assets/add-icon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap save(wxT("assets/save-icon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap load(wxT("assets/down-icon.png"), wxBITMAP_TYPE_PNG);
    wxBitmap exit(wxT("assets/delete-icon.png"), wxBITMAP_TYPE_PNG);

    // Box sizer
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // Toolbars
    toolbar1 = new wxToolBar(this, wxID_ANY);
    toolbar2 = new wxToolBar(this, wxID_ANY);
    
    // Add tool to toolbars
    toolbar1->AddTool(wxID_ANY, wxT("Add"), add);
    toolbar1->AddTool(wxID_ANY, wxT("Save"), save);
    toolbar1->AddTool(wxID_ANY, wxT("Load"), load);
    toolbar1->Realize();
    
    toolbar2->AddTool(wxID_EXIT, wxT("Exit"), exit);
    toolbar2->Realize();

    // Add toolbars to box sizer
    vbox->Add(toolbar1, 0, wxEXPAND);
    vbox->Add(toolbar2, 0, wxEXPAND);

    // Set sizer
    SetSizer(vbox);

    // Connect
    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Frame::OnQuit));
    // ====================


    // // Panels
    // // ====================
    // // Parent panel
    // m_parent = new wxPanel(this, wxID_ANY);

    // // Box sizer
    // wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    // // Panels
    // m_p = new Panel(m_parent);
    // m_op = new OtherPanel(m_parent);

    // // Add panel to box sizer
    // hbox->Add(m_p, 1, wxEXPAND | wxALL, 5);
    // hbox->Add(m_op, 1, wxEXPAND | wxALL, 5);

    // // Set sizer for parent panel
    // m_parent->SetSizer(hbox);
    // // ====================

    // Frame align, wxWidget function
    this->Centre();
}

// Frame quit
void Frame::OnQuit(wxCommandEvent &event)
{
    // Close frame;
    Close(true);
}