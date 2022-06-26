/* Include libraries */
#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/slider.h>

/* Cosntants */
#define WIDTH 250
#define HEIGHT 250

/* Enum */
enum {
	ID_CHECKBOX = 1,
	ID_SLIDER,
	ID_TGBUTTON1,
	ID_TGBUTTON2,
	ID_TGBUTTON3,
};

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);


	/* Static text screen */
	void StaticTextScreen();


	/* Toggle button screen */
	void ToggleButtonScreen();

	/* Toggled */
	void OnToggleRed(wxCommandEvent &event);
	void OnToggleGreen(wxCommandEvent &event);
	void OnToggleBlue(wxCommandEvent &event);


	/* Bitmap button scroll screen */
	void BitmapButtonScrollScreen();

	/* Slider */
	wxSlider *slider;

	/* Bitmap button */
	wxBitmapButton *bb; 

	/* Position */
	int pos;

	/* Bitmap button scroll */
	void OnBitmapButtonScroll(wxScrollEvent &event);


	/* Checkbox toggle screen */
	void CheckBoxToggleScreen();

	/* Checkbox */
	wxCheckBox *m_cb;

	/* Checkbox toggle */
	void OnCheckBoxToggle(wxCommandEvent &event);

/* Protected */
protected:

	/* Toggle buttons */
	wxToggleButton *tg_btn1;
	wxToggleButton *tg_btn2;
	wxToggleButton *tg_btn3;

	/* Panel and colour */
	wxPanel *tg_panel;
	wxColour *colour;

};


/* Static line screen class extends wxDialog */
class StaticLineScreen : wxDialog
{

/* Public */
public:

	/* Constructor */
	StaticLineScreen(const wxString &title);

};