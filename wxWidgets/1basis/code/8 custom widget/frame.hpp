#pragma once

/* Include libraries */
#include <wx/wx.h>

/* Cosntants */
#define WIDTH 450
#define HEIGHT 450

/* IDs */
enum {
	ID_SLIDER = 0
};

/* Widget class extends wxPanel */
class Widget : public wxPanel
{

/* Public */
public:

	/* Constructor */
	Widget(wxPanel *parent, int id);

	/* Panel */
	wxPanel *panel;

	/* Methods */
	void OnSize(wxSizeEvent &event);
	void OnPaint(wxPaintEvent &event);

};

/* Frame class extends wxFrame */
class Frame : public wxFrame
{

/* Public */
public:

	/* Constructor */
	Frame(const wxString &title);

	/* Methods */
	void OnScroll(wxScrollEvent &event);
	int GetCurWidth();

	/* Slider */
	wxSlider *slider;

	/* Widget */
	Widget *widget;

	/* Current width */
	int cur_width;

};