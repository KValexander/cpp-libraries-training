// Include libraries
#include <wx/wx.h>

// Include headers
#include "panel.hpp"

// Frame class extends wxFrame
class Frame : public wxFrame {

public: 
    // Constructor
    Frame(const wxString& title);

    // Frame quit
    void OnQuit(wxCommandEvent &event);

    // Panels
    wxPanel     *m_parent;
    Panel       *m_p;
    OtherPanel  *m_op;

};