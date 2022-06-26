/* Include libraries */
#include <wx/stattext.h>
#include <wx/statline.h>

/* Include headers */
#include "frame.hpp"

/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{
	/* Check box toggle screen */
	// CheckBoxToggleScreen();

	/* Bitmap button scroll screen */
	// BitmapButtonScrollScreen();

	/* Toggle button screen */
	ToggleButtonScreen();

    /* Static line screen */
    // StaticLineScreen *sls = new StaticLineScreen(wxT("The Central Europe"));

	/* Static text screen */
	// StaticTextScreen();

	/* Frame align */
	Centre();
}


/* Static text screen */
void Frame::StaticTextScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, wxID_ANY);

	/* String */
	wxString text = wxT("'Cause sometimes you feel tired,\n\
feel weak, and when you feel weak,\n\
you feel like you wanna just give up.\n\
But you gotta search within you,\n\
you gotta find that inner strength\n\
and just pull that shit out of you\n\
and get that motivation to not give up\n\
and not be a quitter,\n\
no matter how bad you wanna just fall flat on your face and collapse.");

	/* Static text */
	wxStaticText *st = new wxStaticText(panel, wxID_ANY, text, wxPoint(10, 10), wxDefaultSize, wxALIGN_LEFT);

	/* Set size */
	this->SetSize(400, 200);

}


/* Static line screen constructor */
StaticLineScreen::StaticLineScreen(const wxString &title)
: wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH+100, HEIGHT+100))
{

	/* Font */
	wxFont font(10, wxDEFAULT, wxNORMAL, wxBOLD);

	/* Static text */
	wxStaticText *heading = new wxStaticText(this, wxID_ANY, wxT("The Central Europe"), wxPoint(30, 15));
	heading->SetFont(font);

	/* Static line */
	wxStaticLine *sl1 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 50), wxSize(300, 1));

	/* Static texts left */
	wxStaticText *st1 = new wxStaticText(this, wxID_ANY, wxT("Slovakia"), wxPoint(25, 80));
	wxStaticText *st2 = new wxStaticText(this, wxID_ANY, wxT("Hungary"), wxPoint(25, 100));
	wxStaticText *st3 = new wxStaticText(this, wxID_ANY, wxT("Poland"), wxPoint(25, 120));
	wxStaticText *st4 = new wxStaticText(this, wxID_ANY, wxT("Czech Republic"), wxPoint(25, 140));
	wxStaticText *st5 = new wxStaticText(this, wxID_ANY, wxT("Germany"), wxPoint(25, 160));
	wxStaticText *st6 = new wxStaticText(this, wxID_ANY, wxT("Slovenia"), wxPoint(25, 180));
	wxStaticText *st7 = new wxStaticText(this, wxID_ANY, wxT("Austria"), wxPoint(25, 200));
	wxStaticText *st8 = new wxStaticText(this, wxID_ANY, wxT("Switzerland"), wxPoint(25, 220));

	/* Static texts right */
	wxStaticText *st9 = new wxStaticText(this, wxID_ANY, wxT("5 379 000"), wxPoint(220, 80), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st10 = new wxStaticText(this, wxID_ANY, wxT("10 084 000"), wxPoint(220, 100), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st11 = new wxStaticText(this, wxID_ANY, wxT("38 635 000"), wxPoint(220, 120), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st12 = new wxStaticText(this, wxID_ANY, wxT("10 240 000"), wxPoint(220, 140), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st13 = new wxStaticText(this, wxID_ANY, wxT("82 443 000"), wxPoint(220, 160), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st14 = new wxStaticText(this, wxID_ANY, wxT("2 001 000"), wxPoint(220, 180), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st15 = new wxStaticText(this, wxID_ANY, wxT("8 032 000"), wxPoint(220, 200), wxSize(90, -1), wxALIGN_RIGHT);
	wxStaticText *st16 = new wxStaticText(this, wxID_ANY, wxT("7 288 000"), wxPoint(220, 220), wxSize(90, -1), wxALIGN_RIGHT);

	/* Static line */
	wxStaticLine *sl2 = new wxStaticLine(this, wxID_ANY, wxPoint(25, 260), wxSize(300, 1));

	/* Summary */
	wxStaticText *sum = new wxStaticText(this, wxID_ANY, wxT("164 102 200"), wxPoint(220, 280), wxSize(90, -1), wxALIGN_RIGHT);

	/* Summary font */
	wxFont sum_font = sum->GetFont();
	sum_font.SetWeight(wxBOLD);

	/* Set font */
	sum->SetFont(sum_font);

	/* Dialog align */
	this->Centre();

	/* Modal */
	ShowModal();
	Destroy();

}


/* Toggle button screen */
void Frame::ToggleButtonScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, wxID_ANY);

	/* Colour */
	colour = new wxColour(0, 0, 0);

	/* Tuggle buttons */
	tg_btn1 = new wxToggleButton(panel, ID_TGBUTTON1, wxT("Red"), wxPoint(20, 20));
	tg_btn2 = new wxToggleButton(panel, ID_TGBUTTON2, wxT("Green"), wxPoint(20, 70));
	tg_btn3 = new wxToggleButton(panel, ID_TGBUTTON3, wxT("Blue"), wxPoint(20, 120));

	/* Connects */
	Connect(ID_TGBUTTON1, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnToggleRed));
	Connect(ID_TGBUTTON2, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnToggleGreen));
	Connect(ID_TGBUTTON3, wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(Frame::OnToggleBlue));

	/* Toggle panel */
	tg_panel = new wxPanel(panel, wxID_NEW, wxPoint(120, 20), wxSize(90, 90), wxSUNKEN_BORDER);
	tg_panel->SetBackgroundColour(colour->GetAsString());

}

/* Toggle to red */
void Frame::OnToggleRed(wxCommandEvent &event)
{

	/* Colours */
	unsigned char green = colour->Green();
	unsigned char blue = colour->Blue();

	/* Change colour */
	colour->Set( (colour->Red()) ? 0 : 255 , green, blue);
	std::cout << colour->GetAsString() << std::endl;

	/* Set background color */
	tg_panel->SetBackgroundColour(colour->GetAsString());
	tg_panel->Refresh();

}

/* Toggle to green */
void Frame::OnToggleGreen(wxCommandEvent &event)
{

	/* Colours */
	unsigned char red = colour->Red();
	unsigned char blue = colour->Blue();

	/* Change colour */
	colour->Set(red, (colour->Green()) ? 0 : 255 , blue);
	std::cout << colour->GetAsString() << std::endl;

	/* Set background color */
	tg_panel->SetBackgroundColour(colour->GetAsString());
	tg_panel->Refresh();

}

/* Toggle to Blue */
void Frame::OnToggleBlue(wxCommandEvent &event)
{

	/* Colours */
	unsigned char red = colour->Red();
	unsigned char green = colour->Green();

	/* Change colour */
	colour->Set(red, green, (colour->Blue()) ? 0 : 255 );
	std::cout << colour->GetAsString() << std::endl;

	/* Set background color */
	tg_panel->SetBackgroundColour(colour->GetAsString());
	tg_panel->Refresh();

}


/* Bitmap button scroll screen */
void Frame::BitmapButtonScrollScreen()
{

	/* Image */
	wxImage::AddHandler( new wxPNGHandler );

	/* Panel */
	wxPanel *panel = new wxPanel(this);

	/* Slider */
	slider = new wxSlider(panel, ID_SLIDER, 0, 0, 100, wxPoint(10, 30), wxSize(140, -1));

	/* Bitmap button */
	bb = new wxBitmapButton(panel, wxID_ANY, wxBitmap(wxT("assets/add-icon.png"), wxBITMAP_TYPE_PNG), wxPoint(180, 20));

	/* Connect */
	Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(Frame::OnBitmapButtonScroll));

}

/* Bitmap button scroll */
void Frame::OnBitmapButtonScroll(wxScrollEvent &event)
{

	/* Get slider position */
	pos = slider->GetValue();

	if(pos == 0)
		bb->SetBitmapLabel(wxBitmap(wxT("assets/delete-icon.png"), wxBITMAP_TYPE_PNG));

	else if(pos > 0 && pos <= 30)
		bb->SetBitmapLabel(wxBitmap(wxT("assets/doc-icon.png"), wxBITMAP_TYPE_PNG));

	else if(pos > 30 && pos < 80)
		bb->SetBitmapLabel(wxBitmap(wxT("assets/document-icon.png"), wxBITMAP_TYPE_PNG));

	else bb->SetBitmapLabel(wxBitmap(wxT("assets/save-icon.png"), wxBITMAP_TYPE_PNG));

}


/* Check box toggle screen */
void Frame::CheckBoxToggleScreen()
{

	/* Panel */
	wxPanel *panel = new wxPanel(this, wxID_ANY);

	/* Checkbox */
	m_cb = new wxCheckBox(panel, ID_CHECKBOX, wxT("Show title"), wxPoint(20, 20));
	m_cb->SetValue(true);

	/* Connect */
	Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(Frame::OnCheckBoxToggle));

}

/* Check box toggle */
void Frame::OnCheckBoxToggle(wxCommandEvent &event)
{

	/* Set title value */
	this->SetTitle( (m_cb->GetValue()) ? "Frame" : "" );

}