/* Include libraries */
#include <wx/wx.h>

/* Cosntants */
#define WIDTH 250
#define HEIGHT 250

/* Enum */
enum {
	ID_FONTDIALOG = 1,
	ID_INFO,
	ID_ERROR,
	ID_QUESTION,
	ID_ALERT
};

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Font dialog screen */
	void FontDialogScreen();

	/* Static text */
	wxStaticText *st;

	/* Open font */
	void OnFontOpen(wxCommandEvent &event);


	/* Select file screen */
	void SelectFileScreen();

	/* Input text */
	wxTextCtrl *tc;

	/* Open file */
	void OnFileOpen(wxCommandEvent &event);


	/* Message screen */
	void MessageScreen();

	/* Messages */
	void InfoMessage(wxCommandEvent &event);
	void ErrorMessage(wxCommandEvent &event);
	void QuestionMessage(wxCommandEvent &event);
	void AlertMessage(wxCommandEvent &event);

};


/* Custom dialog screen extends wxDialog */
class CustomDialogScreen : public wxDialog
{

/* Public */
public:

	/* Constructor */
	CustomDialogScreen(const wxString &title);

};