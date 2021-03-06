/* Include headers */
#include "frame.hpp"

/* Array */
int num[] = {75, 150, 225, 300, 375, 450, 525, 600, 675};
int numsize = sizeof(num) / sizeof(num[0]);

/* Widget constructor */
Widget::Widget(wxPanel *parent, int id)
:wxPanel(parent, id, wxDefaultPosition, wxSize(-1, 30), wxSUNKEN_BORDER)
{

	/* Parent */
	panel = parent;

	/* Connect */
	Connect(wxEVT_PAINT, wxPaintEventHandler(Widget::OnPaint));
	Connect(wxEVT_SIZE, wxSizeEventHandler(Widget::OnSize));

}

/* Widget OnPaint */
void Widget::OnPaint(wxPaintEvent &event)
{

	/* Font */
	wxFont font(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier 10 Pitch"));

	/* Paint DC */
	wxPaintDC dc(this);
	dc.SetFont(font);
	wxSize size = GetSize();
	int width = size.GetWidth();

	/* Frame */
	Frame *frame = (Frame *) panel->GetParent();
	int cur_width = frame->GetCurWidth();
	int step = (int) round(width / 10.0);

	/* Something */
	int till = (int) ((width / 750.0) * cur_width);
	int full = (int) ((width / 750.0) * 700);

	/* Check */
	if(cur_width >= 700) {

		/* Draw rectangles */
		dc.SetPen(wxPen(wxColour(255, 255, 184)));
		dc.SetBrush(wxBrush(wxColour(255, 255, 184)));
		dc.DrawRectangle(0, 0, full, 30);
		dc.SetPen(wxPen(wxColour(255, 175, 175)));
		dc.SetBrush(wxBrush(wxColour(255, 175, 175)));
		dc.DrawRectangle(full, 0, till - full, 30);

	} else {

		/* Draw rectangle */
		dc.SetPen(wxPen(wxColour(255, 255, 184)));
		dc.SetBrush(wxBrush(wxColour(255, 255, 184)));
		dc.DrawRectangle(0, 0, till, 30);

	}

	/* Something draw */
	dc.SetPen(wxPen(wxColour(90, 80, 60)));
	for(int i = 0; i <= numsize; i++) {
		dc.DrawLine(i*step, 0, i*step, 6);
		wxSize size = dc.GetTextExtent(wxString::Format(wxT("%d"), num[i-1]));
		dc.DrawText(wxString::Format(wxT("%d"), num[i-1]), i*step-size.GetWidth()/2, 8);
	}

}

/* Widget OnSize */
void Widget::OnSize(wxSizeEvent &event)
{
	Refresh();
}


/* Frame constructor */
Frame::Frame(const wxString &title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(WIDTH, HEIGHT))
{

	/* Current width */
	cur_width = 75;

	/* Panel */
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	wxPanel *centerPanel = new wxPanel(panel, wxID_ANY);

	/* Slider */
	slider = new wxSlider(centerPanel, ID_SLIDER, 75, 0, 750, wxPoint(-1, -1), wxSize(150, -1), wxSL_LABELS);

	/* Box sizers */
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);

	/* Widget */
	widget = new Widget(panel, wxID_ANY);
	hbox->Add(widget, 1, wxEXPAND);

	hbox2->Add(centerPanel, 1, wxEXPAND);
	hbox3->Add(slider, 0, wxTOP | wxLEFT, 35);

	/* Set sizer */
	centerPanel->SetSizer(hbox3);

	vbox->Add(hbox2, 1, wxEXPAND);
	vbox->Add(hbox, 0, wxEXPAND);

	/* Set sizer and Set focus */
	panel->SetSizer(vbox);
	slider->SetFocus();

	/* Connect */
	Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(Frame::OnScroll));

	/* Frame align */
	Center(); // or Centre()

}

/* Frame OnScroll */
void Frame::OnScroll(wxScrollEvent &event)
{
	cur_width = slider->GetValue();
	widget->Refresh();
}

/* Frame GetCurWidth */
int Frame::GetCurWidth()
{
	return cur_width;
}