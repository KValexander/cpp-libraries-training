// Include libraries
#include <wx/wx.h>
#include <wx/panel.h>

// Panel class extends wxPanel
class Panel : public wxPanel {

public:
	// Constructor
	Panel(wxPanel *parent);

	// Plus and minus count
	void OnPlus(wxCommandEvent &event);
	void OnMinus(wxCommandEvent &event);

	// Buttons
	wxButton *m_plus;
	wxButton *m_minus;
	wxPanel  *m_parent;

	// Count
	int count;
};

// Other panel
class OtherPanel : public wxPanel {
public:
	// Constructor
	OtherPanel(wxPanel *parent);

	// Display text
	void OnSetText(wxCommandEvent &event);

	// Text
	wxStaticText *m_text;
};

// ID
const int ID_PLUS = 101;
const int ID_MINUS = 102;